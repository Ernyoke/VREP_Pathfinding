#include <cmath>
#include <iostream>
#include <thread>

#include "DR12_Robot.h"
#include "../../../Utilities/Utilities.h"

DR12RobotBuilder::DR12RobotBuilder(simxInt clientId,
                                   simxInt handle,
                                   simxInt rightWheelHandle,
                                   simxInt leftWheelHandle,
                                   simxInt rightJointHandle,
                                   simxInt leftJointHandle)
        : RobotBuilder{clientId, handle}, rightWheelHandle{rightWheelHandle}, leftWheelHandle{leftWheelHandle},
          rightJointHandle{rightJointHandle}, leftJointHandle{leftJointHandle} {
}

DR12_Robot *DR12_Robot::build(const DR12RobotBuilder &robotBuilder) {
    DR12_Robot *dr12Unit = new DR12_Robot(robotBuilder);
    return dr12Unit;
}

DR12_Robot::DR12_Robot(const DR12RobotBuilder &robotBuilder)
        : Robot(robotBuilder) {
    m_RightWheel = Wheel::build(ObjectBuilder{m_ClientId, robotBuilder.rightWheelHandle});
    m_LeftWheel = Wheel::build(ObjectBuilder{m_ClientId, robotBuilder.leftWheelHandle});
    m_RightJoint = Joint::build(ObjectBuilder{m_ClientId, robotBuilder.rightJointHandle});
    m_LeftJoint = Joint::build(ObjectBuilder{m_ClientId, robotBuilder.leftJointHandle});
}

DR12_Robot::~DR12_Robot() {
    delete m_RightWheel;
    delete m_LeftWheel;
    delete m_RightJoint;
    delete m_LeftJoint;
}

float DR12_Robot::wheelDiameter() const {
    return m_RightWheel->diameter();
}

float DR12_Robot::wheelDistance() const {
    std::tuple<float, float, float> rightWheelPos = m_RightWheel->getGlobalPosition();
    std::tuple<float, float, float> leftWheelPos = m_LeftWheel->getGlobalPosition();

    return Utilities::distance(std::make_tuple(std::get<0>(rightWheelPos), std::get<1>(rightWheelPos)),
                               std::make_tuple(std::get<0>(leftWheelPos), std::get<1>(leftWheelPos)));

//    float x = std::abs(std::get<0>(rightWheelPos) - std::get<0>(leftWheelPos));
//    float y = std::abs(std::get<1>(rightWheelPos) - std::get<1>(leftWheelPos));
//
//    return std::sqrt(x * x + y * y);
}

void DR12_Robot::followPath(const std::vector<std::tuple<float, float, float> > &path) {
    float speed = 0.5;
    float rotationSpeed = 0.5;
    float d = wheelDistance();
    float speedRight = speed + d * rotationSpeed;
    float speedLeft = speed - d * rotationSpeed;
    float r = wheelDiameter() / 2;
    float omagaRight = speedRight / r;
    float omagaLeft = speedLeft / r;

    bool stop = false;
    int i = 200;

    while (!stop) {
        auto pathPoint = path.at(i);
        float orientation = relativeOrientationXY(std::make_tuple(std::get<0>(pathPoint), std::get<1>(pathPoint)));
        go(-omagaRight * orientation, -omagaLeft * orientation);
        auto position = getGlobalPosition();
        float distance = Utilities::distance(std::make_tuple(std::get<0>(position), std::get<1>(position)),
                                             std::make_tuple(std::get<0>(pathPoint), std::get<1>(pathPoint)));
        if (distance < 0.05) {
            i += 50;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void DR12_Robot::go(const float rightJointVelocity, const float leftJointVelocity) {
    m_RightJoint->setTargetVelocity(rightJointVelocity);
    m_LeftJoint->setTargetVelocity(leftJointVelocity);
}

void DR12_Robot::goAhead(const float jointVelocity) {
    go(jointVelocity, jointVelocity);
}

void DR12_Robot::stop() {
    goAhead(0.0f);
}

std::tuple<float, float, float> DR12_Robot::orientation() const {
    simxFloat angles[3];
    simxInt ret = simxGetObjectOrientation(m_ClientId, m_Handle, -1, angles, simx_opmode_oneshot_wait);
    return std::make_tuple(angles[0], angles[1], angles[2]);
}

float DR12_Robot::relativeOrientationXY(const std::tuple<float, float> &point) const {
    float beta = 0;
    float myBeta = 0;

    auto myPosition = getGlobalPosition();
    auto myOrientation = orientation();

    float x = std::get<0>(point) - std::get<0>(myPosition);
    float y = std::get<1>(point) - std::get<1>(myPosition);

    if (x >= 0 && y >= 0) {
        beta = std::atan(x / y);
    }
    if (x < 0 && y >= 0) {
        beta = Utilities::PI - std::atan(x / y);
    }
    if (x < 0 && y < 0) {
        beta = Utilities::PI + std::atan(x / y);
    }
    if (x >= 0 && y < 0) {
        beta = 2 * Utilities::PI - std::atan(x / y);
    }

    myBeta = Utilities::orientationXY(myOrientation);

    return beta - myBeta;
}

void DR12_Robot::setOrientationXY(const float angle) {
    simxFloat angles[3];
    simxInt ret = simxGetObjectOrientation(m_ClientId, m_Handle, -1, angles, simx_opmode_oneshot_wait);
    if (angle >= 0 && angle < Utilities::PI / 2) {
        angles[0] = -std::abs(angles[0]);
        angles[1] = -angle;
        angles[2] = -std::abs(angles[2]);
    }
    if (angle >= Utilities::PI / 2 && angle < Utilities::PI) {
        angles[0] = std::abs(angles[0]);
        angles[1] = -(Utilities::PI - angle);
        angles[2] = std::abs(angles[2]);
    }
    if (angle >= Utilities::PI && angle < 3 * Utilities::PI / 2) {
        angles[0] = std::abs(angles[0]);
        angles[1] = Utilities::PI + angle;
        angles[2] = std::abs(angles[2]);
    }
    if (angle >= 3 * Utilities::PI / 2 && angle <= 2 * Utilities::PI) {
        angles[0] = -std::abs(angles[0]);
        angles[1] = 2 * Utilities::PI - angle;
        angles[2] = -std::abs(angles[2]);
    }
    ret = simxSetObjectOrientation(m_ClientId, m_Handle, -1, angles, simx_opmode_oneshot_wait);
    std::cout << "Orientation: " << ret << std::endl;
}
