#include <iostream>
#include <fstream>
#include <tuple>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "memory"
#include "PathFinding/Playground.h"
#include "PathFinding/Position.h"
#include "PathFinding/A_Star/A_StarPath.h"
#include "PathFinding/NoPathException.h"
#include "VREP/VRepApi.h"
#include "VREP/Objects/Sensors/VisionSensor.h"
#include "VREP/Objects/Robots/DR12_Robot.h"
#include "Bridge.h"
#include "VREP/Exceptions/ReturnCodesExceptions.h"
#include "Utilities/Utilities.h"

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
        std::cout << "DR12 pos: " << robotPos.X() << " " << robotPos.Y() << std::endl;
        std::cout << "Wheel diameter: " << robot->wheelDiameter() << std::endl;
        std::cout << "Distance between wheels: " << robot->wheelDistance() << std::endl;
        cv::Mat img = visionSensor->image(VisionSensor::ImageType::GRAYSCALE);
        Bridge::coverObject(img, robotPos, 15);
        auto playGround = std::shared_ptr<Playground>(new Playground(Bridge::createGroundMap(img)));
        A_StarPath path(playGround);
        path.setStartPoint(robotPos);
        path.setEndPoint(Position(440, 440));
        CoordinateList_sptr pathCoordList = path.path();
        //std::ofstream outFile;
        //outFile.open("output.txt");
        //playGround->writeToFile(outFile);
        Bridge::drawPath(img, pathCoordList);
//        cv::imshow("opencvtest", img);
//        cv::waitKey(0);
        robot->followPath(Bridge::convertToVREPPath(pathCoordList, resolution));
//        auto ori = robot->orientation();
//        std::cout << "Orientation: " << std::get<0>(ori) << " " << std::get<1>(ori) << " " << std::get<2>(ori) << std::endl;
//        std::cout << "Orientation rad: " << Utilities::orientationXY(ori) << std::endl;
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
