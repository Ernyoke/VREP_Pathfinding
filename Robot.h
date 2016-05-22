#ifndef ROBOT_H
#define ROBOT_H

#include "Object.h"

class Robot : public Object
{
public:
    virtual ~Robot();

protected:
    Robot(const ObjectBuilder& robotBuilder);
};

#endif // ROBOT_H
