#pragma once
#include "HEAD.h"
#include "Graph.h"
#include "FileReader.h"
#include "MCC.h"
#include "MKE.h"
#include "MNP.h"

class Student
{
public:
	Student(void);
	Student(
		size_t id,
		vector<StartEnd>* se,
		vector<StartEnd>* uNN,
		vector<resistance_t>* resistance,
		vector<voltage_t>* voltage,
		vector<amperage_t>* amperage,
		vector<size_t>* meg
		);
	~Student(void);
	void initGraph();
	
	_testing void checkGraph(void);
	_testing vector<resistance_t> getResistance();
	_testing void reportComposing(void);

private:
	size_t _id;
	vector<resistance_t> _r;
	vector<voltage_t> _e;
	vector<amperage_t> _i;
	vector<StartEnd> _uNN;
	vector<StartEnd> _se;
	vector<size_t> _meg;

	Graph _scheme;

	MCC _methodOfContourCurrents;
	MKE _methodOfKirchhoffEquations;
	MNP _methodOfNodalPotentials;
};

