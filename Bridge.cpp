#include "Bridge.h"

Position Bridge::convertToPosition(const std::tuple<float, float, float> pos,
                                   const VisionSensor::Resolution &resolution) {
    return Position{(std::get<0>(pos) + 2.5f) * resolution.height / 5.0f, (std::get<1>(pos) + 2.5f) * resolution.width / 5.0f};
}

std::tuple<float, float, float> Bridge::convertToVREPCoordinate(const Position &pos,
                                                                const VisionSensor::Resolution &resolution) {
    float x = (pos.X() * 5.0f) / resolution.height - 2.5f;
    float y = (pos.Y() * 5.0f) / resolution.width - 2.5f;
    float z = 0;
    std::cout << x << " " << y << " " << z << " " << std::endl;
    return std::make_tuple(x, y, z);
}

std::vector<std::tuple<float, float, float> > Bridge::convertToVREPPath(const CoordinateList_sptr &pathCoordList,
                                                                        const VisionSensor::Resolution &resolution) {
    std::vector<std::tuple<float, float, float> > vrepPath;
    for (auto it = pathCoordList->cbegin(); it != pathCoordList->cend(); ++it) {
        vrepPath.push_back(convertToVREPCoordinate(*it, resolution));
    }
    return vrepPath;
}

void Bridge::coverObject(cv::Mat &ground, const Position &pos, const unsigned int radius, const cv::Scalar &color) {
    cv::circle(ground, cv::Point(pos.X(), pos.Y()), radius, color, -1);
}

void Bridge::enlargeBorder(cv::Mat& image, const unsigned int kernel) {
    cv::dilate(image, image, 255 * cv::getStructuringElement(cv::MORPH_RECT, cv::Size(kernel, kernel)));
}

boost::numeric::ublas::matrix<STATE> Bridge::createGroundMap(const cv::Mat &ground) {
    cv::Size size = ground.size();
    boost::numeric::ublas::matrix<STATE> groundMap;
    groundMap.resize(size.height, size.width);
    for (unsigned int i = 0; i < size.height; ++i) {
        for (unsigned int j = 0; j < size.width; ++j) {
            if (ground.at<uchar>(j, i) == 0) {
                groundMap(i, j) = EMPTY;
            } else {
                groundMap(i, j) = WALL;
            }
        }
    }
    return groundMap;
}

cv::Mat Bridge::createImgMap(const boost::numeric::ublas::matrix<STATE> &groundMap) {
    cv::Mat ground(groundMap.size1(), groundMap.size2(), CV_8UC3, cv::Scalar(0, 0, 0));
    for (unsigned int i = 0; i < groundMap.size1(); ++i) {
        for (unsigned int j = 0; j < groundMap.size2(); ++j) {
            if (groundMap(i, j) == 0) {
                ground.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 0, 0);
            } else {
                ground.at<cv::Vec3b>(i, j) = cv::Vec3b(255, 255, 255);
            }
        }
    }
    return ground;
}

void Bridge::drawPath(cv::Mat &ground, CoordinateList_sptr &pathCoordList) {
    for (auto it = pathCoordList->cbegin(); it != pathCoordList->cend(); ++it) {
        ground.at<uchar>(it->Y(), it->X()) = 255;
    }
}