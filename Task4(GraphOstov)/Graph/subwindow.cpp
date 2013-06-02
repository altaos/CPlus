#include "subwindow.h"
#include "ui_subwindow.h"

SubWindow::SubWindow(int* action, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);
    graph = new Graph();
    drawing = false;
    current_action = action;
    graphView = new GraphView();
    ui->graphicsView->setScene(graphView->getScene());
}

SubWindow::~SubWindow()
{
    if(graph)
       delete graph;
    delete graphView;
    delete ui;
}

GraphView* SubWindow::getGraphView()
{
    return graphView;
}

void SubWindow::loadGraph(QString filename)
{
    graph = FileManager::open(filename);
}

void SubWindow::saveGraph(QString filename)
{
    FileManager::save(graph, filename);
}

Graph *SubWindow::getGraph()
{
    return graph;
}

void SubWindow::setGraph(Graph *&graph)
{
    this->graph = graph;
}

void SubWindow::Paint()
{
    graphView->getScene()->clear();
    if(drawing)
    {
        graphView->paintGraph(graph);
        graphView->paintLine(n1->getCoord(), tmpPoint);
    }
    else
    {
        graphView->paintGraph(graph);
    }
}

void SubWindow::mousePressEvent(QMouseEvent *e)
{
    if(*current_action == 1)
    {
        Node* node = new Node(graph->getNodeCount(), e->pos());
        graph->addNode(node);
        Paint();
    }

    if(*current_action == 2)
    {
        n1 = graph->findNode(e->pos());
        tmpPoint = e->pos();
        if(n1)
            drawing = true;
        Paint();
    }
}

void SubWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if(*current_action == 1 && drawing)
    {
        drawing = false;
        tmpPoint = e->pos();
        n2 = graph->findNode(tmpPoint);

        if(n2)
        {
            n1->addConnectedNode(n2);
            n2->addConnectedNode(n1);
        }
        Paint();
    }
}

void SubWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(*current_action == 2 && drawing)
    {
        tmpPoint = e->pos();
        Paint();
    }
}

