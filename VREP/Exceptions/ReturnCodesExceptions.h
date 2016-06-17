//
// Created by ervin on 16.06.2016.
//

#ifndef VREP_PATHFINDING_RETURNCODESEXCEPTIONS_H
#define VREP_PATHFINDING_RETURNCODESEXCEPTIONS_H


#include <map>
#include <exception>

#include <boost/numeric/ublas/vector.hpp>

class ReturnCodesExceptions : public std::exception {
protected:
    int m_ReturnCode;
    static const std::map<int, std::string> errorMessager;
    std::vector<std::string> notes;

public:
    explicit ReturnCodesExceptions(const int returnCode) throw();
    ~ReturnCodesExceptions();

    virtual const char *what() const throw();

    static void handleReturnCode(const int code);

    void addNote(const std::string& note);

};


#endif //VREP_PATHFINDING_RETURNCODESEXCEPTIONS_H
