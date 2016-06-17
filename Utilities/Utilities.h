//
// Created by ervin on 15.06.2016.
//

#ifndef VREP_PATHFINDING_UTILITIES_H
#define VREP_PATHFINDING_UTILITIES_H


#include <tuple>
#include <cmath>

namespace Utilities {

    constexpr float PI = 3.14159265;

    template <typename T>
    T distance(const std::tuple<T, T>& a, const std::tuple<T, T>& b) {
        T x = std::abs(std::get<0>(a) - std::get<0>(b));
        T y = std::abs(std::get<1>(a) - std::get<1>(b));
        return std::sqrt(x * x + y * y);
    }

    float orientationXY(const std::tuple<float, float, float>& euler);
};


#endif //VREP_PATHFINDING_UTILITIES_H
