#include "Wheel.h"
#include "../../../Exceptions/ReturnCodesExceptions.h"

Wheel *Wheel::build(const ObjectBuilder &objectBuilder) {
    Wheel *wheel = new Wheel(objectBuilder);
    return wheel;
}

Wheel::Wheel(const ObjectBuilder &objectBuilder)
    : Object{objectBuilder} {
}

Wheel::~Wheel() {
}

float Wheel::diameter() const {
    simxFloat zMin = 0;
    simxFloat zMax = 0;
    simxFloat result = 0;
    try {
        ReturnCodesExceptions::handleReturnCode(
            simxGetObjectFloatParameter(m_ClientId, m_Handle, 17, &zMin, simx_opmode_oneshot_wait));
        ReturnCodesExceptions::handleReturnCode(
            simxGetObjectFloatParameter(m_ClientId, m_Handle, 20, &zMax, simx_opmode_oneshot_wait));
        result = zMax - zMin;
    }
    catch (ReturnCodesExceptions *ex) {
        throw ex;
    }
    return static_cast<float>(result);
}
