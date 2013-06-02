#include "graphview.h"
#include <QFont>
#include "filemanager.h"

GraphView::GraphView()
{
    scene = new QGraphicsScene();
    brush = new QBrush(Qt::white);
    penNode = new QPen(Qt::blue);
    penNode->setWidth(2);
    penEdge = new QPen(Qt::black);
    penEdge->setWidth(2);
}

GraphView::~GraphView()
{
    delete penNode;
    delete penEdge;
    delete brush;
    scene->clear();
    delete scene;
}

QGraphicsScene* GraphView::getScene()
{
    return scene;
}

void GraphView::paintGraph(Graph* graph)
{
    //paint edges
    for(int i = 0; i < graph->getNodeCount(); i++)
    {
        Node* node1 = graph->getNode(i);
        for(int j = 0; j < node1->getConnectedNodesCount(); j++)
        {
            scene->addLine(node1->getCoord().x(), node1->getCoord().y(), node1->getConnectedNode(j)->getCoord().x(),  node1->getConnectedNode(j)->getCoord().y(), *penEdge);
            //scene->addLine()
        }
    }

    //QFont* font = new QFont();
    //paint nodes
    for(int i = 0; i < graph->getNodeCount(); i++)
    {
        Node* node1 = graph->getNode(i);
        scene->addEllipse(node1->getCoord().x() - node1->getRadius(), node1->getCoord().y() - node1->getRadius(), 2*node1->getRadius(), 2*node1->getRadius(), *penNode, *brush);
        //QGraphicsTextItem text = scene->addText((QString)node1->getNumber(), *font);
    }
}

void GraphView::paintLine(QPoint p1, QPoint p2)
{
    scene->addLine(p1.x(), p1.y(), p2.x(),  p2.y(), *penEdge);
}
