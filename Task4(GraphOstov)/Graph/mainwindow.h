#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "subwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QAction* getCurrentAction();
    
private:
    Ui::MainWindow *ui;
    QAction* currentAction;

private slots:
    void on_openFile_triggered();
    void on_saveFile_triggered();
    void on_newFile_triggered();
    void on_addNode_triggered();
    void on_addEdge_triggered();
};

#endif // MAINWINDOW_H
