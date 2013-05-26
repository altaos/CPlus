#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include "graph.h"
#include <QAction>
#include <QGraphicsScene>
#include "filemanager.h"

class GraphView
{
private:
    Graph* graph;
    QGraphicsScene* scene;
    QBrush* brush;
    QPen* pen;

public:
    GraphView();
    ~GraphView();

    QGraphicsScene* getScene();
    void setGraph(Graph* graph);
    Graph* getGraph();
};

#endif // GRAPHVIEW_H
