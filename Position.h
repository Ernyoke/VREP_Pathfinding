#ifndef POSITION_H
#define POSITION_H

struct Direction {
    inline Direction (int x, int y) : x {x}, y {y} {
    }
    int x, y;
};

class Position
{
public:
    Position (const unsigned int x, const unsigned int y);
    virtual ~Position ();
    
    unsigned int X() const;
    unsigned int Y() const;
    
    virtual Position go (const Direction dir) const;
    double distance (const Position other) const;
    
    bool operator != (const Position other) const {
        return m_X != other.X() || m_Y != other.Y();
    }
    
protected:
    unsigned int m_X, m_Y;
};

#endif // POSITION_H
