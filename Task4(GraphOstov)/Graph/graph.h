#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "node.h"
#include "edge.h"

class Graph
{
private:
    std::vector<Node*>* nodes;
    std::vector<Edge*>* edges;

public:
    Graph();
    ~Graph();

    void addNode(Node* node);
    void deleteNode(std::vector<Node*>::iterator it);
};

#endif // GRAPH_H
