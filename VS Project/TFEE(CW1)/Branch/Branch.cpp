#include "Branch.h"
#include "Resistor.h"
#include "SourceDC.h"
#include "SourceCurrent.h"


Branch::Branch(void)
{
}

Branch::Branch( size_t id, resistance_t r, voltage_t e, amperage_t i, StartEnd se )
{
	_branchNum = id;

	if( r != 0){
		Resistor *buf = new Resistor(r);
		_elements.insert(_elements.end(), buf);
//		cout << typeid(*_elements[0]).name()<<endl;
	}
	if(e != 0){
		SourceDC *buf = new SourceDC(e);
		_elements.insert(_elements.end(),buf);
//		cout << typeid(*_elements[1]).name()<<endl;
	}
	if(i != 0){
		SourceCurrent *buf = new SourceCurrent(i);
		_elements.insert(_elements.end(), buf);
//		cout << typeid(*_elements[1]).name()<<endl;
	}
	_se = se;

}


Branch::~Branch(void)
{
}

_index Branch::getStartNode(){
	return _se.start;
}

_index Branch::getEndNode(){
	return _se.end;
}

_index Branch::getBranchNum( void )
{
	return _branchNum;
}