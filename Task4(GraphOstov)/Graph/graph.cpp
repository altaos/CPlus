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

void Graph::addEdge(Node *node1, Node *node2, bool isMarked)
{
    if (!node1->hasEdge(node2) && !node2->hasEdge(node1))
    {
        Edge* edge = new Edge();
        edge->setNodes(node1,node2);
        edge->setIsMarked(isMarked);
        edges->push_back(edge);

        node1->addEdge(edge);
        node2->addEdge(edge);
    }
}

Node *Graph::getNode(int index)
{
    return nodes->at(index);
}

int Graph::getNextNodeNumber()
{
    return numberOfCurrentNode++;
}

void Graph::setBeginNodeNumber(int number)
{
    numberOfCurrentNode = number;
}

int Graph::findNode(int number)
{
    for(int i = 0; i < nodes->size(); i++)
    {
        if(nodes->at(i)->getNumber() == number)
            return i;
    }

    return -1;
}
