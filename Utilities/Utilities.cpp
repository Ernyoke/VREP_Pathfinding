//
// Created by ervin on 15.06.2016.
//

#include "Utilities.h"

float Utilities::orientationXY(const std::tuple<float, float, float>& euler) {
    float x = std::get<0>(euler);
    float y = std::get<1>(euler);
    float z = std::get<2>(euler);

    if (x >= 0 && z >= 0) {
        if (y <= 0 && y > -PI / 2) {
            return std::abs(y);
        }
        if (y > 0 && y < PI / 2) {
            return 2 * PI - std::abs(y);
        }
    }
    if (x < 0 && z < 0) {
        if (y <= 0 && y > -PI / 2) {
            return PI - std::abs(y);
        }
        if (y > 0 && y < PI / 2) {
            return PI + std::abs(y);
        }
    }
}
