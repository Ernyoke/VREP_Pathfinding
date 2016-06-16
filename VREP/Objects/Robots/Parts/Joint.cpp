#include "Joint.h"
#include "../../../Exceptions/ReturnCodesExceptions.h"

Joint *Joint::build(const ObjectBuilder &objectBuilder) {
    Joint *joint = new Joint(objectBuilder);
    return joint;
}

Joint::Joint(const ObjectBuilder &objectBuilder)
    : Object{objectBuilder} {
}

Joint::~Joint() {
}

void Joint::setTargetVelocity(const float velocity) {
    try {
        ReturnCodesExceptions::handleReturnCode(
            simxSetJointTargetVelocity(m_ClientId, m_Handle, velocity, simx_opmode_oneshot));
    }
    catch (ReturnCodesExceptions *ex) {
        throw ex;
    }
}
