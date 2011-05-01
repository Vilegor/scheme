#include "inductance.h"

Inductance::Inductance()
{
    _image = new QImage(INDUCTANCE_IMAGE_PATH);
}

void Inductance::setInductance(float value)
{
    _inductance = value;

}
