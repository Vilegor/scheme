#ifndef STARTENDPOINT_H
#define STARTENDPOINT_H
#include "SCHEME_H.h"

class StartEndPoint
{
public:
    StartEndPoint();

public slots:
    size_t getStart();
    size_t getEnd();
    void setStart(size_t s);
    void setEnd(size_t e);

private:
    size_t _start;
    size_t _end;
};

#endif // STARTENDPOINT_H
