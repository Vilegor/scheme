#ifndef RESISTANCE_H
#define RESISTANCE_H
#include "SCHEME_H.h"
#include "Scheme/element.h"

class QImage;

class Resistance : public Element
{
    Q_OBJECT;

public:
    Resistance();
    ~Resistance(){ };

public slots:
    void setResistance(float value);

protected:

private:
    float _resistance;
    QImage *_image;

};

#endif // RESISTANCE_H
