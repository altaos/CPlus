#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMdiSubWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->mdiArea->tileSubWindows();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFile_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
            this,
            tr("Open Document"),
                QDir::currentPath(),
            tr("Documents (*.txt);;All files (*.*)") );

    SubWindow *subWindow = new SubWindow(this);
    subWindow->setWindowTitle(filename);
    subWindow->loadGraph(filename);
    log.Write(filename + ": Граф загружен");
    subWindow->show();
    subWindow->getGraphView()->paintGraph(subWindow->getGraph());
    subWindow->activateWindow();
    ui->mdiArea->addSubWindow(subWindow);
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
    SubWindow* newSubWindow = new SubWindow(this);
    ui->mdiArea->addSubWindow(newSubWindow);
    Graph* n_gr = subWindow->getGraph()->getOstovTree();
    log.Write(subWindow->windowTitle() + ": Найдено остовновное дерево");
    log.Write(subWindow->windowTitle() + ": Создана дочерняя форма");
    newSubWindow->setGraph(n_gr);
    newSubWindow->show();
    newSubWindow->getGraphView()->paintGraph(n_gr);
    newSubWindow->activateWindow();
}

