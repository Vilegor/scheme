#ifndef SOURCEDC_H
#define SOURCEDC_H
#include "SCHEME_H.h"
#include "Scheme/element.h"

class QImage;

class SourceDC : public Element
{
    Q_OBJECT;

public:
    SourceDC();

public slots:
    void setVoltage( float value);

private:
    float _dc;
    QImage *_image;
};

#endif // SOURCEDC_H
