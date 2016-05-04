#ifndef VREPAPI_H
#define VREPAPI_H

#include <string>
#include <exception>
#include "ConnectionErrorException.h"

extern "C" {
#include "remoteApi/extApi.h"
}

using HANDLE = simxInt;

class VRepApi
{
public:
    VRepApi();
    virtual ~VRepApi();

    simxInt m_clientId;

    void connect(const std::string& ipAddress,
                 const unsigned short port,
                 const bool isBlocking,
                 const bool doNotDiscoonect,
                 const int timeOut,
                 const int commThreadCycleInMs = 5);

    HANDLE getObjectHandle(const std::string objectName) const;
};

#endif // VREPAPI_H
