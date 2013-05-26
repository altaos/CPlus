#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QDialog>
#include "graph.h"

namespace Ui {
class SubWindow;
}

class SubWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit SubWindow(QWidget *parent = 0);
    ~SubWindow();

    Graph* getGraph();
    //void setCurrentAction(QAction* action);
    
private:
    Ui::SubWindow *ui;
    Graph* graph;
    QAction* currentAction;
};

#endif // SUBWINDOW_H
