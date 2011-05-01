#include "elementfactory.h"

ElementFactory::ElementFactory()
{

}

Element * ElementFactory::createElement(size_t type)
{
    switch(type){
    case RESISTANCE: return new Resistance;
    case INDUCTANCE: return new Inductance;
    case CAPACITY: return new Capacity;
    case SOURCE_DC: return new SourceDC;
    case SOURCE_CURRENT: return new SourceCurrent;
    default: return NULL;
    }
}
