#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>
//#include <QTextStream>
#include "graphview.h"
#include "filemanager.h"

namespace Ui {
class SubWindow;
}

class SubWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit SubWindow(QWidget *parent = 0);
    ~SubWindow();
    GraphView* getGraphView();
    void loadGraph(QString filename);
    void saveGraph(QString filename);
    Graph* getGraph();
    void setGraph(Graph*& graph);
    
private:
    Ui::SubWindow *ui;
    GraphView* graphView;
    //int getNodeNumber(std::string str);
    //Node* getNode(std::string str);
    Graph* graph;
};

#endif // SUBWINDOW_H
