#ifndef CAPACITY_H
#define CAPACITY_H

#include "Scheme/element.h"
#include <QImage>

class Image;

class Capacity : public Element
{
    Q_OBJECT;

public:
    Capacity();

public slots:
    void setCapacity( float value);

protected:

private:

    float _capacity;
    QImage *_image;

};

#endif // CAPACITY_H
