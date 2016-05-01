#ifndef NOPATHEXCEPTION_H
#define NOPATHEXCEPTION_H

#include <exception>
#include <string>

class NoPathException
{
public:
    explicit NoPathException(const std::string message);
    virtual ~NoPathException();

    virtual const char* what() const throw()
    {
        return m_Msg.c_str();
    }

private:
    std::string m_Msg;
};

#endif // NOPATHEXCEPTION_H
