#include "ConnectionErrorException.h"

ConnectionErrorException::ConnectionErrorException(const char* msg) throw()
    : m_message{ msg }
    , m_errorNumber{ 0 }
{
}

ConnectionErrorException::ConnectionErrorException(const std::string& message) throw()
    : m_message{ message }
    , m_errorNumber{ 0 }
{
}

ConnectionErrorException::ConnectionErrorException(const int errorNr) throw()
    : m_errorNumber{ errorNr }
{
}

ConnectionErrorException::ConnectionErrorException(const char* msg, const int errorNr) throw()
    : m_message{ msg }
    , m_errorNumber{ errorNr }
{
}

ConnectionErrorException::ConnectionErrorException(const std::string& message, const int errorNr) throw()
    : m_message{ message }
    , m_errorNumber{ errorNr }
{
}

ConnectionErrorException::~ConnectionErrorException() throw()
{
}

const char* ConnectionErrorException::what() const throw()
{
    return m_message.c_str();
}
