#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "methods.h"
#include <QTextEdit>
#include <QPushButton>
#include <QGraphicsView>


#include <QGraphicsLineItem>

#include <QGraphicsView>
#include <QGraphicsScene>

class GraphWidget : public QGraphicsView
{
public:
    GraphWidget(QWidget *parent = nullptr) : QGraphicsView(parent)
    {
        QGraphicsScene* scene = new QGraphicsScene(this);
        setScene(scene);
        QGraphicsView view(scene);
        int const_n = 10;
        // Создаем оси координат
        scene->addLine(0, 0, 250, 0, QPen(Qt::black));
        scene->addLine(0, 0, 0, -200, QPen(Qt::black));
        int arr[3000];
        for (int i = 0; i < 3000; ++i) {
            arr[i] = 0;
        }
        //задаем сетку
        for(int i = 0; i < 225; i+=25){
            scene->addLine(i, 0, i, -200, QPen(Qt::black));
            scene->addLine(0, -i, 200, -i, QPen(Qt::black));
        }
        for(MottoBikeObj* a: (new Translator)->show()){
            int x = a->get_year();
            arr[x] += 1;
        }
        QList<QPointF> points = {};
        for(MottoBikeObj* a: (new Translator)->show()){
            int x = a->get_year();
            int y = arr[x];
            if(y == 0)break;
            scene->addEllipse(x/const_n,-1*y*100,5,5,QPen(Qt::blue), QBrush(Qt::blue));
            points.append(QPoint(x/const_n,-1*y*100));
        }

    }
};

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTextEdit * text_edit = window()->findChild<QTextEdit*>("textEdit");
    QPushButton * find = window()->findChild<QPushButton*>("find_btn");
    find->setVisible(false);

    QPushButton * button6 = window()->findChild<QPushButton*>("pushButton_2");
    QPushButton * button5 = window()->findChild<QPushButton*>("pushButton_3");
    QPushButton * button4 = window()->findChild<QPushButton*>("pushButton_4");
    QPushButton * button3 = window()->findChild<QPushButton*>("pushButton_5");
    QPushButton * button2 = window()->findChild<QPushButton*>("pushButton_6");
    QPushButton * button1 = window()->findChild<QPushButton*>("pushButton_7");

    window()->findChild<QLineEdit*>("lineEdit")->setPlaceholderText(QString::fromStdString("Введите марку мотоцикла"));
    window()->findChild<QLineEdit*>("lineEdit_6")->setPlaceholderText(QString::fromStdString("Введите год выпуска(целое число)"));
    window()->findChild<QLineEdit*>("lineEdit_5")->setPlaceholderText(QString::fromStdString("Введите ГосНомер"));
    window()->findChild<QLineEdit*>("lineEdit_3")->setPlaceholderText(QString::fromStdString("Введите Фамилию владельца"));


    connect(find,SIGNAL(clicked()),this,SLOT(find_marka()));
    connect(button6,SIGNAL(clicked()),this,SLOT(btn2_clicked()));
    connect(button5,SIGNAL(clicked()),this,SLOT(btn3_clicked()));
    connect(button4,SIGNAL(clicked()),this,SLOT(btn4_clicked()));
    connect(button3,SIGNAL(clicked()),this,SLOT(btn5_clicked()));
    connect(button2,SIGNAL(clicked()),this,SLOT(btn6_clicked()));
    connect(button1,SIGNAL(clicked()),this,SLOT(btn7_clicked()));
    QGraphicsView *view = ui->graphicsView;
    view->setBackgroundBrush(QBrush(Qt::white));
    // GraphWidget *graphWidget = new GraphWidget(this);
    // view->setScene(graphWidget->scene());
    text_edit->setText(main1());
}
#include <iostream>
#include <QLabel>
std::string mark_name;
//Показать алфавитный перечень владельцев, имеющих мотоциклы данной марки
void MainWindow::btn7_clicked(){
    set_visible();
    QPushButton * button5 = window()->findChild<QPushButton*>("pushButton_3");
    button5->setVisible(false);
    mark_name = "marka";
    // window()->findChild<QVBoxLayout*>("verticalLayout_3")->
    window()->findChild<QLineEdit*>("lineEdit")->clear();
    window()->findChild<QLineEdit*>("lineEdit_6")->clear();
    window()->findChild<QLineEdit*>("lineEdit_5")->clear();
    window()->findChild<QLineEdit*>("lineEdit_3")->clear();
    // window()->findChild<QLineEdit*>("lineEdit")->hide();
    window()->findChild<QLineEdit*>("lineEdit_6")->setVisible(false);
    window()->findChild<QLineEdit*>("lineEdit_5")->setVisible(false);
    window()->findChild<QLineEdit*>("lineEdit_3")->setVisible(false);
    // window()->findChild<QLabel*>("label")->hide();
    window()->findChild<QLabel*>("label_5")->setVisible(false);
    window()->findChild<QLabel*>("label_4")->setVisible(false);
    window()->findChild<QLabel*>("label_3")->setVisible(false);
    window()->findChild<QLabel*>("label_6")->setVisible(false);
    QPushButton * find = window()->findChild<QPushButton*>("find_btn");
    find->setVisible(true);
}
void MainWindow::set_visible(){
    QPushButton * find = window()->findChild<QPushButton*>("find_btn");
    find->setText("Искать");
    window()->findChild<QLineEdit*>("lineEdit")->setVisible(true);
    window()->findChild<QLineEdit*>("lineEdit_6")->setVisible(true);
    window()->findChild<QLineEdit*>("lineEdit_5")->setVisible(true);
    window()->findChild<QLineEdit*>("lineEdit_3")->setVisible(true);
    window()->findChild<QLabel*>("label")->setVisible(true);
    window()->findChild<QLabel*>("label_5")->setVisible(true);
    window()->findChild<QLabel*>("label_6")->setVisible(true);
    window()->findChild<QLabel*>("label_4")->setVisible(true);
    window()->findChild<QLabel*>("label_3")->setVisible(true);
    QPushButton * button5 = window()->findChild<QPushButton*>("pushButton_3");
    button5->setVisible(true);
    find->setVisible(false);
}
//находим фамилии по марке мотоцикла делаем неведимыми все поля кроме марки и показываем кнопку искать
void MainWindow::find_marka(){

    QTextEdit * text_edit = window()->findChild<QTextEdit*>("textEdit");
    string find_lable;
    vector<MottoBikeObj*> dop;
    if(mark_name == "marka"){
        find_lable = "lineEdit";
        dop= (new Translator)->show_mark(window()->findChild<QLineEdit*>(QString::fromStdString( find_lable))->text().toStdString());
    }
    else if(mark_name=="name"){
        find_lable = "lineEdit_3";
        dop= (new Translator)->show_last_name(window()->findChild<QLineEdit*>(QString::fromStdString( find_lable))->text().toStdString());
    }
    // else if(mark_name == "del"){
    //     text_edit->setText((new Translator)->delete_gos(window()->findChild<QLineEdit*>("lineEdit_5")->text().toStdString()));
    //     set_visible();
    //     return;
    // }
    text_edit->setText("");

    if(!dop.size()){
        text_edit->setText("К сожалению, ничего не найдено");
        return;
    }
    for(MottoBikeObj*a: dop){
        text_edit->append(QString::fromStdString(a->get_mark()));
        text_edit->append(QString::number(a->get_year()));
        text_edit->append(QString::fromStdString(a->get_gos_number()));
        text_edit->append(QString::fromStdString(a->get_last_name()));
    }
    set_visible();
}
void MainWindow::btn2_clicked(){
    set_visible();
    mark_name = "del";
    QPushButton * button5 = window()->findChild<QPushButton*>("pushButton_3");
    button5->setVisible(false);
    window()->findChild<QLineEdit*>("lineEdit")->setVisible(false);
    window()->findChild<QLineEdit*>("lineEdit_6")->setVisible(false);
    // window()->findChild<QLineEdit*>("lineEdit_5")->setVisible(false);
    window()->findChild<QLineEdit*>("lineEdit_3")->setVisible(false);
    window()->findChild<QLabel*>("label")->setVisible(false);
    window()->findChild<QLabel*>("label_5")->setVisible(false);
    // window()->findChild<QLabel*>("label_4")->setVisible(false);
    window()->findChild<QLabel*>("label_3")->setVisible(false);
    QPushButton * find = window()->findChild<QPushButton*>("find_btn");
    window()->findChild<QLabel*>("label_6")->setVisible(false);
    find->setVisible(true);
    find->setText("Удалить запись");
}
//поиск по фамилии
void MainWindow::btn5_clicked(){
    set_visible();
    mark_name = "name";
    QPushButton * button5 = window()->findChild<QPushButton*>("pushButton_3");
    button5->setVisible(false);
    window()->findChild<QLineEdit*>("lineEdit")->setVisible(false);
    window()->findChild<QLineEdit*>("lineEdit_6")->setVisible(false);
    window()->findChild<QLineEdit*>("lineEdit_5")->setVisible(false);
    // window()->findChild<QLineEdit*>("lineEdit_3")->setVisible(false);
    window()->findChild<QLabel*>("label")->setVisible(false);
    window()->findChild<QLabel*>("label_5")->setVisible(false);
    window()->findChild<QLabel*>("label_4")->setVisible(false);
    window()->findChild<QLabel*>("label_6")->setVisible(false);
    // window()->findChild<QLabel*>("label_3")->setVisible(false);
    QPushButton * find = window()->findChild<QPushButton*>("find_btn");
    find->setVisible(true);
}

void MainWindow::btn4_clicked(){
    QGraphicsView *view = window()->findChild<QGraphicsView*>("graphicsView");
    GraphWidget *graphWidget = new GraphWidget(this);
    view->setScene(graphWidget->scene());
}

//добавлет новую запись
#include<QLineEdit>
void MainWindow::btn3_clicked(){
    set_visible();
    QString mark = window()->findChild<QLineEdit*>("lineEdit")->text();
    int year  = window()->findChild<QLineEdit*>("lineEdit_6")->text().toInt();
    QString gos_number = window()->findChild<QLineEdit*>("lineEdit_5")->text();
    QString last_name = window()->findChild<QLineEdit*>("lineEdit_3")->text();
    QTextEdit * text_edit = window()->findChild<QTextEdit*>("textEdit");
    if(!mark.isEmpty() && year && !gos_number.isEmpty() && !last_name.isEmpty()){
        text_edit->setText((new Translator)->add(mark.toStdString(),year,gos_number.toStdString(),last_name.toStdString()));
        window()->findChild<QLineEdit*>("lineEdit")->setText("");
        window()->findChild<QLineEdit*>("lineEdit_6")->setText("");
        window()->findChild<QLineEdit*>("lineEdit_5")->setText("");
        window()->findChild<QLineEdit*>("lineEdit_3")->setText("");
    }
    else{
        text_edit->setText("Вы  ввели что-то не то\n\
Попробуйте ввести значения в поля для ввода");
    }
}
//выводит все записи
void MainWindow::btn6_clicked(){
    set_visible();
    QTextEdit * text_edit = window()->findChild<QTextEdit*>("textEdit");
    text_edit->clear();
    int count = 1;
    for(MottoBikeObj* a: (new Translator)->show()){
        text_edit->append(QString::fromStdString("запись №") + QString::number(count));
        text_edit->append(QString::fromStdString(a->get_mark()));
        text_edit->append(QString::number(a->get_year()));
        text_edit->append(QString::fromStdString(a->get_gos_number()));
        text_edit->append(QString::fromStdString(a->get_last_name()));
        text_edit->append("");
        count++;
    }

}
string MainWindow:: konk(int k){
    string s = "";
    for (int i = 0; i < k; ++i) {
        s  = s + " ";
    }
    return s;
}
void MainWindow::btn1_clicked(){
    set_visible();
    std::cout << 6;

}

MainWindow::~MainWindow()
{
    delete ui;
}
