#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "subwindow.h"
#include "logger.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    Logger log;
    int* current_action;

private slots:
    void on_openFile_triggered();
    void on_saveFile_triggered();
    void on_findOstovTree_triggered();
    void on_addNode_triggered();
    void on_addEdge_triggered();
    void on_nothing_triggered();
    void on_create_triggered();
};

#endif // MAINWINDOW_H
