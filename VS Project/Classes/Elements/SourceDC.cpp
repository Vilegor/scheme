#include "SourceDC.h"


SourceDC::SourceDC(void)
{
}

SourceDC::SourceDC( voltage_t voltage ){
	_voltage = voltage;
}


SourceDC::~SourceDC(void)
{
}

int SourceDC::getType(){
	return SOURCE_DC;
}

int SourceDC::getValue(){
	return _voltage;
}
