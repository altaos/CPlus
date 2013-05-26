#include "edge.h"

Edge::Edge()
{
    isMarked = false;
}

Edge::~Edge()
{

}

void Edge::setNodes(Node* n1, Node* n2)
{
    this->n1 = n1;
    this->n2 = n2;
}

Node* Edge::getN1()
{
    return n1;
}

Node* Edge::getN2()
{
    return n2;
}

bool Edge::getIsMarked()
{
    return isMarked;
}

void Edge::setIsMarked(bool isMarked)
{
    this->isMarked = isMarked;
}
