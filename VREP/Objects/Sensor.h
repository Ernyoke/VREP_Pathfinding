#ifndef SENSOR_H
#define SENSOR_H

#include <memory>
#include "Object.h"

class Sensor : public Object {
public:
    virtual ~Sensor();

protected:
    Sensor(const ObjectBuilder &sensorBuilder);
};

#endif // SENSOR_H
