#ifndef HISTORICALPOSITION_H
#define HISTORICALPOSITION_H

#include "Position.h"

class HistoricalPosition : public Position {
public:
    HistoricalPosition(unsigned int x, unsigned int y, unsigned int step = 0);

    HistoricalPosition(const Position &p, unsigned int step = 0);

    virtual ~HistoricalPosition();

    void setStep(const unsigned int step);

    unsigned step() const;

    void setPreviousPosition(const HistoricalPosition &prevPosition);

    const HistoricalPosition *getPrevoiusPosition() const;

    virtual HistoricalPosition go(const Direction dir);

private:
    unsigned int m_Step;
    HistoricalPosition *m_PrevPosition;
};

#endif // HISTORICALPOSITION_H
