#ifndef BRIDGE_H
#define BRIDGE_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "Position.h"

namespace Bridge
{
    Position convertToPosition(const std::tuple<float, float, float>);
    void coverMe(cv::Mat& ground, const Position& pos, const unsigned int radius);
};

#endif // BRIDGE_H
