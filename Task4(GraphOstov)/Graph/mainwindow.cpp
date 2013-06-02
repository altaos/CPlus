#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMdiSubWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    current_action = new int(0);
    //SubWindow* subWindow = new SubWindow(this);
    //ui->mdiArea->addSubWindow(subWindow);
    //subWindow->show();
    //subWindow->activateWindow();
    //ui->mdiArea->tileSubWindows();
}

MainWindow::~MainWindow()
{
    delete current_action;
    delete ui;
}

/*void MainWindow::paintEvent(QPaintEvent *p)
{
    SubWindow* subWindow = static_cast<SubWindow*>(ui->mdiArea->currentSubWindow()->widget());
    GraphView* view = subWindow->getGraphView();

    if(drawing)
    {
        view->paintLine(n1->getCoord(), tmpPoint);
    }
    else
    {
        view->paintGraph(subWindow->getGraph());
    }
}*/

void MainWindow::on_openFile_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
            this,
            tr("Open Document"),
                QDir::currentPath(),
            tr("Documents (*.txt);;All files (*.*)") );

    SubWindow *subWindow = new SubWindow(current_action, this);
    subWindow->setWindowTitle(filename);
    subWindow->loadGraph(filename);
    log.Write(filename + ": Граф загружен");
    subWindow->show();
    //subWindow->getGraphView()->paintGraph(subWindow->getGraph());
    subWindow->activateWindow();
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->Paint();
    log.Write(filename + ": Создана дочерняя форма");
}

void MainWindow::on_saveFile_triggered()
{
    QString filename = QFileDialog::getSaveFileName(
            this,
            tr("Open Document"),
                QDir::currentPath(),
            tr("Documents (*.txt);;All files (*.*)") );

    //SubWindow* subWindow = reinterpret_cast<SubWindow*>ui->mdiArea->activeSubWindow();
    //if (ui->mdiArea->activeSubWindow() != NULL)
    SubWindow* subWindow = static_cast<SubWindow*>(ui->mdiArea->currentSubWindow()->widget());//activeSubWindow()->widget());

    subWindow->saveGraph(filename);
    log.Write(filename + ": Граф сохранен");
}

void MainWindow::on_findOstovTree_triggered()
{
    SubWindow* subWindow = static_cast<SubWindow*>(ui->mdiArea->currentSubWindow()->widget());//activeSubWindow()->widget());
    SubWindow* newSubWindow = new SubWindow(current_action, this);
    ui->mdiArea->addSubWindow(newSubWindow);
    Graph* n_gr = subWindow->getGraph()->getOstovTree();
    log.Write(subWindow->windowTitle() + ": Найдено остовновное дерево");
    log.Write(subWindow->windowTitle() + ": Создана дочерняя форма");
    newSubWindow->setGraph(n_gr);
    newSubWindow->show();
    newSubWindow->activateWindow();
    //newSubWindow->getGraphView()->paintGraph(n_gr);
    newSubWindow->Paint();
}

void MainWindow::on_addNode_triggered()
{
    *current_action = 1;
}

void MainWindow::on_addEdge_triggered()
{
    *current_action = 2;
}

void MainWindow::on_nothing_triggered()
{
    *current_action = 0;
}

void MainWindow::on_create_triggered()
{
    SubWindow* subWindow = new SubWindow(current_action, this);
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->show();
    subWindow->activateWindow();
}

