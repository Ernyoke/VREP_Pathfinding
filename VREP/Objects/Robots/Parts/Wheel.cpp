#include "Wheel.h"

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
    simxGetObjectFloatParameter(m_ClientId, m_Handle, 17, &zMin, simx_opmode_oneshot_wait);
    simxGetObjectFloatParameter(m_ClientId, m_Handle, 20, &zMax, simx_opmode_oneshot_wait);
    return zMax - zMin;
}
