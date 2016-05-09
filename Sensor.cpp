#include "Sensor.h"
#include <string.h>

Sensor::Sensor(const SensorBuilder& sensorBuilder)
    : m_ClientId(sensorBuilder.clientId)
    , m_Handle(sensorBuilder.handle)
{
}

Sensor::~Sensor()
{
}
