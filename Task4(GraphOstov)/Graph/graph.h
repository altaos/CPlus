#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "node.h"

class Graph
{
private:
    int numberOfCurrentNode;

    std::vector<Node*>* nodes;

public:
    Graph();
    Graph(Graph& graph);
    ~Graph();

    void addNode(Node* node);
    void deleteNode(std::vector<Node*>::iterator it);

    Node* getNode(int index);

    int getNextNodeNumber();
    void setBeginNodeNumber(int number);
    int findNode(int number);
    int getNodeCount();
    Graph* getOstovTree(Graph* startGraph);
};

#endif // GRAPH_H
