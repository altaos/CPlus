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

    QAction* getCurrentAction();
    
private:
    Ui::MainWindow *ui;
    QAction* currentAction;
    Logger log;

private slots:
    void on_openFile_triggered();
    void on_saveFile_triggered();
    void on_findOstovTree_triggered();
};

#endif // MAINWINDOW_H
