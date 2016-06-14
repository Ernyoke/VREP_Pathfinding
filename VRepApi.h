#ifndef VREPAPI_H
#define VREPAPI_H

#include <string>
#include <exception>
#include <tuple>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ConnectionErrorException.h"
#include "Sensor.h"
#include "Position.h"
#include "VisionSensor.h"
#include "DR12_Robot.h"

extern "C" {
#include "remoteApi/extApi.h"
}

using HANDLE = simxInt;

class VRepApi {
public:
    VRepApi();

    virtual ~VRepApi();

    simxInt m_clientId;

    void connect(const std::string &ipAddress,
                 const unsigned short port,
                 const bool isBlocking,
                 const bool doNotDiscoonect,
                 const int timeOut,
                 const int commThreadCycleInMs = 5);

    void disconnect();

    HANDLE getObjectHandle(const std::string &objectName) const;

    VisionSensor *getVisionSensor(const std::string objName) const;

    DR12_Robot *getDR12Unit(const std::string &objName,
                            const std::string &rightWheelName = "dr12_rightWheel_",
                            const std::string &leftWheelName = "dr12_leftWheel_",
                            const std::string &rightJointName = "dr12_rightJoint_",
                            const std::string &leftJointName = "dr12_leftJoint_") const;

private:
    void wait(const int sec) const;
};

#endif // VREPAPI_H
