#ifndef SOURCECURRENT_H
#define SOURCECURRENT_H
#include "SCHEME_H.h"
#include "Scheme/element.h"

class QImage;

class SourceCurrent : public Element
{
    Q_OBJECT;

public:
    SourceCurrent();

public slots:
    void setCurrency( float value);

private:
    float _current;
    QImage *_image;
};

#endif // SOURCECURRENT_H
