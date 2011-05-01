#include "SourceCurrent.h"


SourceCurrent::SourceCurrent(void){
}

SourceCurrent::SourceCurrent( amperage_t amperage ){
	_amperage = amperage;
}


SourceCurrent::~SourceCurrent(void)
{
}

int SourceCurrent::getType(){
	return SOURCE_CURRENT;
}

int SourceCurrent::getValue(){
	return _amperage;
}
