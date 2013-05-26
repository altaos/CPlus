#ifndef NODE_H
#define NODE_H

#include <vector>
#include <QPoint>
#include "edge.h";

class Edge;

class Node
{
private:
    int number;
    std::vector<Edge*>* edges;
    QPoint coord;
    bool isVisited;
    static const int radius = 10;

public:
    Node(int number);
    Node(int number, QPoint coord);
    Node(Node& node);
    ~Node();

    int getNumber();
    void setNumber(int number);
    QPoint getCoord();
    void setCoord(QPoint coord);
    bool getIsVisited();
    void setIsVisited(bool isVisited);
    int getRadius();
    void addEdge(Edge* edge);
    void deleteEdge(Node* node);
    int getEdgeCount();
};

#endif // NODE_H
