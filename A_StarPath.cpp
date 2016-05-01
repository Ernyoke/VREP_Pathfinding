#include "A_StarPath.h"
#include "OutOfBoundException.h"
#include "NoPathException.h"

#include <iostream>

static const Direction dir[] = {
    Direction(0, -1), // N
    Direction(-1, 0), // W
    Direction(0, 1), // S
    Direction(1, 0), // E
    Direction(-1, -1), // NW
    Direction(1, -1), // SW
    Direction(1, 1), // SE
    Direction(-1, 1) // NE
};

A_StarPath::A_StarPath(const Field playGround)
    : m_PlayGround{ playGround }
    , m_Start{ 0, 0 }
    , m_End{ 0, 0 }
{
}

A_StarPath::~A_StarPath()
{
}

bool A_StarPath::setStartPoint(Position startPos)
{
    bool result = false;
    if(m_PlayGround->isEmpty(startPos)) {
        m_Start = startPos;
        result = true;
    }
    return result;
}

bool A_StarPath::setEndPoint(Position endPos)
{
    bool result = false;
    if(m_PlayGround->isEmpty(endPos)) {
        m_End = endPos;
        result = true;
    }
    return result;
}

void A_StarPath::path()
{
    if(!m_PlayGround->dimension().area()) {
        throw new NoPathException("Area of field is 0!");
    }

    Playground copyPlayGround = *m_PlayGround.get();

    auto cmp = [&](const HistoricalPosition& p1, const HistoricalPosition& p2)
                   -> bool { return p1.distance(m_End) + p1.step() > p2.distance(m_End) + p2.step(); };

    std::priority_queue<HistoricalPosition, std::vector<HistoricalPosition>, decltype(cmp)> posList(cmp);

    HistoricalPosition current(m_Start);

    while(current != m_End) {
        for(int i = 0; i < 8; ++i) {
            try {
                HistoricalPosition next = current.go(dir[i]);
                if(copyPlayGround.isEmpty(next)) {
                    next.setPreviousPosition(current);
                    posList.push(next);
                }
            } catch(OutOfBoundException* ex) {
                delete ex;
            }
        }

        if(posList.empty()) {
            throw new NoPathException("No path found!");
        }

        copyPlayGround.touch(current);
        current = posList.top();
        posList.pop();
    }

    const HistoricalPosition* pathPos = current.getPrevoiusPosition();
    std::cout << current.X() << " " << current.Y() << std::endl;
    while(pathPos->getPrevoiusPosition() != nullptr) {
        std::cout << pathPos->X() << " " << pathPos->Y() << std::endl;
        pathPos = pathPos->getPrevoiusPosition();
    }
    std::cout << pathPos->X() << " " << pathPos->Y() << std::endl;
}
