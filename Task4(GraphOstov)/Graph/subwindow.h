#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>
#include <QMouseEvent>
//#include <QTextStream>
#include "graphview.h"
#include "filemanager.h"


enum act {NODE, EDGE, NOTHING};

namespace Ui {
class SubWindow;
}

class SubWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit SubWindow(int* action, QWidget *parent = 0);
    ~SubWindow();
    GraphView* getGraphView();
    void loadGraph(QString filename);
    void saveGraph(QString filename);
    Graph* getGraph();
    void setGraph(Graph*& graph);
    void Paint();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    
private:
    Ui::SubWindow *ui;
    GraphView* graphView;
    //int getNodeNumber(std::string str);
    //Node* getNode(std::string str);
    Graph* graph;

    Node* n1;
    Node* n2;
    QPoint tmpPoint;
    int* current_action;
    bool drawing;
};

#endif // SUBWINDOW_H
