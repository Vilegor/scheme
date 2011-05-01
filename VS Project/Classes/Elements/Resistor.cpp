#include "Resistor.h"


Resistor::Resistor(void){
}

Resistor::Resistor( resistance_t resistance ){
	_resistance = resistance;
}


Resistor::~Resistor(void)
{
}

int Resistor::getType(){
	return RESISTANCE;
}

int Resistor::getValue(){
	return _resistance;
}
