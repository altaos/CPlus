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

void SubWindow::LoadGraph(QString filename)
{
    Graph* graph = NULL;
    QFile file(filename);
    std::string line;
    if(file.open(QIODevice::ReadOnly |QIODevice::Text))
    {
        graph = new Graph();
        int min_number = -1;

        while(!file.atEnd())
        {
            QString str = file.readLine();
            line = str.toStdString();
            if (line == ".")
                break;

            Node* n = NULL;

            int number = getNodeNumber(line);
            if (number > min_number)
                min_number = number;

            int n_pos = graph->findNode(number);
            if (n_pos < 0)
            {
                n = getNode(line);
                graph->addNode(n);
            }
            else
            {
                n = graph->getNode(n_pos);
            }

            int pos = line.find_first_of(':');
            if (pos < 0) break;

            std::vector<std::string> edges;
            while(pos < line.length())
            {
                pos++;
                int end = line.find_first_of(',',pos);
                if (end < 0) end = line.length();
                if (end < 0) break;
                edges.push_back(line.substr(pos,end-pos));
                pos = end;
            }

            if (edges.size()>0)
            {
                for(int i=0;i<edges.size();i++)
                {
                    Node* nn = NULL;

                    int number = getNodeNumber(edges.at(i));
                    if (number > min_number)
                        min_number = number;

                    int n_pos = graph->findNode(number);
                    if (n_pos<0)
                    {
                        nn = getNode(edges.at(i));
                        graph->addNode(nn);
                    }
                    else
                    {
                        nn = graph->getNode(n_pos);
                    }

                    graph->addEdge(n,nn);
                }
            }
        }

        file.close();
        graph->setBeginNodeNumber(++min_number);
    }

    graphView->setGraph(graph);
}

void SubWindow::SaveGraph(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);

    for(int i = 0; graphView->getGraph()->getNodeCount(); i++)
    {
        Node* node = graphView->getGraph()->getNode(i);
        out << node->getNumber() << "-" << node->getCoord().x() << "-" << node->getCoord().y() <<":";

        for(int j = 0; j < node->getEdgeCount(); j++)
        {
            Node* node2 = node->getEgde(j)->getN1()->getNumber() == node->getNumber() ? node->getEgde(j)->getN2() :
                                                                                        node->getEgde(j)->getN1();
            out << node2->getNumber() << "-" << node2->getCoord().x() << "-" << node2->getCoord().y();
            if (j != node->getEdgeCount() - 1) out << ",";
            else out << "\n";
        }
    }

    out << ".";
    file.close();
}

int SubWindow::getNodeNumber(std::string str)
{
    int pos = str.find_first_of('-', 0);
    int num = atoi(str.substr(0, pos).c_str());
    return num;
}

Node* SubWindow::getNode(std::string str)
{
    QPoint point;
    int pos = str.find_first_of('-', 0);
    int num = atoi(str.substr(0, pos).c_str());
    int pos_x = str.find_first_of('-', ++pos);
    point.setX(atoi(str.substr(pos, pos_x).c_str()));
    int pos_y = str.find_first_of(':', ++pos_x);
    point.setY(atoi(str.substr(pos_x, pos_y).c_str()));
    Node* node = new Node(num, point);

    return node;
}

