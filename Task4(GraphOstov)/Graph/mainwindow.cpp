#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

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
    subWindow->LoadGraph(filename);
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->show();
    subWindow->activateWindow();

}

void MainWindow::on_saveFile_triggered()
{
    QString filename = QFileDialog::getSaveFileName(
            this,
            tr("Open Document"),
                QDir::currentPath(),
            tr("Documents (*.txt);;All files (*.*)") );
}

void MainWindow::on_newFile_triggered()
{
    QDialog *subWindow = new SubWindow(this);
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->show();
    subWindow->activateWindow();
    //ui->mdiArea->tileSubWindows();
}

void MainWindow::on_addNode_triggered()
{
    for(QList<QMdiSubWindow*>::iterator it = ui->mdiArea->subWindowList().begin(); it != ui->mdiArea->subWindowList().end(); it++)
    {
        QMdiSubWindow *subWindow = *it;
        SubWindow* mySubWind = reinterpret_cast<SubWindow*>(subWindow);
        mySubWind->getGraphView()->setCurrentAction(ui->addNode);
    }
}

void MainWindow::on_addEdge_triggered()
{

}

