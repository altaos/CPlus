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
    void paintLine(QPoint p1, QPoint p2);
};

#endif // GRAPHVIEW_H
