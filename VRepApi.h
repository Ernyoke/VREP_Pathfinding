#ifndef VREPAPI_H
#define VREPAPI_H

#include <string>
#include <exception>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ConnectionErrorException.h"
#include "Sensor.h"
#include "Position.h"
#include "VisionSensor.h"

extern "C" {
#include "remoteApi/extApi.h"
}

using HANDLE = simxInt;

class VRepApi
{
public:
    VRepApi();
    virtual ~VRepApi();

    simxInt m_clientId;

    void connect(const std::string& ipAddress,
                 const unsigned short port,
                 const bool isBlocking,
                 const bool doNotDiscoonect,
                 const int timeOut,
                 const int commThreadCycleInMs = 5);
    void disconnect();

    HANDLE getObjectHandle(const std::string objectName) const;
    Position getObjectPosition(const std::string objectName) const;
    VisionSensor* getVisionSensor(const std::string objName) const;
    
private:
    void wait(const int sec) const;
};

#endif // VREPAPI_H
