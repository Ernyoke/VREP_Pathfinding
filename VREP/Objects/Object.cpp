#include "Object.h"
#include "../Exceptions/ReturnCodesExceptions.h"

Object::Object(const ObjectBuilder &objectBuilder)
    : m_ClientId{objectBuilder.clientId}, m_Handle{objectBuilder.handle} {
}

Object::~Object() {
}

std::tuple<float, float, float> Object::globalPosition() const {
    simxFloat *positionVec = new simxFloat[3];
    try {
        ReturnCodesExceptions::handleReturnCode(
            simxGetObjectPosition(m_ClientId, m_Handle, -1, positionVec, simx_opmode_oneshot_wait));
        return std::make_tuple(static_cast<float>(positionVec[0]), positionVec[1], positionVec[2]);
    }
    catch (ReturnCodesExceptions *ex) {
        throw ex;
    }
}
