#include "node.h"

Node::Node(int number)
{
    this->number = number;
    connected_nodes = new std::vector<Node*>();
}

Node::Node(int number, QPoint coord)
{
    this->number = number;
    this->coord = coord;
    connected_nodes = new std::vector<Node*>();
}

Node::Node(Node &node)
{
    this->number = node.number;
    this->coord = node.getCoord();
    this->isVisited = node.IsVisited();
    this->connected_nodes = new std::vector<Node*>();
}

Node::~Node()
{
    connected_nodes->clear();
    delete connected_nodes;
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

int Node::getRadius()
{
    return radius;
}

int Node::getConnectedNodesCount()
{
    return connected_nodes->size();
}

void Node::addConnectedNode(Node *node)
{
    connected_nodes->push_back(node);
}

void Node::deleteConnectedNode(int index)
{
    connected_nodes->erase(connected_nodes->begin() + index);
}

bool Node::hasConnectedNode(Node *node)
{
    for(std::vector<Node*>::iterator it = connected_nodes->begin(); it != connected_nodes->end(); it++)
    {
        if((*it)->getNumber() == node->getNumber())
            return true;
    }

    return false;
}

Node* Node::getConnectedNode(int index)
{
    return connected_nodes->at(index);
}

bool Node::IsVisited()
{
    return isVisited;
}

void Node::Visit()
{
    isVisited = true;
    for(int i = 0; i < connected_nodes->size();)
    {
        Node* node = connected_nodes->at(i);
        if(node->IsVisited())
        {
            //delete connection
            node->deleteConnectedNode(i);
        }
        else
        {
            //set is visited
            node->Visit();
            i++;
        }
    }
}

