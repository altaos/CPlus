#include "graphview.h"

GraphView::GraphView()
{
    graph = new Graph();
    graph->setBeginNodeNumber(-1);
    currentAction = NULL;
    scene = new QGraphicsScene();
    brush = new QBrush(Qt::white);
    pen = new QPen(Qt::green);
    pen->setWidth(2);
}

GraphView::~GraphView()
{
    delete pen;
    delete brush;
    delete scene;

    if(graph)
        delete graph;
}

void GraphView::setCurrentAction(QAction* action)
{
    currentAction = action;
}

QGraphicsScene* GraphView::getScene()
{
    return scene;
}

void GraphView::setGraph(Graph *graph)
{
    this->graph = graph;
}

Graph *GraphView::getGraph()
{
    return graph;
}
