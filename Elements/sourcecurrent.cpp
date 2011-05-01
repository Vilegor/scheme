#include "sourcecurrent.h"

SourceCurrent::SourceCurrent()
{
    _image = new QImage(SOURCE_CURRENT_IMAGE_PATH);
}

void SourceCurrent::setCurrency(float value)
{
    _current = value;
}
