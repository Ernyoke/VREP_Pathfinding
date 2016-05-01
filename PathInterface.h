#ifndef PATHINTERFACE_H
#define PATHINTERFACE_H

#include <list>
#include <memory>
#include "Position.h"

using CoordinateList = std::list<Position>;
using CoordinateList_sptr = std::shared_ptr<CoordinateList>; 

class PathInterface
{
public:
    PathInterface();
    virtual ~PathInterface();

    virtual CoordinateList_sptr path() = 0;
};

#endif // PATHINTERFACE_H
