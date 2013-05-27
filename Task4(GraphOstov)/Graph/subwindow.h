#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>
//#include <QTextStream>
#include "graphview.h"

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
    
private:
    Ui::SubWindow *ui;
    GraphView* graphView;
    int getNodeNumber(std::string str);
    Node* getNode(std::string str);
};

#endif // SUBWINDOW_H
