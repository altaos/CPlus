#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "node.h"

class Graph
{
private:
    std::vector<Node*>* nodes;

    void Visite(Node*& node, Graph*& newGraph);
    void Reset();

public:
    Graph();
    Graph(Graph& graph);
    ~Graph();

    void addNode(Node* node);
    void deleteNode(std::vector<Node*>::iterator it);

    Node* getNode(int index);
    int findNode(int number);
    Node* findNode(QPoint point);
    int getNodeCount();
    Graph* getOstovTree();
};

#endif // GRAPH_H
