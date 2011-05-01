#include "node.h"

Node::Node()
{
    _image = new QImage(NODE_IMAGE_PATH);
}

void Node::addBinding(Node *node)
{
    _bindings.insert(_bindings.end(),node->getID());
}

QVector<size_t> Node::getBindings()
{
    return _bindings;
}

size_t Node::getID()
{
    return _id;
}
