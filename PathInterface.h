#ifndef PATHINTERFACE_H
#define PATHINTERFACE_H

class PathInterface
{
public:
    PathInterface();
    virtual ~PathInterface();

    virtual void path() = 0;
};

#endif // PATHINTERFACE_H
