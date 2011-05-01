#ifndef BRANCH_H
#define BRANCH_H
#include "SCHEME_H.h"
<<<<<<< HEAD
#include "Elements/startendpoint.h"
#include "Elements/element.h"
=======
#include "Scheme/element.h"
>>>>>>> 772125f35267f41c19e08e1a3478325ceef8d322

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
