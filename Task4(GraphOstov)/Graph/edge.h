#ifndef EDGE_H
#define EDGE_H

#include "node.h"

class Node;

class Edge
{
private:
    Node *n1;
    Node *n2;
    bool isMarked;
public:
    Edge();
    ~Edge();

    Node* getN1();
    Node* getN2();
    bool getIsMarked();
    void setIsMarked(bool isMarked);
    void setNodes(Node* n1, Node* n2);
};

#endif // EDGE_H
