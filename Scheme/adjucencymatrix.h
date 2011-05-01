#ifndef ADJUCENCYMATRIX_H
#define ADJUCENCYMATRIX_H

#include "SCHEME_H.h"
#include <QVector>
#include "Elements/node.h"

class AdjucencyMatrix
{
public:
    AdjucencyMatrix();

public slots:
    void addNode(Node* newNode);

private:
    QVector< QVector< Node* > > _matrix;//????????????????

    void init();

};

#endif // ADJUCENCYMATRIX_H
