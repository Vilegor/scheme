#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H
#include "resistance.h"
#include "capacity.h"
#include "inductance.h"
#include "sourcecurrent.h"
#include "sourcedc.h"


class ElementFactory : public QObject
{
    Q_OBJECT;

public:
    ElementFactory();

public slots:
    Element* createElement(size_t type);

private:

};

#endif // ELEMENTFACTORY_H
