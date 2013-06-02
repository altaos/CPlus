#include "graph.h"

Graph::Graph()
{
    nodes = new std::vector<Node*>();
}

Graph::Graph(Graph &graph)
{
    nodes = new std::vector<Node*>();

    for(int i=0; i<graph.getNodeCount();i++)
    {
        Node* n = new Node(*graph.getNode(i));
        nodes->push_back(n);
    }
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
}

void Graph::deleteNode(std::vector<Node*>::iterator it)
{
    nodes->erase(it);
}

Node *Graph::getNode(int index)
{
    return nodes->at(index);
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

Node *Graph::findNode(QPoint point)
{
    for(int i = 0; i < nodes->size(); i++)
    {
        if((point.x() + 10 < (nodes->at(i)->getCoord()).x() || point.x() - 10 > (nodes->at(i)->getCoord()).x()) && (point.y() + 10 < (nodes->at(i)->getCoord()).y() || point.y() - 10 > (nodes->at(i)->getCoord()).y()))
        {
            return nodes->at(i);
        }
    }

    return NULL;
}

int Graph::getNodeCount()
{
    return nodes->size();
}

void Graph::Visite(Node *&node, Graph *&newGraph)
{
    for(auto i = 0; i < node->getConnectedNodesCount(); i++)
    {
        Node* tmp = node->getConnectedNode(i);
        if(!tmp->IsVisited())
        {
            Node* n1 = newGraph->getNode(newGraph->findNode(node->getNumber()));
            Node* n2 = newGraph->getNode(newGraph->findNode(tmp->getNumber()));
            n1->addConnectedNode(n2);
            n2->addConnectedNode(n1);
            tmp->setVisited(true);
            Visite(tmp, newGraph);
        }
    }
}

void Graph::Reset()
{
    for(auto i = 0; i < nodes->size(); i++)
    {
        getNode(i)->setVisited(false);
    }
}

Graph *Graph::getOstovTree()
{
    Graph* newGraph = new Graph(*this);
    Node* firstNode = this->getNode(0);
    firstNode->setVisited(true);
    Visite(firstNode, newGraph);
    Reset();

    return newGraph;
}
