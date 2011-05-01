#pragma once
#include "HEAD.h"
#include "Matrix.h"
#include "Graph.h"

class MNP
{
public:
	MNP(void);
	MNP(Graph scheme, vector<resistance_t> r, vector<voltage_t> e, vector<amperage_t> j);
	~MNP(void);
	vector<double> computing(void);
	vector<double> getResult(void);
	void inputConditions(Graph scheme, vector<resistance_t> r, vector<voltage_t> e, vector<amperage_t> j);

private:
	void initMNPMatrix(Graph scheme);
	_index findBasicNode(Graph scheme);

	Matrix<double> _R;
	Matrix<double> _E;
	Matrix<double> _J;
	Matrix<double> _mnpMatrix;
	vector<double> _result;  /* currents of the branches */ ///?
};