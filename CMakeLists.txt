cmake_minimum_required(VERSION 3.5)
project(VREP_PathFinding)

set(OpenCV_FOUND 1)
find_package(OpenCV REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp
        PathFinding/A_Star/A_StarPath.cpp
        PathFinding/A_Star/A_StarPath.h
        Bridge.cpp
        Bridge.h
        VREP/ConnectionErrorException.cpp
        VREP/ConnectionErrorException.h
        VREP/Objects/Robots/DR12_Robot.h
        VREP/Objects/Robots/DR12_Robot.cpp
        PathFinding/HistoricalPosition.cpp
        PathFinding/HistoricalPosition.h
        VREP/Objects/Robots/Parts/Joint.cpp
        VREP/Objects/Robots/Parts/Joint.h
        PathFinding/NoPathException.cpp
        PathFinding/NoPathException.h
        VREP/Objects/Object.cpp
        VREP/Objects/Object.h
        PathFinding/OutOfBoundException.cpp
        PathFinding/OutOfBoundException.h
        PathFinding/PathInterface.cpp
        PathFinding/PathInterface.h
        PathFinding/Playground.cpp
        PathFinding/Playground.h
        PathFinding/Position.cpp
        PathFinding/Position.h
        VREP/Objects/Robot.cpp
        VREP/Objects/Robot.h
        VREP/Objects/Sensor.cpp
        VREP/Objects/Sensor.h
        VREP/Objects/Sensors/VisionSensor.cpp
        VREP/Objects/Sensors/VisionSensor.h
        VREP/VRepApi.cpp
        VREP/VRepApi.h
        VREP/Objects/Robots/Parts/Wheel.cpp
        VREP/Objects/Robots/Parts/Wheel.h
        remoteApi/extApi.c
        remoteApi/extApi.h
        remoteApi/extApiInternal.h
        remoteApi/extApiPlatform.c
        remoteApi/extApi.h
        remoteApi/v_repConst.h
        remoteApi/v_repLib.h
        remoteApi/v_repTypes.h Utilities/Utilities.cpp Utilities/Utilities.h)

add_executable(VREP_PathFinding ${SOURCE_FILES})

add_definitions(-DNON_MATLAB_PARSING -DMAX_EXT_API_CONNECTIONS=255)
target_link_libraries(VREP_PathFinding pthread ${OpenCV_LIBS})