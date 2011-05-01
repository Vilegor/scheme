#include "branch.h"

Branch::Branch(size_t start, size_t end)
{
    _se.setStart(start);
    _se.setEnd(end);
}

void Branch::addElement(Element *newElement)
{
    _elements.insert(_elements.end(), newElement);
}

QVector< Element *> Branch::getElements()
{
    return _elements;
}

