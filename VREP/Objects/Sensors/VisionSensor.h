#ifndef VISIONSENSOR_H
#define VISIONSENSOR_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "../Sensor.h"

class VisionSensor : public Sensor {
public:

    enum ImageType {
        RGB = 0,
        GRAYSCALE = 1
    };

    struct Resolution {
        unsigned int width;
        unsigned int height;
    };

    virtual ~VisionSensor();

    static VisionSensor *build(const ObjectBuilder &sensorBuilder);

    virtual void initalize();

    bool initComplete() const;

    cv::Mat image(const ImageType &imageType) const;

    Resolution resolution() const;

protected:
    VisionSensor(const ObjectBuilder &sensorBuilder);

private:
    bool isInitialized;

    unsigned int convertImageType(const ImageType &imageType) const;

};

#endif // VISIONSENSOR_H
