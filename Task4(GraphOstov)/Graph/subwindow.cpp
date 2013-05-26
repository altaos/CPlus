#include "subwindow.h"
#include "ui_subwindow.h"

SubWindow::SubWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);
    graph = new Graph();
    graph->setBeginNodeNumber(-1);
}

SubWindow::~SubWindow()
{
    delete graph;
    delete ui;
}

Graph* SubWindow::getGraph()
{
    return graph;
}
