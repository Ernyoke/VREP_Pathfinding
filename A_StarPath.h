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

class A_StarPath : public PathInterface
{
public:
    A_StarPath(const Field playGround);
    virtual ~A_StarPath();

    bool setStartPoint(Position startPos);
    bool setEndPoint(Position endPos);
    
    virtual void path();
    
private:
    Field m_PlayGround;
    Position m_Start;
    Position m_End;
};

#endif // A_STARPATH_H
