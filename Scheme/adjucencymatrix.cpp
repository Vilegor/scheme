#include "adjucencymatrix.h"

AdjucencyMatrix::AdjucencyMatrix()
{
}

void AdjucencyMatrix::init()
{

}

void AdjucencyMatrix::addNode(Node *newNode)
{
    QVector<size_t> *temp;
    _matrix.resize(_matrix.size() + 1);
    for(size_t i = 0; i < _matrix[i].size(); i++){
        _matrix[i].resize(_matrix[i].size() + 1);
    }
    *temp = newNode->getBindings();
    for(size_t i = 0; i < temp->size(); i++){
        //_matrix[newNode->getID()][temp[i]] = newNode;
    }
}
