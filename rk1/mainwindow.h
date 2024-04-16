#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Group g;
public slots:
    void find_by_fio();
    void add_student();
    void add_grad_student();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
