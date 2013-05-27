#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "node.h"

class Graph
{
private:
    int numberOfCurrentNode;

    std::vector<Node*>* nodes;
    //std::vector<Edge*>* edges;

public:
    Graph();
    ~Graph();

    void addNode(Node* node);
    void deleteNode(std::vector<Node*>::iterator it);

    Node* getNode(int index);

    int getNextNodeNumber();
    void setBeginNodeNumber(int number);
    int findNode(int number);
    int getNodeCount();
};

#endif // GRAPH_H
