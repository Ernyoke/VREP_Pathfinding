#include "Joint.h"

Joint* Joint::build(const ObjectBuilder& objectBuilder)
{
    Joint* joint = new Joint(objectBuilder);
    return joint;
}

Joint::Joint(const ObjectBuilder& objectBuilder)
    : Object{ objectBuilder }
{
}

Joint::~Joint()
{
}

void Joint::setTargetVelocity(const float velocity)
{
    simxSetJointTargetVelocity(m_ClientId, m_Handle, velocity, simx_opmode_oneshot);
}
