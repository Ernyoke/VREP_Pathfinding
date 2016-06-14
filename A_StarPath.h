#ifndef A_STARPATH_H
#define A_STARPATH_H

#include <memory>
#include <queue>
#include <vector>
#include "Playground.h"
#include "Position.h"
#include "HistoricalPosition.h"
#include "PathInterface.h"

using Field = std::shared_ptr<Playground>;

class A_StarPath : public PathInterface {
public:
    A_StarPath(const Field &playGround);

    virtual ~A_StarPath();

    bool setStartPoint(const Position &startPos);

    bool setEndPoint(const Position &endPos);

    virtual CoordinateList_sptr path();

private:
    const Field m_PlayGround; //the Playground stays unmodified during the life of this class
    Position m_Start;
    Position m_End;

};

#endif // A_STARPATH_H
