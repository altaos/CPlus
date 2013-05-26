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
    QAction* currentAction;
    QGraphicsScene* scene;
    QBrush* brush;
    QPen* pen;

public:
    GraphView();
    ~GraphView();

    void setCurrentAction(QAction* action);
    QGraphicsScene* getScene();
    void setGraph(Graph* graph);
};

#endif // GRAPHVIEW_H
