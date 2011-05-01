#ifndef GRAPH_H
#define GRAPH_H
#include "SCHEME_H.h"
#include "Scheme/branch.h"

class Graph
{
public:
    Graph();
    ~Graph();
    *Node addNode(void);
    void addNode(_index nodeNum);
    void addBranch(void);
    Branch* findBranch(_index startNode, _index endNode);

private:
    size_t _nodeCount;
    vector<Branch> _branches;
    Branch*** _adjacencyMatrix;
};

#endif // GRAPH_H
