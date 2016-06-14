#ifndef WHEEL_H
#define WHEEL_H

#include "Object.h"

class Wheel : public Object {
public:
    virtual ~Wheel();

    static Wheel *build(const ObjectBuilder &objectBuilder);

    float diameter() const;

protected:
    Wheel(const ObjectBuilder &objectBuilder);
};

#endif // WHEEL_H
