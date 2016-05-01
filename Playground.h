#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <boost/numeric/ublas/matrix.hpp>
#include "Position.h"

enum STATE { WALL = 1, TOUCHED = 2, EMPTY = 0, START = 3, END = 4 };

class Dimension
{
public:
    Dimension(unsigned int width, unsigned int height);
    ~Dimension();

    unsigned int area() const;

private:
    unsigned int m_Width, m_Height;
};

class Playground
{

public:
    Playground();
    virtual ~Playground();

    void readFromFile(std::ifstream& stream);
    void writeToFile(std::ostream& stream) const;

    bool touch(const Position position);
    bool isWall(const Position position) const;
    bool isEmpty(const Position position) const;
    bool isTouched(const Position position) const;

    Dimension dimension() const;

private:
    boost::numeric::ublas::matrix<STATE> m_Map;
};

#endif // PLAYGROUND_H
