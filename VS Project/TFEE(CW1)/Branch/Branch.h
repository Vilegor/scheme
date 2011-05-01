#pragma once
#include "Element.h"
#include "HEAD.h"

struct ElementsBitMask{
	unsigned resistance : 1;	
	unsigned voltage : 2;
	unsigned amperage : 2;
};

class Branch
{
public:
	Branch(void);
	Branch(
		size_t id,
		resistance_t r,
		voltage_t e,
		amperage_t i,
		StartEnd se
		);
	~Branch(void);

	void addElement();
	_index getStartNode();
	_index getEndNode();
	_index getBranchNum(void);

private:

	ElementsBitMask _elementExistance;
	_index _branchNum;
	StartEnd _se;
	vector <Element*> _elements;

/*
	void _setResistancePresence();

	void _setDCDirectPresence();
	void _setDCParallelPresence();

	void _setCurrentParallelPresence();
	void _setCurrentDirectPresence();*/

};

