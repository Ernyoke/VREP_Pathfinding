#include <iostream>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "memory"
#include "Playground.h"
#include "Position.h"
#include "A_StarPath.h"
#include "NoPathException.h"
#include "VRepApi.h"

int main(int argc, char** argv)
{
    /*
    auto playGround = std::shared_ptr<Playground>(new Playground());
    std::ifstream inFile;
    inFile.open("input.txt");
    playGround->readFromFile(inFile);
    inFile.close();
    playGround->writeToFile(std::cout);
    A_StarPath path(playGround);
    path.setStartPoint(Position(5, 5));
    path.setEndPoint(Position(0, 1));
    try {
        CoordinateList_sptr pathCoordList = path.path();
        for(auto it = pathCoordList->cbegin(); it != pathCoordList->cend(); ++it) {
            std::cout << it->X() << " " << it->Y() << std::endl;
        }
    } catch(NoPathException* ex) {
        std::cout << ex->what() << std::endl;
        delete ex;
    }
    */

    VRepApi vRepApi;
    
    std::cout << "Waiting for connection!" << std::endl;
    
    try {
        vRepApi.connect("127.0.0.1", 19997, true, true, 2000);
        std::cout << "Connected!" << std::endl;
        cv::Mat img = vRepApi.getSensorImage(vRepApi.getObjectHandle("mapSensor"), false);
        cv::imshow("opencvtest",img);
        cv::waitKey(0);
    } catch(ConnectionErrorException* ex) {
        std::cout << ex->what() << std::endl;
        delete ex;
    }
    
//    cv::Mat img = cv::imread("/home/ervin/Pictures/wallhaven-112263.jpg",CV_LOAD_IMAGE_COLOR);
//    cv::imshow("opencvtest",img);
//    cv::waitKey(0);

    return 0;
}
