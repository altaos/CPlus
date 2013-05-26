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
};

#endif // GRAPH_H
