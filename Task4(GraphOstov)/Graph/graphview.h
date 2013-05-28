#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include "graph.h"
#include <QGraphicsScene>

class GraphView
{
private:
    QGraphicsScene* scene;
    QBrush* brush;
    QPen* penNode;
    QPen* penEdge;

public:
    GraphView();
    ~GraphView();

    QGraphicsScene* getScene();
    void paintGraph(Graph* graph);
};

#endif // GRAPHVIEW_H
