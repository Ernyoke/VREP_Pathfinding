#include <fstream>
#include <iostream>
#include "Playground.h"

Playground::Playground ()
{
    m_Map.clear();
}

Playground::~Playground ()
{
    //empty destructor
}

void Playground::readFromFile (const std::string filename)
{
    std::ifstream file;
    file.open(filename.c_str());

    if (file.is_open()) {
        size_t x, y;
        unsigned int val;
        file >> x;
        file >> y;
        m_Map.resize(x, y);
        for (size_t i = 0; i < x; ++i) {
            for (size_t j = 0; j < y; ++j) {
                file >> val;
                m_Map(i, j) = static_cast<STATE>(val);
            }
        }
        file.close();
    }
}

void Playground::writeToFile(const std::string filename) const
{
    for (size_t i = 0; i < m_Map.size1(); ++i) {
        for (size_t j = 0; j < m_Map.size2(); ++j) {
            std::cout << m_Map(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

bool Playground::touch (const Position position)
{
    bool result = false;
    if (isEmpty(position)) {
        m_Map(position.X(), position.Y()) = TOUCHED;
        result = true;
    }
    return result;
}

bool Playground::isWall (const Position position) const
{
    bool result = false;
    if (position.X() < m_Map.size1() && position.Y() < m_Map.size2()) {
        result = m_Map(position.X(), position.Y()) == WALL;
    }
    return result;
}

bool Playground::isEmpty (const Position position) const
{
    bool result = false;
    if (position.X() < m_Map.size1() && position.Y() < m_Map.size2()) {
        result = m_Map(position.X(), position.Y()) == EMPTY;
    }
    return result;
}

bool Playground::isTouched (const Position position) const
{
    bool result = false;
    if (position.X() < m_Map.size1() && position.Y() < m_Map.size2()) {
        result = m_Map(position.X(), position.Y()) == TOUCHED;
    }
    return result;
}
