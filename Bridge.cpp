#include "Bridge.h"

#include <tuple>

Position Bridge::convertToPosition(const std::tuple<float, float, float> pos)
{
    return Position{(std::get<0>(pos) + 2.5) * 512 / 5, (std::get<1>(pos) + 2.5) * 512 / 5 };
}

void Bridge::coverMe(cv::Mat& ground, const Position& pos, const unsigned int radius)
{
    cv::circle(ground, cv::Point(pos.X(), pos.Y()), radius, cv::Scalar(0, 0, 0), -1);
}
