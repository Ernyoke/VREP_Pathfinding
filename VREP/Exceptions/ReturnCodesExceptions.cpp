//
// Created by ervin on 16.06.2016.
//

#include "ReturnCodesExceptions.h"

const std::map<int, std::string> ReturnCodesExceptions::errorMessager =
    {{0,  "No error!"},
     {1,  "There is no command reply in the input buffer. This should not always be considered as an error!"},
     {2,  "Network timed out!"},
     {4,  "The specified operation mode is not supported!"},
     {8,  "The function caused an error on the server side!"},
     {16, "The communication thread is still processing previous split command of the same type!"},
     {32, "The function caused an error on the client side!"},
     {64, "simxStart was not yet called!"}
    };

void ReturnCodesExceptions::handleReturnCode(const int code) {
    if (code != 0) {
        throw new ReturnCodesExceptions(code);
    }
}

void ReturnCodesExceptions::handleReturnCodeNoResponse(const int code) {
    if (code != 0 && code != 1) {
        throw new ReturnCodesExceptions(code);
    }
}

ReturnCodesExceptions::ReturnCodesExceptions(const int returnCode) throw() : m_ReturnCode{returnCode} {
}

ReturnCodesExceptions::~ReturnCodesExceptions() {
}

const char *ReturnCodesExceptions::what() const throw() {
    return errorMessager.at(m_ReturnCode).c_str();
}

void ReturnCodesExceptions::addNote(const std::string &note) {
    notes.push_back(note);
}
