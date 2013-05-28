#include "subwindow.h"
#include "ui_subwindow.h"

SubWindow::SubWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);
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

//int SubWindow::getNodeNumber(std::string str)
//{
//    int pos = str.find_first_of('-', 0);
//    int num = atoi(str.substr(0, pos).c_str());
//    return num;
//}

//Node* SubWindow::getNode(std::string str)
//{
//    QPoint point;
//    int pos = str.find_first_of('-', 0);
//    int num = atoi(str.substr(0, pos).c_str());
//    int pos_x = str.find_first_of('-', ++pos);
//    point.setX(atoi(str.substr(pos, pos_x).c_str()));
//    int pos_y = str.find_first_of(':', ++pos_x);
//    point.setY(atoi(str.substr(pos_x, pos_y).c_str()));
//    Node* node = new Node(num, point);

//    return node;
//}

