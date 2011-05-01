#include "Capacity.h"


Capacity::Capacity(void){
}

Capacity::Capacity( capacity_t capacity ){
	_capacity = capacity;
}


Capacity::~Capacity(void)
{
}

int Capacity::getType(){
	return CAPACITY;
}

int Capacity::getValue(){
	return _capacity;
}
