#include "Object.h"
#include "../Exceptions/ReturnCodesExceptions.h"

Object *Object::build(const ObjectBuilder &objectBuilder) {
    Object *object = new Object(objectBuilder);
    return object;
}

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

void Object::setGlobalPosition(std::tuple<float, float, float>& position) {
    int N = 3;
    simxFloat positionVec[N];
    positionVec[0] = std::get<0>(position);
    positionVec[1] = std::get<1>(position);
    positionVec[2] = std::get<2>(position);
    try {
        ReturnCodesExceptions::handleReturnCodeNoResponse(
                simxSetObjectPosition(m_ClientId, m_Handle, -1, positionVec, simx_opmode_oneshot));
    }
    catch (ReturnCodesExceptions *ex) {
        throw ex;
    }
}

Object* Object::parent() {
    simxInt parentHandle = 0;
    try {
        ReturnCodesExceptions::handleReturnCode(
                simxGetObjectParent(m_ClientId, m_Handle, &parentHandle, simx_opmode_oneshot_wait));
        return Object::build(ObjectBuilder {m_ClientId, parentHandle});
    }
    catch (ReturnCodesExceptions *ex) {
        throw ex;
    }
}
