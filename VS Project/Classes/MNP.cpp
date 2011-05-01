#include "MNP.h"


MNP::MNP(void)
{
	_mnpMatrix.resize(BRANCH_COUNT, NODE_COUNT - 1);
	_R.resize(1, BRANCH_COUNT);
	_E.resize(1, BRANCH_COUNT);
	_J.resize(1, BRANCH_COUNT);
}


MNP::MNP(Graph scheme, vector<resistance_t> r, vector<voltage_t> e, vector<amperage_t> j)
{
	_mnpMatrix.resize(BRANCH_COUNT, NODE_COUNT - 1);
	_R.resize(1, BRANCH_COUNT);
	_E.resize(1, BRANCH_COUNT);
	_J.resize(1, BRANCH_COUNT);
	for (_index i = 0; i < BRANCH_COUNT; i++)
	{
		_R[i][0] = r[i];
		_E[i][0] = e[i];
		_J[i][0] = j[i];
	}
	initMNPMatrix(scheme);
}


MNP::~MNP(void)
{
}


void MNP::inputConditions( Graph scheme, vector<resistance_t> r, vector<voltage_t> e, vector<amperage_t> j )
{
	for (_index i = 0; i < BRANCH_COUNT; i++)
	{
		_R[i][0] = r[i];
		_E[i][0] = e[i];
		_J[i][0] = j[i];
	}
	initMNPMatrix(scheme);
}


void MNP::initMNPMatrix( Graph scheme )
{
	_index basicNode = findBasicNode(scheme);
	for (_index i = 0; i < NODE_COUNT; i++)
	{
		if (i + 1 == basicNode)
		{
			continue;
		}
		for (_index j = 0; j < NODE_COUNT; j++)
		{
			if (scheme.findBranch(i + 1, j + 1) != NULL)
			{
				_mnpMatrix[i][scheme.findBranch(i + 1, j + 1)->getBranchNum() - 1] = 1;
			}
			if (scheme.findBranch(j + 1, i + 1) != NULL)
			{
				_mnpMatrix[i][scheme.findBranch(j + 1, i + 1)->getBranchNum() - 1] = -1;
			}
		}
	}
}


_index MNP::findBasicNode(Graph scheme)
{
	_index basicNode;
	unsigned int maxNumOfBranches = 0;
	unsigned int curNumOfBranches = 0;
	for (_index i = 0; i < NODE_COUNT; i++)
	{
		for (_index j = 0; j < NODE_COUNT; j++)
		{
			if (scheme.findBranch(i + 1, j + 1) != NULL)
			{
				curNumOfBranches++;
			}
			if (scheme.findBranch(j + 1, i + 1) != NULL)
			{
				curNumOfBranches++;
			}
		}
		if (curNumOfBranches >= maxNumOfBranches)
		{
			maxNumOfBranches = curNumOfBranches;
			basicNode = i + 1;
		}
	}
	return basicNode;
}

vector<double> MNP::computing( void )
{
	Matrix<double> RD = _R.diag();
	
	cout << "RD = diag(R) :" << endl;/////
	RD.consoleOutput();/////
	
	Matrix<double> G = RD.inverseValues();;
	
	cout << "G = 1/RD :" << endl;/////
	G.consoleOutput();/////
	
	Matrix<double> F = ((_mnpMatrix * G * _mnpMatrix.transposition())^-1) * ((-_mnpMatrix * G * _E) - (_mnpMatrix * _J));
	
	cout << "F = ((A*G * A^T)^-1) * (-A*G*E - A*J) :" << endl;/////
	F.consoleOutput();/////
	
	Matrix<double> U = _mnpMatrix.transposition() * F;
	
	cout << "U = A^T * F :" << endl;/////
	U.transposition().consoleOutput();/////
	
	Matrix<double> IR = G * (U + _E);
	
	cout << "IR = G * (U + E) :" << endl;/////
	IR.transposition().consoleOutput();/////
	
	for (_index i = 0; i < BRANCH_COUNT; i++)
	{
		_result.insert(_result.end(), IR[i][0]); ///?
	}
	return _result;
}

vector<double> MNP::getResult( void )
{
	return _result;
}
