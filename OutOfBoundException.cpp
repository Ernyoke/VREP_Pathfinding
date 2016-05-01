#include "OutOfBoundException.h"

OutOfBoundException::OutOfBoundException(const std::string message)
    : m_Msg{ message }
{
}

OutOfBoundException::~OutOfBoundException()
{
}
