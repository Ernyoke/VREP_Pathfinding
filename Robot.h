#ifndef ROBOT_H
#define ROBOT_H

#include "Object.h"

struct RobotBuilder : public ObjectBuilder {
    RobotBuilder(simxInt clientId, simxInt handle);
};

class Robot : public Object
{
public:
    virtual ~Robot();

protected:
    Robot(const RobotBuilder& robotBuilder);
};

#endif // ROBOT_H
