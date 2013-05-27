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
    //this->setWindowTitle("Changed!");
    QString filename = QFileDialog::getOpenFileName(
            this,
            tr("Open Document"),
                QDir::currentPath(),
            tr("Documents (*.txt);;All files (*.*)") );

    SubWindow *subWindow = new SubWindow(this);
    subWindow->setWindowTitle("Graph " + (int)(ui->mdiArea->subWindowList(QMdiArea::CreationOrder).size()));
    subWindow->loadGraph(filename);
    subWindow->show();
    subWindow->getGraphView()->paintGraph();
    subWindow->activateWindow();
    ui->mdiArea->addSubWindow(subWindow);
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
}

