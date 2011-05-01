#ifndef NODE_H
#define NODE_H
#include "SCHEME_H.h"
#include "Scheme/element.h"


class Node : public Element
{
    Q_OBJECT;

public:
    Node();

public slots:
    void addBinding(Node* node);
    QVector<size_t> getBindings();
    size_t getID();

private:
    size_t _id;
    QImage *_image;
    QVector<size_t> _bindings;
};

#endif // NODE_H
