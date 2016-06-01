#ifndef DR12_ROBOT_H
#define DR12_ROBOT_H

#include <tuple>
#include <list>

#include "Robot.h"
#include "Wheel.h"
#include "Joint.h"

struct DR12RobotBuilder : public RobotBuilder
{

    DR12RobotBuilder(simxInt clientId,
                     simxInt handle,
                     simxInt rightWheelHandle,
                     simxInt leftWheelHandle,
                     simxInt rightJointHandle,
                     simxInt leftJointHandle);

    simxInt rightWheelHandle;
    simxInt leftWheelHandle;
    simxInt rightJointHandle;
    simxInt leftJointHandle;
};

class DR12_Robot : public Robot
{
public:
    virtual ~DR12_Robot();

    static DR12_Robot* build(const DR12RobotBuilder& sensorBuilder);

    float wheelDiameter() const;
    float wheelDistance() const;
    
    void followPath(const std::list< std::tuple<float, float, float> >& path) const;
    
    void setOrientationXY(const float grades);

protected:
    DR12_Robot(const DR12RobotBuilder& robotBuilder);

    Wheel* m_RightWheel;
    Wheel* m_LeftWheel;
    Joint* m_RightJoint;
    Joint* m_LeftJoint;
};

#endif // DR12_ROBOT_H
