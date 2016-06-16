#ifndef OBJECT_H
#define OBJECT_H

#include <tuple>

extern "C" {
#include "../../remoteApi/extApi.h"
#include "../../remoteApi/v_repConst.h"
}

struct ObjectBuilder {
    simxInt clientId;
    simxInt handle;
};

class Object {
public:
    virtual ~Object();

    std::tuple<float, float, float> globalPosition() const;

protected:
    const simxInt m_ClientId;
    const simxInt m_Handle;

    Object(const ObjectBuilder &objectBuilder);
};

#endif // OBJECT_H
