#include "capacity.h"

Capacity::Capacity()
{
    _image = new QImage(CAPACITY_IMAGE_PATH);
}

void Capacity::setCapacity(float value){
    _capacity = value;

}
