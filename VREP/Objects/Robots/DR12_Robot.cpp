#include <cmath>
#include <iostream>
#include <thread>

#include "DR12_Robot.h"
#include "../../../Utilities/Utilities.h"
#include "../../Exceptions/ReturnCodesExceptions.h"

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
    try {
        return m_RightWheel->diameter();
    }
    catch (ReturnCodesExceptions *ex) {
        throw ex;
    }
}

float DR12_Robot::wheelDistance() const {
    try {
        std::tuple<float, float, float> rightWheelPos = m_RightWheel->globalPosition();
        std::tuple<float, float, float> leftWheelPos = m_LeftWheel->globalPosition();

        return Utilities::distance(std::make_tuple(std::get<0>(rightWheelPos), std::get<1>(rightWheelPos)),
                                   std::make_tuple(std::get<0>(leftWheelPos), std::get<1>(leftWheelPos)));
    }
    catch (ReturnCodesExceptions *ex) {
        throw ex;
    }
}

void DR12_Robot::followPath(const std::vector<std::tuple<float, float, float> > &path) {
    float speed = 0.2;
    float rotationSpeed = 0.4;
    float d = wheelDistance();
    float speedRight = 0;
    float speedLeft = 0;
    float r = wheelDiameter() / 2;
    float omagaRight = 0;
    float omagaLeft = 0;
    float orientation = 0;

    float error = 0.2;

    bool stop = false;
    int i = 50;

    while (!stop) {
        auto pathPoint = path.at(i);
        auto position = globalPosition();
        orientation = relativeOrientationXY(std::make_tuple(std::get<0>(pathPoint), std::get<1>(pathPoint)));
        speedRight = speed + d * rotationSpeed * orientation;
        speedLeft = speed - d * rotationSpeed * orientation;
        omagaRight = speedRight / r;
        omagaLeft = speedLeft / r;
        go(omagaRight, omagaLeft);
        float distance = Utilities::distance(std::make_tuple(std::get<0>(position), std::get<1>(position)),
                                             std::make_tuple(std::get<0>(pathPoint), std::get<1>(pathPoint)));

        if (std::abs(distance) <= error + error) {
            i += 30;
        }

        if (i >= path.size()) {
            stop = true;
        }

//        std::cout << "Distance: " << distance << std::endl;
//        std::cout << "Orientation: " << orientation << std::endl;
//        std::cout << "My position: " << std::get<0>(position) << " " << std::get<1>(position) << std::endl;
//        std::cout << "Path position: " << std::get<0>(pathPoint) << " " << std::get<1>(pathPoint) << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    this->stop();
}

void DR12_Robot::followPathDummy(const std::vector<std::tuple<float, float, float> > &path) {
    Object *dummy = parent();
    for (auto it : path) {
        auto robotPosition = globalPosition();
        auto dummyPosition = std::make_tuple(std::get<0>(it), std::get<1>(it), std::get<2>(robotPosition));
        dummy->setGlobalPosition(dummyPosition);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void DR12_Robot::go(const float rightJointVelocity, const float leftJointVelocity) {
    try {
        m_RightJoint->setTargetVelocity(rightJointVelocity);
        m_LeftJoint->setTargetVelocity(leftJointVelocity);
    }
    catch (ReturnCodesExceptions *ex) {
        delete ex;
    }
}

void DR12_Robot::goAhead(const float jointVelocity) {
    try {
        go(jointVelocity, jointVelocity);
    }
    catch (ReturnCodesExceptions *ex) {
        delete ex;
    }
}

void DR12_Robot::stop() {
    try {
        goAhead(0.0f);
    }
    catch (ReturnCodesExceptions *ex) {
        delete ex;
    }
}

std::tuple<float, float, float> DR12_Robot::orientation() const {
    try {
        simxFloat angles[3];
        ReturnCodesExceptions::handleReturnCode(
            simxGetObjectOrientation(m_ClientId, m_Handle, -1, angles, simx_opmode_oneshot_wait));
        return std::make_tuple(angles[0], angles[1], angles[2]);
    }
    catch (ReturnCodesExceptions *ex) {
        throw ex;
    }
}

float DR12_Robot::relativeOrientationXY(const std::tuple<float, float> &point) const {
    try {
        float beta = 0;
        float myBeta = 0;

        auto myPosition = globalPosition();
        auto myOrientation = orientation();

        float x = std::get<0>(point) - std::get<0>(myPosition);
        float y = std::get<1>(point) - std::get<1>(myPosition);

        //std::cout << "x: "  << x << " y: " << y << " x/y: " << x / y << std::endl;
        //std::cout << "atan: " << std::atan(x / y) << std::endl;

        if (x > 0 && y < 0) {
            beta = std::atan(x / y);
        }
        if (x > 0 && y > 0) {
            beta = Utilities::PI - std::atan(x / y);
        }
        if (x < 0 && y > 0) {
            beta = Utilities::PI + std::atan(x / y);
        }
        if (x < 0 && y < 0) {
            beta = 2 * Utilities::PI - std::atan(x / y);
        }

        myBeta = Utilities::orientationXY(myOrientation);

        return beta - myBeta;
    }
    catch (ReturnCodesExceptions *ex) {
        throw ex;
    }
}

void DR12_Robot::setOrientationXY(const float angle) {
    simxFloat angles[3];
    try {
        ReturnCodesExceptions::handleReturnCode(
            simxGetObjectOrientation(m_ClientId, m_Handle, -1, angles, simx_opmode_oneshot_wait));

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

    }
    catch (ReturnCodesExceptions *ex) {
        throw ex;
    }
}
