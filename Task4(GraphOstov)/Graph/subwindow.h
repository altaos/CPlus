#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QDialog>
#include <QFile>
#include <QMouseEvent>
#include "graphview.h"

namespace Ui {
class SubWindow;
}

class SubWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit SubWindow(QWidget *parent = 0);
    ~SubWindow();

    GraphView* getGraphView();
    void LoadGraph(QString filename);

private:
    Ui::SubWindow *ui;
    GraphView* graphView;
    int getNodeNumber(std::string str);
    Node* getNode(std::string str);
};

#endif // SUBWINDOW_H
