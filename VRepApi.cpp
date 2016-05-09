#include "VRepApi.h"

#include <iostream>
#include <chrono>
#include <thread>

VRepApi::VRepApi()
    : m_clientId{ 0 }
{
}

VRepApi::~VRepApi()
{
}

void VRepApi::connect(const std::string& ipAddress,
                      const unsigned short port,
                      const bool isBlocking,
                      const bool doNotDiscoonect,
                      const int timeOut,
                      const int commThreadCycleInMs)
{
    simxInt clientID = simxStart(
        const_cast<simxChar*>(ipAddress.c_str()), port, isBlocking, doNotDiscoonect, timeOut, commThreadCycleInMs);
    if(clientID < 0) {
        throw new ConnectionErrorException("Could not connect to the server!", clientID);
    } else {
        m_clientId = clientID;
    }
}

void VRepApi::disconnect()
{
    simxFinish(m_clientId);
}

HANDLE VRepApi::getObjectHandle(const std::string objectName) const
{
    HANDLE handle = 0;
    simxGetObjectHandle(m_clientId, const_cast<simxChar*>(objectName.c_str()), &handle, simx_opmode_oneshot_wait);
    return handle;
}

VisionSensor* VRepApi::getVisionSensor(const std::string objName) const
{
    HANDLE handle = getObjectHandle(objName);
    SensorBuilder builder{ m_clientId, handle };
    return VisionSensor::build(builder);
}

Position VRepApi::getObjectPosition(const std::string objName) const {
    HANDLE handle = getObjectHandle(objName);
    simxFloat *positionVec = new simxFloat[3];
    std::cout << "Errorcode: " << simxGetObjectPosition(m_clientId, handle, -1, positionVec, simx_opmode_oneshot_wait) << std::endl;
    std::cout << positionVec[0] << " " << positionVec[1] <<  " " << positionVec[2] << std::endl;
    return Position {(positionVec[0] + 2.5) * 512 / 5, (positionVec[1] + 2.5) * 512 / 5};
}

void VRepApi::wait(const int sec) const {
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}
