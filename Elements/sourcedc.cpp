#include "sourcedc.h"

SourceDC::SourceDC()
{
    _image = new QImage(SOURCEDC_IMAGE_PATH);
}

void SourceDC::setVoltage(float value)
{
    _dc = value;
}
