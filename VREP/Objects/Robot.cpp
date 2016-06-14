#include "Robot.h"

RobotBuilder::RobotBuilder(simxInt clientId, simxInt handle) : ObjectBuilder{clientId, handle} {
}

Robot::Robot(const RobotBuilder &robotBuilder)
        : Object(robotBuilder) {
}

Robot::~Robot() {
}
