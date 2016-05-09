#ifndef SENSOR_H
#define SENSOR_H

#include <memory>

extern "C" {
#include "remoteApi/extApi.h"
}

class VRepApi;

struct SensorBuilder
{
    simxInt clientId;
    simxInt handle;
};

class Sensor
{
public:
    virtual ~Sensor();
    
    virtual void initalize() = 0;

protected:
    Sensor(const SensorBuilder& sensorBuilder);
    const simxInt m_ClientId;
    const simxInt m_Handle;
};

#endif // SENSOR_H
