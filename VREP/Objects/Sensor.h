#ifndef SENSOR_H
#define SENSOR_H

#include <memory>
#include "Object.h"

class Sensor : public Object {
public:
    virtual ~Sensor();

    virtual void initalize() = 0;

protected:
    Sensor(const ObjectBuilder &sensorBuilder);
};

#endif // SENSOR_H
