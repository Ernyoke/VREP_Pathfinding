#include "NoPathException.h"

NoPathException::NoPathException(const std::string message)
        : m_Msg(message) {
}

NoPathException::~NoPathException() {
}
