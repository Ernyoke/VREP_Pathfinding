#ifndef CONNECTIONERROREXCEPTION_H
#define CONNECTIONERROREXCEPTION_H

#include <string>

class ConnectionErrorException
{

protected:
    std::string m_message;
    int m_errorNumber;

public:
    explicit ConnectionErrorException(const char* msg) throw();
    ConnectionErrorException(const std::string& message) throw();
    ConnectionErrorException(const int errorNr) throw();
    ConnectionErrorException(const char* msg, const int errorNr) throw();
    ConnectionErrorException(const std::string& message, const int errorNr) throw();
    virtual ~ConnectionErrorException() throw();
    
    virtual const char* what() const throw();
    
};

#endif // CONNECTIONERROREXCEPTION_H
