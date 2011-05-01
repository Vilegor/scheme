#pragma once
#include "Branch.h"
#include "HEAD.h"

class Graph
{
public:
	Graph(void);
	~Graph(void);
	
	void addBranch(
		size_t id,
		resistance_t r,
		voltage_t e,
		amperage_t i,
		StartEnd se
		);
	void initMatrix();
	Branch* findBranch(_index startNode, _index endNode);
	_testing void print(void);

private:

	vector<Branch> _branches;
	Branch* _adjacencyMatrix[NODE_COUNT][NODE_COUNT];
};

