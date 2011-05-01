#ifndef NODE_H
#define NODE_H
#include "SCHEME_H.h"


class Node : public Element
{
    Q_OBJECT;

public:
    Node();

public slots:
    void addBinding(Node* node);

private:
    QImage *_image;
    QVector<Node> *_se;
};

#endif // NODE_H
