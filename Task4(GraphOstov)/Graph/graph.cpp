#include "graph.h"

Graph::Graph()
{
    nodes = new std::vector<Node*>();
    edges = new std::vector<Edge*>();
}

Graph::~Graph()
{
    nodes->clear();
    edges->clear();
    delete nodes;
    delete edges;
}

void Graph::addNode(Node *node)
{
    nodes->push_back(node);
    numberOfCurrentNode = node->getNumber();
}

void Graph::deleteNode(std::vector<Node*>::iterator it)
{
    nodes->erase(it);
}

int Graph::getNextNodeNumber()
{
    return numberOfCurrentNode++;
}

void Graph::setBeginNodeNumber(int number)
{
    numberOfCurrentNode = number;
}
