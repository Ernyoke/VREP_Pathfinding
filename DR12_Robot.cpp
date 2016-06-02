#include <cmath>
#include <iostream>

#include "DR12_Robot.h"

constexpr float PI = 3.14159265;

DR12RobotBuilder::DR12RobotBuilder(simxInt clientId,
                                   simxInt handle,
                                   simxInt rightWheelHandle,
                                   simxInt leftWheelHandle,
                                   simxInt rightJointHandle,
                                   simxInt leftJointHandle)
    : RobotBuilder{ clientId, handle }
    , rightWheelHandle{ rightWheelHandle }
    , leftWheelHandle{ leftWheelHandle }
    , rightJointHandle{ rightJointHandle }
    , leftJointHandle{ leftJointHandle }

{
}

DR12_Robot* DR12_Robot::build(const DR12RobotBuilder& robotBuilder)
{
    DR12_Robot* dr12Unit = new DR12_Robot(robotBuilder);
    return dr12Unit;
}

DR12_Robot::DR12_Robot(const DR12RobotBuilder& robotBuilder)
    : Robot(robotBuilder)
{
    m_RightWheel = Wheel::build(ObjectBuilder{ m_ClientId, robotBuilder.rightWheelHandle });
    m_LeftWheel = Wheel::build(ObjectBuilder{ m_ClientId, robotBuilder.leftWheelHandle });
    m_RightJoint = Joint::build(ObjectBuilder{ m_ClientId, robotBuilder.rightJointHandle });
    m_LeftJoint = Joint::build(ObjectBuilder{ m_ClientId, robotBuilder.leftJointHandle });
}

DR12_Robot::~DR12_Robot()
{
    delete m_RightWheel;
    delete m_LeftWheel;
    delete m_RightJoint;
    delete m_LeftJoint;
}

float DR12_Robot::wheelDiameter() const
{
    return m_RightWheel->diameter();
}

float DR12_Robot::wheelDistance() const
{
    std::tuple<float, float, float> rightWheelPos = m_RightWheel->getGlobalPosition();
    std::tuple<float, float, float> leftWheelPos = m_LeftWheel->getGlobalPosition();

    float x = std::abs(std::get<0>(rightWheelPos) - std::get<0>(leftWheelPos));
    float y = std::abs(std::get<1>(rightWheelPos) - std::get<1>(leftWheelPos));

    return std::sqrt(x * x + y * y);
}

void DR12_Robot::followPath(const std::list<std::tuple<float, float, float> >& path)
{
    std::tuple<float, float, float> first = path.front();
    //float orient = relativeOrientationXY(std::make_tuple(std::get<0>(first), std::get<1>(first)));
    //float orient = relativeOrientationXY(std::make_tuple(-1.6211f, -0.625f));
//    std::cout << "Orientation for first: " << orient << std::endl;
    setOrientationXY(6);
    orientation();
}

std::tuple<float, float, float> DR12_Robot::orientation() const
{
    simxFloat angles[3];
    simxInt ret = simxGetObjectOrientation(m_ClientId, m_Handle, -1, angles, simx_opmode_oneshot_wait);
    std::cout << "Orientation: " << angles[0] << " " << angles[1] << " " << angles[2] << std::endl;
    return std::make_tuple(angles[0], angles[1], angles[2]);
}

float DR12_Robot::relativeOrientationXY(const std::tuple<float, float>& point) const
{
    float beta = 0;

    std::tuple<float, float, float> myPosition = getGlobalPosition();
    float x = std::get<0>(point) - std::get<0>(myPosition);
    float y = std::get<1>(point) - std::get<1>(myPosition);

    if(x >= 0 && y >= 0) {
        beta = std::atan(x / y);
    }
    if(x < 0 && y >= 0) {
        beta = PI - std::atan(x / y);
    }
    if(x < 0 && y < 0) {
        beta = PI + std::atan(x / y);
    }
    if(x >= 0 && y < 0) {
        beta = 2 * PI - std::atan(x / y);
    }

    return beta;
}

void DR12_Robot::setOrientationXY(const float angle)
{
    simxFloat angles[3];
    simxInt ret = simxGetObjectOrientation(m_ClientId, m_Handle, -1, angles, simx_opmode_oneshot_wait);
    if(angle >= 0 && angle < PI / 2) {
        angles[0] = -std::abs(angles[0]);
        angles[1] = -angle;
        angles[2] = -std::abs(angles[2]);
    }
    if(angle >= PI / 2 && angle < PI) {
        angles[0] = std::abs(angles[0]);
        angles[1] = -(PI - angle);
        angles[2] = std::abs(angles[2]);
    }
    if(angle >= PI && angle < 3 * PI / 2) {
        angles[0] = std::abs(angles[0]);
        angles[1] = PI + angle;
        angles[2] = std::abs(angles[2]);
    }
    if(angle >= 3 * PI / 2 && angle <= 2 * PI) {
        angles[0] = -std::abs(angles[0]);
        angles[1] = 2 * PI - angle;
        angles[2] = -std::abs(angles[2]);
    }
    ret = simxSetObjectOrientation(m_ClientId, m_Handle, -1, angles, simx_opmode_oneshot_wait);
    std::cout << "Orientation: " << ret << std::endl;
}
