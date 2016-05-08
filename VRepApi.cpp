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

HANDLE VRepApi::getObjectHandle(const std::string objectName) const
{
    HANDLE handle = 0;
    simxGetObjectHandle(m_clientId, const_cast<simxChar*>(objectName.c_str()), &handle, simx_opmode_oneshot_wait);
    return handle;
}

cv::Mat VRepApi::getSensorImage(HANDLE handle, bool grayscale)
{
    simxInt resolution[] = { 0, 0 };
    simxUChar* imgData = NULL;
    
    imgData = new simxUChar[512 * 512];
    
    std::cout << simxGetVisionSensorImage(m_clientId, handle, resolution, &imgData, 1, simx_opmode_streaming);
//    std::this_thread::sleep_for(std::chrono::seconds(3));
    while(resolution[0] <= 0) {
        simxGetVisionSensorImage(m_clientId, handle, resolution, &imgData, 1, simx_opmode_buffer);
    }
    
    cv::Mat img(512, 512, CV_8UC1, imgData);
    
    return img;
}