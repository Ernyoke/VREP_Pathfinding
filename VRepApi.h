#ifndef VREPAPI_H
#define VREPAPI_H

#include <string>
#include <exception>

extern "C" {
#include "remoteApi/extApi.h"
}

using HANDLE = simxInt;

class ConnectionErrorException : public std::exception
{
protected:
    std::string m_message;
    int m_errorNumber;

public:
    explicit ConnectionErrorException(const char* msg)
        : m_message{ msg }
        , m_errorNumber{ 0 }
    {
    }
    explicit ConnectionErrorException(const std::string& message)
        : m_message{ message }
        , m_errorNumber{ 0 }
    {
    }
    explicit ConnectionErrorException(const int errorNr)
        : m_errorNumber{ errorNr }
    {
    }
    explicit ConnectionErrorException(const char* msg, const int errorNr)
        : m_message{ msg }
        , m_errorNumber{ errorNr }
    {
    }
    explicit ConnectionErrorException(const std::string& message, const int errorNr)
        : m_message{ message }
        , m_errorNumber{ errorNr }
    {
    }

    virtual ~ConnectionErrorException() throw()
    {
    }

    virtual const char* what() const throw()
    {
        return m_message.c_str();
    }
};

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
