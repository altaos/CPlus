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
    delete graphView;
    delete ui;
}

GraphView* SubWindow::getGraphView()
{
    return graphView;
}

void SubWindow::loadGraph(QString filename)
{
    graphView->setGraph(FileManager::open(filename));
}

void SubWindow::saveGraph(QString filename)
{
//    QFile file(filename);
//    file.open(QIODevice::WriteOnly|QIODevice::Text);
//    QTextStream out(&file);

//    for(int i = 0; graphView->getGraph()->getNodeCount(); i++)
//    {
//        Node* node = graphView->getGraph()->getNode(i);
//        out << node->getNumber() << "-" << node->getCoord().x() << "-" << node->getCoord().y() <<":";

//        for(int j = 0; j < node->getEdgeCount(); j++)
//        {
//            Node* node2 = node->getEgde(j)->getN1()->getNumber() == node->getNumber() ? node->getEgde(j)->getN2() :
//                                                                                        node->getEgde(j)->getN1();
//            out << node2->getNumber() << "-" << node2->getCoord().x() << "-" << node2->getCoord().y();
//            if (j != node->getEdgeCount() - 1) out << ",";
//            else out << "\n";
//        }
//    }

//    out << ".";
//    file.close();
    FileManager::save(graphView->getGraph(), filename);
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

