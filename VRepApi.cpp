#include "VRepApi.h"

VRepApi::VRepApi()
    : m_clientId{ 0 }
{
}

VRepApi::~VRepApi()
{
}

void VRepApi::connect(const std::string& ipAddress,
                      const unsigned short port,
                      const bool isBlocking,
                      const bool doNotDiscoonect,
                      const int timeOut,
                      const int commThreadCycleInMs)
{
    simxInt clientID = simxStart(
        const_cast<simxChar*>(ipAddress.c_str()), port, isBlocking, doNotDiscoonect, timeOut, commThreadCycleInMs);
    if(clientID < 0) {
        throw new ConnectionErrorException("Could not connect to the server!", clientID);
    } else {
        m_clientId = clientID;
    }
}

HANDLE VRepApi::getObjectHandle(const std::string objectName) const
{
    HANDLE handle = 0;
    simxGetObjectHandle(m_clientId, const_cast<simxChar*>(objectName.c_str()), &handle, simx_opmode_oneshot_wait);
    return handle;
}