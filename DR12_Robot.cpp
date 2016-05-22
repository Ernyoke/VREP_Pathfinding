#include "DR12_Robot.h"

DR12_Robot* DR12_Robot::build(const ObjectBuilder& sensorBuilder)
{
    DR12_Robot* dr12Unit = new DR12_Robot(sensorBuilder);
    return dr12Unit;
}

DR12_Robot::DR12_Robot(const ObjectBuilder& robotBuilder)
    : Robot(robotBuilder)
{
}

DR12_Robot::~DR12_Robot()
{
}
