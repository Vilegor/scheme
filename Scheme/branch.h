#ifndef BRANCH_H
#define BRANCH_H
#include "SCHEME_H.h"
#include "Elements/startendpoint.h"
#include "Scheme/element.h"

class Branch
{
public:
    Branch(size_t start, size_t end);

public slots:
    void addElement( Element* newElement);
    QVector<Element*> getElements();

private:
    size_t _id;
    StartEndPoint _se;
    QVector<Element*> _elements;
};

#endif // BRANCH_H
