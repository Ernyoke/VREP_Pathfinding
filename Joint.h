#ifndef JOINT_H
#define JOINT_H

#include "Object.h"

class Joint : public Object
{
public:
    virtual ~Joint();
    
    static Joint* build(const ObjectBuilder& objectBuilder);
    
protected:
    Joint(const ObjectBuilder& objectBuilder);

};

#endif // JOINT_H
