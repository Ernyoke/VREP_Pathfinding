#include <fstream>
#include <iostream>
#include "Playground.h"

Dimension::Dimension(unsigned int width, unsigned int height)
    : m_Width{ width }
    , m_Height{ height }
{
}

Dimension::~Dimension()
{
    // empty destructor
}

unsigned int Dimension::area() const
{
    return m_Width * m_Height;
}

Playground::Playground()
{
    m_Map.clear();
}

Playground::Playground(const Matrix& groundMap)
    : m_Map{ groundMap }
{
}

Playground::~Playground()
{
    // empty destructor
}

void Playground::readFromFile(std::ifstream& stream)
{
    if(stream.is_open()) {
        unsigned int x, y;
        unsigned int val;
        stream >> x;
        stream >> y;
        m_Map.resize(x, y);
        for(size_t i = 0; i < x; ++i) {
            for(size_t j = 0; j < y; ++j) {
                stream >> val;
                m_Map(i, j) = static_cast<STATE>(val);
            }
        }
    }
}

void Playground::writeToFile(std::ostream& stream) const
{
    for(size_t i = 0; i < m_Map.size1(); ++i) {
        for(size_t j = 0; j < m_Map.size2(); ++j) {
            stream << m_Map(i, j) << " ";
        }
        stream << std::endl;
    }
}

bool Playground::touch(const Position position)
{
    bool result = false;
    if(isEmpty(position)) {
        m_Map(position.X(), position.Y()) = TOUCHED;
        result = true;
    }
    return result;
}

bool Playground::isWall(const Position position) const
{
    bool result = false;
    if(position.X() < m_Map.size1() && position.Y() < m_Map.size2()) {
        result = m_Map(position.X(), position.Y()) == WALL;
    }
    return result;
}

bool Playground::isEmpty(const Position position) const
{
    bool result = false;
    if(position.X() < m_Map.size1() && position.Y() < m_Map.size2()) {
        STATE val = m_Map(position.X(), position.Y());
        result = m_Map(position.X(), position.Y()) == EMPTY;
    }
    return result;
}

bool Playground::isTouched(const Position position) const
{
    bool result = false;
    if(position.X() < m_Map.size1() && position.Y() < m_Map.size2()) {
        result = m_Map(position.X(), position.Y()) == TOUCHED;
    }
    return result;
}

Dimension Playground::dimension() const
{
    return Dimension{ static_cast<unsigned int>(m_Map.size1()), static_cast<unsigned int>(m_Map.size2()) };
}
