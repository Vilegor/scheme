#include "Graph.h"


Graph::Graph(void){
	for(int i = 0; i < NODE_COUNT; i++){
		for(int j = 0; j < NODE_COUNT; j++){
			_adjacencyMatrix[i][j] = NULL;
		}
	}
}

Graph::~Graph(void){
}

void Graph::addBranch( size_t id, resistance_t r, voltage_t e, amperage_t i, StartEnd se ){
	Branch *buf = new Branch(id, r, e, i, se);
	_branches.insert(_branches.end(), *buf);
}

void Graph::initMatrix(){
	for(int i = 0; i < BRANCH_COUNT; i++){
		 int s = _branches[i].getStartNode();
		 int e = _branches[i].getEndNode();
		_adjacencyMatrix[s - 1][e - 1] = &(_branches[i]);
	}
}

Branch* Graph::findBranch( _index startNode, _index endNode )
{
	return _adjacencyMatrix[startNode - 1][endNode - 1];
}

void Graph::print( void )
{
	cout << endl;
	for (_index i = 0; i < NODE_COUNT; i++)
	{
		cout << "|";
		for (_index j = 0; j < NODE_COUNT; j++)
		{
			if (_adjacencyMatrix[i][j] != NULL)
			{
				cout << " " << _adjacencyMatrix[i][j]->getBranchNum();
				continue;
			}
			else
			{
				cout << " 0";
			}
		}
		cout << " |" << endl;
	}
	cout << endl;
}