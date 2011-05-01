#include "Inductance.h"


Inductance::Inductance(void)
{
}

Inductance::Inductance( inductance_t inductance ){
	_inductance = inductance;
}


Inductance::~Inductance(void)
{
}

int Inductance::getType(){
	return INDUCTANCE;
}

int Inductance::getValue(){
	return _inductance;
}
