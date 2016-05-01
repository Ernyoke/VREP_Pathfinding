#ifndef OUTOFBOUNDEXCEPTION_H
#define OUTOFBOUNDEXCEPTION_H

#include <exception>
#include <string>

class OutOfBoundException : public std::exception
{
public:
    explicit OutOfBoundException(const std::string message);
    virtual ~OutOfBoundException();

    virtual const char* what() const throw()
    {
        return m_Msg.c_str();
    }

private:
    std::string m_Msg;
};

#endif // OUTOFBOUNDEXCEPTION_H
