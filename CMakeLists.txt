cmake_minimum_required(VERSION 3.5)
project(VREP_PathFinding)

set(OpenCV_FOUND 1)
find_package(OpenCV REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp A_StarPath.cpp A_StarPath.h Bridge.cpp Bridge.h ConnectionErrorException.cpp ConnectionErrorException.h
        DR12_Robot.h DR12_Robot.cpp HistoricalPosition.cpp HistoricalPosition.h Joint.cpp Joint.h NoPathException.cpp
        NoPathException.h Object.cpp Object.h OutOfBoundException.cpp OutOfBoundException.h PathInterface.cpp PathInterface.h
        Playground.cpp Playground.h Position.cpp Position.h Robot.cpp Robot.h Sensor.cpp Sensor.h VisionSensor.cpp VisionSensor.h
        VRepApi.cpp VRepApi.h Wheel.cpp Wheel.h remoteApi/extApi.c remoteApi/extApi.h remoteApi/extApiInternal.h remoteApi/extApiPlatform.c
        remoteApi/extApi.h remoteApi/v_repConst.h remoteApi/v_repLib.h remoteApi/v_repTypes.h)
add_executable(VREP_PathFinding ${SOURCE_FILES})
add_definitions(-DNON_MATLAB_PARSING -DMAX_EXT_API_CONNECTIONS=255)
target_link_libraries(VREP_PathFinding pthread ${OpenCV_LIBS})