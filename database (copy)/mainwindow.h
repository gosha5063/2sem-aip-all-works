#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTextEdit * text_edit = window()->findChild<QTextEdit*>("textEdit");
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void set_visible();
    void find_marka();
    void btn1_clicked();
    void btn2_clicked();
    void btn3_clicked();
    void btn4_clicked();
    void btn5_clicked();
    void btn6_clicked();
    void btn7_clicked();
    void compare_f();
    std::string konk(int);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
