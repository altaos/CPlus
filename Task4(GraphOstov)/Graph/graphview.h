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
    QPen* penNode;
    QPen* penEdge;

public:
    GraphView();
    ~GraphView();

    QGraphicsScene* getScene();
    void setGraph(Graph* graph);
    Graph* getGraph();
    void paintGraph();
};

#endif // GRAPHVIEW_H
