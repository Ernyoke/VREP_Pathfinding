#include "HistoricalPosition.h"
#include "OutOfBoundException.h"

HistoricalPosition::HistoricalPosition (unsigned int x, unsigned int y, unsigned int step) :
    Position {x, y}, m_Step {step}, m_PrevPosition {nullptr} {
}

HistoricalPosition::HistoricalPosition(const Position& p, unsigned int step) :
    Position {p}, m_Step {step}, m_PrevPosition {nullptr} {
}

HistoricalPosition::~HistoricalPosition ()
{
    //delete m_PrevPosition;
}

void HistoricalPosition::setStep (const unsigned int step)
{
    m_Step = step;
}

unsigned int HistoricalPosition::step () const
{
    return m_Step;
}

void HistoricalPosition::setPreviousPosition (const HistoricalPosition& prevPosition)
{
    m_PrevPosition = new HistoricalPosition (prevPosition);
}

const HistoricalPosition* HistoricalPosition::getPrevoiusPosition () const
{
    return m_PrevPosition;
}

HistoricalPosition HistoricalPosition::go(const Direction dir)
{
    if ((m_X == 0 && dir.x == -1) || (m_Y == 0 && dir.y == -1)) {
        throw new OutOfBoundException("");
    }
    HistoricalPosition newPos {m_X + dir.x, m_Y + dir.y, m_Step + 1};
    return newPos;
}
