#include "Position.h"
#include "OutOfBoundException.h"
#include <cmath>

Position::Position(const unsigned int x, const unsigned int y)
        : m_X{x}, m_Y{y} {
}

Position::~Position() {
}

Position Position::go(const Direction dir) const {
    if ((m_X == 0 && dir.x == -1) || (m_Y == 0 && dir.y == -1)) {
        throw new OutOfBoundException("");
    }
    Position newPos{m_X + dir.x, m_Y + dir.y};
    return newPos;
}

double Position::distance(const Position other) const {
    unsigned int x = std::abs(m_X - other.X());
    unsigned int y = std::abs(m_Y - other.Y());
    return std::sqrt(x * x + y * y);
}

unsigned int Position::X() const {
    return m_X;
}

unsigned int Position::Y() const {
    return m_Y;
}
