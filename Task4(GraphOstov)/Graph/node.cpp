#include "node.h"

Node::Node(int number)
{
    this->number = number;
    edges = new std::vector<Edge*>();
}

Node::Node(int number, QPoint coord)
{
    this->number = number;
    this->coord = coord;
    edges = new std::vector<Edge*>();
}

Node::Node(Node &node)
{
   this->number = node.number;
   this->coord = node.getCoord();
   this->isVisited = node.getIsVisited();
    this->edges = new std::vector<Edge*>();
}

Node::~Node()
{
    edges->clear();
    delete edges;
}

int Node::getNumber()
{
    return number;
}

void Node::setNumber(int number)
{
    this->number = number;
}

QPoint Node::getCoord()
{
    return coord;
}

void Node::setCoord(QPoint coord)
{
    this->coord = coord;
}

void Node::addEdge(Edge* edge)
{
    edges->push_back(edge);
}

int Node::getRadius()
{
    return radius;
}

bool Node::getIsVisited()
{
    return isVisited;
}

void Node::setIsVisited(bool isVisited)
{
    this->isVisited = isVisited;
}

int Node::getEdgeCount()
{
    return edges->size();
}

void Node::deleteEdge(Node *node)
{

    for(std::vector<Edge*>::iterator it = edges->begin(); it != edges->end(); it++)
    {
        if((*it)->getN1()->getNumber() == node->getNumber() || (*it)->getN2()->getNumber() == node->getNumber())
        {
            edges->erase(it);
            break;
        }
    }
}

bool Node::hasEdge(Node *node)
{
    for(std::vector<Edge*>::iterator it = edges->begin(); it != edges->end(); it++)
    {
        if((*it)->getN1()->getNumber() == node->getNumber() ||
                (*it)->getN2()->getNumber() == node->getNumber())
        {
            return true;
        }
    }

    return false;
}
