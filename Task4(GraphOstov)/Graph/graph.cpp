#include "graph.h"

Graph::Graph()
{
    nodes = new std::vector<Node*>();
}

Graph::Graph(Graph &graph)
{

}

Graph::~Graph()
{
    for(int i = 0; i < nodes->size(); i++)
    {
        delete nodes->at(i);
    }

    delete nodes;
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

int Graph::getNodeCount()
{
    return nodes->size();
}

Graph *Graph::getOstovTree(Graph* startGraph)
{

}
