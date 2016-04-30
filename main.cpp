#include <iostream>
#include "memory"
#include "Playground.h"
#include "Position.h"
#include "A_StarPath.h"
#include "NoPathException.h"

int main(int argc, char **argv)
{
    auto playGround = std::shared_ptr<Playground> (new Playground());
    playGround->readFromFile ("input.txt");
    playGround->writeToFile ("");
    A_StarPath path (playGround);
    path.setStartPoint (Position(5, 2));
    path.setEndPoint (Position(0, 3));
    try {
        path.path ();
    } catch (NoPathException *ex) {
        std::cout << ex->what() << std::endl;
        delete ex;
    }
    return 0;
}
