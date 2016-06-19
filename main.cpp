#include <iostream>
#include <fstream>
#include <tuple>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "memory"
#include "PathFinding/Playground.h"
#include "PathFinding/A_Star/A_StarPath.h"
#include "PathFinding/NoPathException.h"
#include "VREP/VRepApi.h"
#include "Bridge.h"
#include "VREP/Exceptions/ReturnCodesExceptions.h"

#define DEBUG false

int main(int argc, char **argv) {
    VRepApi vRepApi;

    std::cout << "Waiting for connection!" << std::endl;

    try {
        vRepApi.connect("127.0.0.1", 19999, true, true, 2000);
        std::cout << "Connected!" << std::endl;

        VisionSensor *visionSensor = vRepApi.getVisionSensor("mapSensor");
        DR12_Robot *robot = vRepApi.getDR12Unit("dr12");

        VisionSensor::Resolution resolution = visionSensor->resolution();
        Position robotPos = Bridge::convertToPosition(robot->globalPosition(), resolution);

        //original image from vision sensor
        cv::Mat img = visionSensor->image(VisionSensor::ImageType::GRAYSCALE);

        //cover our robot from the image and create a matrix for A_Star algorithm
        cv::Mat reworked {img.clone()};
        Bridge::coverObject(reworked, robotPos, 15);
        Bridge::enlargeBorder(reworked, 60);

        auto playGround = std::shared_ptr<Playground>(new Playground(Bridge::createGroundMap(reworked)));
        A_StarPath path(playGround);

        //the start point is the robot's current position
        path.setStartPoint(robotPos);

        //set the endpoint
        path.setEndPoint(Position(440, 440));

        //calculate path
        CoordinateList_sptr pathCoordList = path.path();

        //draw path on the image
        cv::Mat finalWithPath {img.clone()};
        Bridge::drawPath(finalWithPath, pathCoordList);

        //follow the path with a controller algorithm
        robot->followPath(Bridge::convertToVREPPath(pathCoordList, resolution));
//        robot->followPathDummy(Bridge::convertToVREPPath(pathCoordList, resolution));

        if (DEBUG) {
            cv::imshow("original", img);
            cv::waitKey(0);
            cv::imshow("dilated", reworked);
            cv::waitKey(0);
            cv::imshow("with path", finalWithPath);
            cv::waitKey(0);
        }

        delete visionSensor;
        delete robot;
        vRepApi.disconnect();
    }
    catch (ConnectionErrorException *ex) {
        std::cout << ex->what() << std::endl;
        delete ex;
    }
    catch (NoPathException *ex) {
        std::cout << ex->what() << std::endl;
        delete ex;
    }
    catch (ReturnCodesExceptions *ex) {
        std::cout << ex->what() << std::endl;
        delete ex;
    }
    return 0;
}
