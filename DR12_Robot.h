#ifndef DR12_ROBOT_H
#define DR12_ROBOT_H

#include "Robot.h"

class DR12_Robot : public Robot
{
public:
    virtual ~DR12_Robot();
    
    static DR12_Robot* build(const ObjectBuilder& sensorBuilder);

protected:
    DR12_Robot(const ObjectBuilder& robotBuilder);
};

#endif // DR12_ROBOT_H
