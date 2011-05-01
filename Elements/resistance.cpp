#include "resistance.h"

Resistance::Resistance()
{
    _image = new QImage(RESISTOR_IMAGE_PATH);
}

void Resistance::setResistance(float value)
{
    _resistance = value;
}
