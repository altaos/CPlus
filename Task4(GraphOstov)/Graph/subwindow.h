#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QDialog>

namespace Ui {
class SubWindow;
}

class SubWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit SubWindow(QWidget *parent = 0);
    ~SubWindow();
    
private:
    Ui::SubWindow *ui;
};

#endif // SUBWINDOW_H
