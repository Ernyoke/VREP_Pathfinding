#include "VisionSensor.h"

VisionSensor* VisionSensor::build(const SensorBuilder& sensorBuilder)
{
    VisionSensor* sensor = new VisionSensor(sensorBuilder);
    return sensor;
}

VisionSensor::VisionSensor(const SensorBuilder& sensorBuilder)
    : Sensor(sensorBuilder)
    , isInitialized{ false }
{
}

VisionSensor::~VisionSensor()
{
}

void VisionSensor::initalize()
{
    if(!isInitialized) {
        simxInt resolution[] = { 0, 0 };
        simxUChar* imgData = new simxUChar[1];
        simxInt result = simxGetVisionSensorImage(m_ClientId, m_Handle, resolution, &imgData, 1, simx_opmode_streaming);
        isInitialized = true;
    }
}

bool VisionSensor::initComplete() const
{
    bool result = false;
    if(isInitialized) {
        simxInt resolution[] = { 0, 0 };
        simxUChar* imgData = new simxUChar[1];
        simxInt tempResult =
            simxGetVisionSensorImage(m_ClientId, m_Handle, resolution, &imgData, 1, simx_opmode_buffer);
        tempResult == 0 ? result = true : result = false;
    }
    return result;
}

VisionSensor::Resolution VisionSensor::resolution() const
{
    Resolution res{ 0, 0 };
    if(isInitialized) {
        simxInt resolutionVec[] = { 0, 0 };
        simxUChar* imgData = new simxUChar[1];
        simxInt tempResult =
            simxGetVisionSensorImage(m_ClientId, m_Handle, resolutionVec, &imgData, 1, simx_opmode_buffer);
        res.width = static_cast<unsigned int>(resolutionVec[0]);
        res.height = static_cast<unsigned int>(resolutionVec[1]);
    }
    return res;
}

cv::Mat VisionSensor::image(const ImageType& imageType) const
{
    simxUChar* imgData = nullptr;
    Resolution res = { 0, 0 };
    if(isInitialized) {
        res = resolution();
        simxInt resolutionVec[] = { 0, 0 };
        switch(imageType) {
        case GRAYSCALE: {
            imgData = new simxUChar[res.height * res.height];
            break;
        }
        case RGB: {
            imgData = new simxUChar[res.height * res.height * 3];
            break;
        }
        }
        simxGetVisionSensorImage(m_ClientId, m_Handle, resolutionVec, &imgData, imageType, simx_opmode_buffer);
    }

    return cv::Mat(res.height, res.width, convertImageType(imageType), imgData);
}

unsigned int VisionSensor::convertImageType(const ImageType& imageType) const
{
    unsigned int result = 0;
    switch(imageType) {
    case GRAYSCALE: {
        result = CV_8UC1;
        break;
    }
    case RGB: {
        result = CV_8UC3;
        break;
    }
    }
    return result;
}