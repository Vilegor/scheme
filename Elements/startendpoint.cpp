#include "startendpoint.h"

StartEndPoint::StartEndPoint()
{
}

size_t StartEndPoint::getStart()
{
    return _start;
}

size_t StartEndPoint::getEnd()
{
    return _end;
}

void StartEndPoint::setStart(size_t s)
{
    _start = s;
}

void StartEndPoint::setEnd(size_t e)
{
    _end = e;
}
