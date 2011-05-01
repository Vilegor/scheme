#include "Student.h"


Student::Student(void)
{
}

Student::Student( 
	size_t id, 
	vector<StartEnd>* se, 
	vector<StartEnd>* uNN, 
	vector<resistance_t>* resistance, 
	vector<voltage_t>* voltage, 
	vector<amperage_t>* amperage,
	vector<size_t>* meg
	){
		for(int i = 0; i < BRANCH_COUNT; i++){
			_id = id;
			_r.insert(_r.end(),*resistance->begin());
			resistance->erase(resistance->begin());
			_e.insert(_e.end(),*voltage->begin());
			voltage->erase(voltage->begin());
			_i.insert(_i.end(),*amperage->begin());
			amperage->erase(amperage->begin());
			_se.insert(_se.end(),*se->begin());
			se->erase(se->begin());
		}
		_uNN.insert(_uNN.end(),*uNN->begin());
		uNN->erase(uNN->begin());
		_meg.insert(_meg.end(), *meg->begin());
		meg->erase(meg->begin());

}


Student::~Student(void)
{
}

void Student::initGraph(){
	for(int i = 0; i < BRANCH_COUNT; i++){
		_scheme.addBranch(i + 1, _r[i], _e[i], _i[i], _se[i]);
	}
	_scheme.initMatrix();
}

_testing vector<resistance_t> Student::getResistance(){
	return _r;
}

_testing void Student::checkGraph( void )
{
	_scheme.print();
}

_testing void Student::reportComposing( void )
{
	_methodOfNodalPotentials.inputConditions(_scheme, _r, _e, _i);
	_methodOfNodalPotentials.computing();
}
