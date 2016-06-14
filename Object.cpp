#include "Object.h"

Object::Object(const ObjectBuilder &objectBuilder)
        : m_ClientId{objectBuilder.clientId}, m_Handle{objectBuilder.handle} {
}

Object::~Object() {
}

std::tuple<float, float, float> Object::getGlobalPosition() const {
    simxFloat *positionVec = new simxFloat[3];
    int errorCode = simxGetObjectPosition(m_ClientId, m_Handle, -1, positionVec, simx_opmode_oneshot_wait);
    return std::make_tuple(static_cast<float>(positionVec[0]), positionVec[1], positionVec[2]);
}
