#ifndef ELEMENT_H
#define ELEMENT_H

#include "SCHEME_H.h"

class Element : public QObject
{
    Q_OBJECT
public:
    Element(void) {};
    virtual ~Element() {};
};

#endif // ELEMENT_H
