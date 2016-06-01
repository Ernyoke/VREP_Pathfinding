#include <cmath>

#include "DR12_Robot.h"

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

void DR12_Robot::followPath(const std::list<std::tuple<float, float, float> >& path) const
{
    // TODO
}

void DR12_Robot::setOrientationXY(const float grades)
{
    float alfa = 0;
    float beta = 0;
    float gamma = 0;
    if(grades >= 0 && grades < 90) {
        alfa = -90;
        beta = grades;
        gamma = -90;
    }
    if(grades >= 90 && grades < 270) {
        alfa = 90;
        beta = 180 - grades;
        gamma = 90;
    }
    if(grades >= 270 && grades < 360) {
        alfa = -90;
        beta = 270 - grades;
        gamma = -90;
    }
    float* gradeArray = new float[3];
    gradeArray[0] = alfa;
    gradeArray[1] = beta;
    gradeArray[2] = gamma;
    simxGetObjectOrientation(m_ClientId, m_Handle, -1, gradeArray, simx_opmode_oneshot);
}
