#include "VisionSensor.h"
#include "../../Exceptions/ReturnCodesExceptions.h"

VisionSensor *VisionSensor::build(const ObjectBuilder &sensorBuilder) {
    VisionSensor *sensor = new VisionSensor(sensorBuilder);
    return sensor;
}

VisionSensor::VisionSensor(const ObjectBuilder &sensorBuilder)
    : Sensor(sensorBuilder) {
}

VisionSensor::~VisionSensor() {
}

VisionSensor::Resolution VisionSensor::resolution() const {
    try {
        Resolution res{0, 0};
        simxInt resolutionVec[] = {0, 0};
        simxUChar *imgData = new simxUChar[1];
        ReturnCodesExceptions::handleReturnCode(
            simxGetVisionSensorImage(m_ClientId, m_Handle, resolutionVec, &imgData, 1, simx_opmode_oneshot_wait));
        res.width = static_cast<unsigned int>(resolutionVec[0]);
        res.height = static_cast<unsigned int>(resolutionVec[1]);
        return res;
    }
    catch (ReturnCodesExceptions *ex) {
        throw ex;
    }
}

cv::Mat VisionSensor::image(const ImageType &imageType) const {
    try {
        simxUChar *imgData = nullptr;
        Resolution res = {0, 0};
        res = resolution();
        simxInt resolutionVec[] = {0, 0};
        switch (imageType) {
            case GRAYSCALE: {
                imgData = new simxUChar[res.height * res.height];
                break;
            }
            case RGB: {
                imgData = new simxUChar[res.height * res.height * 3];
                break;
            }
        }
        ReturnCodesExceptions::handleReturnCode(
            simxGetVisionSensorImage(m_ClientId, m_Handle, resolutionVec, &imgData, imageType, simx_opmode_oneshot_wait));
        return cv::Mat(res.height, res.width, convertImageType(imageType), imgData);
    }
    catch (ReturnCodesExceptions ex) {
        throw ex;
    }
}

unsigned int VisionSensor::convertImageType(const ImageType &imageType) const {
    unsigned int result = 0;
    switch (imageType) {
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
