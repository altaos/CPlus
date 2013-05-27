#ifndef NODE_H
#define NODE_H

#include <vector>
#include <QPoint>

class Node
{
private:
    int number;
    QPoint coord;
    bool isVisited;
    static const int radius = 10;
    std::vector<Node*>* connected_nodes;

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
    int getConnectedNodesCount();
    void addConnectedNode(Node* node);
    bool hasConnectedNode(Node* node);
    Node* getConnectedNode(int index);
};

#endif // NODE_H
