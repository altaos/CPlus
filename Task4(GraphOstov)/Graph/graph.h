#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "node.h"
#include "edge.h"

class Graph
{
private:
    int numberOfCurrentNode;

    std::vector<Node*>* nodes;
    std::vector<Edge*>* edges;

public:
    Graph();
    ~Graph();

    void addNode(Node* node);
    void deleteNode(std::vector<Node*>::iterator it);

    void addEdge(Node* node1, Node* node2, bool isMarked = false);
    Node* getNode(int index);

    int getNextNodeNumber();
    void setBeginNodeNumber(int number);
    int findNode(int number);
    int getNodeCount();
    int getEdgeCount();
};

#endif // GRAPH_H
