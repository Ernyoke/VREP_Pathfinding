#ifndef BRIDGE_H
#define BRIDGE_H

#include <tuple>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <boost/numeric/ublas/matrix.hpp>

#include "Position.h"
#include "VisionSensor.h"
#include "Playground.h"
#include "PathInterface.h"

namespace Bridge {
    Position convertToPosition(const std::tuple<float, float, float>, const VisionSensor::Resolution &resolution);

    std::tuple<float, float, float> convertToVREPCoordinate(const Position &pos,
                                                            const VisionSensor::Resolution &resolution);

    std::vector<std::tuple<float, float, float> > convertToVREPPath(const CoordinateList_sptr &pathCoordList,
                                                                    const VisionSensor::Resolution &resolution);

    void coverObject(cv::Mat &ground,
                     const Position &pos,
                     const unsigned int radius,
                     const cv::Scalar &color = cv::Scalar(0, 0, 0));

    boost::numeric::ublas::matrix<STATE> createGroundMap(const cv::Mat &ground);

    cv::Mat createImgMap(const boost::numeric::ublas::matrix<STATE> &groundMap);

    void drawPath(cv::Mat &ground, CoordinateList_sptr &pathCoordList);
};

#endif // BRIDGE_H
