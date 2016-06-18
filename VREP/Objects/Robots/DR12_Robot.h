#ifndef DR12_ROBOT_H
#define DR12_ROBOT_H

#include <tuple>
#include <vector>

#include "../Robot.h"
#include "Parts/Wheel.h"
#include "Parts/Joint.h"

struct DR12RobotBuilder : public RobotBuilder {

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

class DR12_Robot : public Robot {
public:
    static DR12_Robot *build(const DR12RobotBuilder &sensorBuilder);

    virtual ~DR12_Robot();

    float wheelDiameter() const;

    float wheelDistance() const;

    void followPath(const std::vector<std::tuple<float, float, float> > &path);

    void followPathDummy(const std::vector<std::tuple<float, float, float> > &path);

    std::tuple<float, float, float> orientation() const;

    float relativeOrientationXY(const std::tuple<float, float> &point) const;

    void setOrientationXY(const float angle);

    void go(const float rightJointVelocity, const float leftJointVelocity);

    void goAhead(const float jointVelocity);

    void stop();


protected:
    DR12_Robot(const DR12RobotBuilder &robotBuilder);

    Wheel *m_RightWheel;
    Wheel *m_LeftWheel;
    Joint *m_RightJoint;
    Joint *m_LeftJoint;
};

#endif // DR12_ROBOT_H
