#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFile_triggered()
{
    //this->setWindowTitle("Changed!");
    QStringList filenames = QFileDialog::getOpenFileNames(
            this,
            tr("Open Document"),
                QDir::currentPath(),
            tr("Documents (*.txt);;All files (*.*)") );

    QDialog *subWindow = new SubWindow();
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
    QDialog *subWindow = new SubWindow();
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->show();
    subWindow->activateWindow();
}

void MainWindow::on_addNode_triggered()
{
    currentAction = ui->addNode;
}

void MainWindow::on_addEdge_triggered()
{
    currentAction = ui->addEdge;
}

