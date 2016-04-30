#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <boost/numeric/ublas/matrix.hpp>
#include "Position.h"

enum STATE {
    WALL = 1,
    TOUCHED = 2,
    EMPTY = 0,
    START = 3,
    END = 4
};

class Playground
{

public:

    Playground ();
    virtual ~Playground ();
    
    void readFromFile(const std::string file);
    void writeToFile(const std::string file) const;

    bool touch (const Position position);
    bool isWall (const Position position) const;
    bool isEmpty (const Position position) const;
    bool isTouched (const Position position) const;
    
private:
    boost::numeric::ublas::matrix<STATE> m_Map;
};

#endif // PLAYGROUND_H
