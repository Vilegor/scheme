#ifndef INDUCTANCE_H
#define INDUCTANCE_H
#include "Scheme/element.h"

class QImage;

class Inductance : public Element
{
    Q_OBJECT;

public:
    Inductance();

public slots:
    void setInductance( float value);

protected:

    float _inductance;
    QImage *_image;

};

#endif // INDUCTANCE_H
