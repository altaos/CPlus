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
    subWindow->setWindowTitle("Graph " + (int)(ui->mdiArea->subWindowList(QMdiArea::CreationOrder).size()));
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

    //SubWindow* subWindow = reinterpret_cast<SubWindow*>ui->mdiArea->activeSubWindow();
    //SubWindow* subWindow = static_cast<SubWindow*>(ui->mdiArea->activeSubWindow()->widget());
    //subWindow->SaveGraph(filename);
}

