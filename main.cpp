#include <iostream>
#include <fstream>
#include "memory"
#include "Playground.h"
#include "Position.h"
#include "A_StarPath.h"
#include "NoPathException.h"

int main(int argc, char** argv)
{
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
    return 0;
}
