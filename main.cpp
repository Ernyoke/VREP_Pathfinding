#include <iostream>
#include <fstream>
#include <tuple>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "memory"
#include "Playground.h"
#include "Position.h"
#include "A_StarPath.h"
#include "NoPathException.h"
#include "VRepApi.h"
#include "VisionSensor.h"
#include "DR12_Robot.h"
#include "Bridge.h"

int main(int argc, char** argv)
{
    VRepApi vRepApi;

    std::cout << "Waiting for connection!" << std::endl;

    try {
        vRepApi.connect("127.0.0.1", 19999, true, true, 2000);
        std::cout << "Connected!" << std::endl;
        VisionSensor* visionSensor = vRepApi.getVisionSensor("mapSensor");
        visionSensor->initalize();
        while(!visionSensor->initComplete())
            ;
        DR12_Robot* robot = vRepApi.getDR12Unit("dr12");
        VisionSensor::Resolution resolution = visionSensor->resolution();
        Position robotPos = Bridge::convertToPosition(robot->getGlobalPosition(), resolution);
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
//        //std::ofstream outFile;
//        //outFile.open("output.txt");
//        //playGround->writeToFile(outFile);
        Bridge::drawPath(img, pathCoordList);
        robot->followPath(Bridge::convertToVREPPath(pathCoordList, resolution));
        robot->orientation();
        cv::imshow("opencvtest", img);
        cv::waitKey(0);
        delete visionSensor;
        delete robot;
        vRepApi.disconnect();
    } catch(ConnectionErrorException* ex) {
        std::cout << ex->what() << std::endl;
        delete ex;
    } catch(NoPathException* ex) {
        std::cout << ex->what() << std::endl;
        delete ex;
    }
    return 0;
}
