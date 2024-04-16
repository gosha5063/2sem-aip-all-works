#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "methods.h"
#include <QTextEdit>
#include <QPushButton>
#include <QGraphicsView>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QGraphicsLineItem>

#include <QGraphicsView>
#include <QGraphicsScene>
#include "hist.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene); // ui->graphicsView - это ваш QGraphicsView, полученный через ui файла.
    QTextEdit * text_edit = window()->findChild<QTextEdit*>("textEdit");
    QPushButton * find = window()->findChild<QPushButton*>("find_btn");
    find->setVisible(false);
    QPushButton * button6 = window()->findChild<QPushButton*>("pushButton_2");
    QPushButton * button5 = window()->findChild<QPushButton*>("pushButton_3");
    QPushButton * button4 = window()->findChild<QPushButton*>("pushButton_4");
    QPushButton * button3 = window()->findChild<QPushButton*>("pushButton_5");
    QPushButton * button2 = window()->findChild<QPushButton*>("pushButton_6");
    QPushButton * button1 = window()->findChild<QPushButton*>("pushButton_7");

    window()->findChild<QLineEdit*>("lineEdit")->setPlaceholderText(QString::fromStdString("Введите класс животного"));
    window()->findChild<QLineEdit*>("lineEdit_6")->setPlaceholderText(QString::fromStdString("Введите отряд"));
    window()->findChild<QLineEdit*>("lineEdit_5")->setPlaceholderText(QString::fromStdString("Введите семейство"));
    window()->findChild<QLineEdit*>("lineEdit_3")->setPlaceholderText(QString::fromStdString("Введите вид"));
    QPushButton * compare = window()->findChild<QPushButton*>("compare");

    connect(find,SIGNAL(clicked()),this,SLOT(find_marka()));
    connect(button6,SIGNAL(clicked()),this,SLOT(btn2_clicked()));
    connect(button5,SIGNAL(clicked()),this,SLOT(btn3_clicked()));
    connect(button4,SIGNAL(clicked()),this,SLOT(btn4_clicked()));
    connect(button3,SIGNAL(clicked()),this,SLOT(btn5_clicked()));
    connect(button2,SIGNAL(clicked()),this,SLOT(btn6_clicked()));
    connect(button1,SIGNAL(clicked()),this,SLOT(btn7_clicked()));
    connect(compare,SIGNAL(clicked()), this, SLOT(compare_f()));
    QGraphicsView *view = ui->graphicsView;
    view->setBackgroundBrush(QBrush(Qt::white));
    // GraphWidget *graphWidget = new GraphWidget(this);
    // view->setScene(graphWidget->scene());
    text_edit->setText(main1());

}
#include <iostream>
#include <QLabel>
std::string mark_name;
void MainWindow::compare_f(){
    vector<MottoBikeObj*> dop1;
    vector<MottoBikeObj*> dop2;
    dop1 = (new Translator)->show_mark(window()->findChild<QLineEdit*>(QString::fromStdString("sem1"))->text().toStdString());
    dop2 = (new Translator)->show_mark(window()->findChild<QLineEdit*>(QString::fromStdString("sem2"))->text().toStdString());
    vector<MottoBikeObj*> dop = dop2;
    if(dop1.size() > dop2.size()){
        dop = dop1;
    }

    QTextEdit * text_edit = window()->findChild<QTextEdit*>("textEdit");
    text_edit -> setText("");
    int i = 1;
    if(dop.size() == 0){
        text_edit -> setText("Таких семейств нет");
    }
    for(MottoBikeObj*a: dop){
        text_edit->append(" note №" + i);
        text_edit->append(QString::fromStdString(a->get_mark()));
        text_edit->append(QString::fromStdString(a->get_year()));
        text_edit->append(QString::fromStdString(a->get_gos_number()));
        text_edit->append(QString::fromStdString(a->get_last_name()));
        i++;
    }

}
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
        dop = (new Translator)->show_mark(window()->findChild<QLineEdit*>(QString::fromStdString( find_lable))->text().toStdString());
    }
    else if(mark_name=="name"){
        find_lable = "lineEdit_3";
        dop = (new Translator)->show_last_name(window()->findChild<QLineEdit*>(QString::fromStdString( find_lable))->text().toStdString());
    }
    else if(mark_name == "del"){
        text_edit->setText((new Translator)->delete_gos(window()->findChild<QLineEdit*>("lineEdit_3")->text().toStdString()));
        set_visible();
        return;
    }
    text_edit->setText("");

    if(!dop.size()){
        text_edit->setText("К сожалению, ничего не найдено");
        return;
    }
    int i = 1;
    for(MottoBikeObj*a: dop){
        text_edit->append(" запись №" + i);
        text_edit->append(QString::fromStdString(a->get_mark()));
        text_edit->append(QString::fromStdString(a->get_year()));
        text_edit->append(QString::fromStdString(a->get_gos_number()));
        text_edit->append(QString::fromStdString(a->get_last_name()));
        i++;
    }
    set_visible();
}
//удалить запись по госномеру
void MainWindow::btn2_clicked(){
    set_visible();
    mark_name = "del";
    QPushButton * button5 = window()->findChild<QPushButton*>("pushButton_3");
    button5->setVisible(false);
    window()->findChild<QLineEdit*>("lineEdit")->setVisible(false);
    window()->findChild<QLineEdit*>("lineEdit_6")->setVisible(false);
    window()->findChild<QLineEdit*>("lineEdit_5")->setVisible(false);
    // window()->findChild<QLineEdit*>("lineEdit_3")->setVisible(false);
    window()->findChild<QLabel*>("label")->setVisible(false);
    window()->findChild<QLabel*>("label_5")->setVisible(false);
    window()->findChild<QLabel*>("label_4")->setVisible(false);
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
int rand(int a, int b){
    return (a*a + 78*a + b)%b;
}
void addHistogramData(QGraphicsScene* scene, const QVector<QString>& dataValues, double maxValue) {
    int numBars = dataValues.size();
    if (numBars == 0) return;

    int sceneWidth = scene->width(); // Ширина сцены для расчета ширины столбика
    double width = 100; // Отступ между столбцами

    for (int i = 0; i < numBars; ++i) {
        double height = 100;// Расчет высоты столбца
        QGraphicsRectItem* rect = new QGraphicsRectItem(0, 0, width, -rand(10,((i+1)*12))*3);
        rect->setPos(i * (width + 20), 100); // Позиционирование столбца
        rect->setBrush(QBrush(Qt::blue));
        scene->addItem(rect); // Добавление столбца на сцену
    }
}

void MainWindow::btn4_clicked(){

    QVector<QString> data = {"sd", "ads"};
    double maxValue = 20; // Максимальное значение для масштабирования гистограммы

    QGraphicsScene* scene = ui->graphicsView->scene(); // Получение сцены из вашего QGraphicsView
    addHistogramData(scene, data, maxValue); // Вывод данных на сцену
}


//добавлет новую запись
#include<QLineEdit>
void MainWindow::btn3_clicked(){
    set_visible();
    QString mark = window()->findChild<QLineEdit*>("lineEdit")->text();
    QString year  = window()->findChild<QLineEdit*>("lineEdit_6")->text();
    QString gos_number = window()->findChild<QLineEdit*>("lineEdit_5")->text();
    QString last_name = window()->findChild<QLineEdit*>("lineEdit_3")->text();
    QTextEdit * text_edit = window()->findChild<QTextEdit*>("textEdit");
    if(!mark.isEmpty() && !year.isEmpty() && !gos_number.isEmpty() && !last_name.isEmpty()){
        text_edit->setText((new Translator)->add(mark.toStdString(),year.toStdString(),gos_number.toStdString(),last_name.toStdString()));
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
        text_edit->append("Класс: "+QString::fromStdString(a->get_mark()));
        text_edit->append("Отряд: "+QString::fromStdString(a->get_year()));
        text_edit->append("Семейство: "+QString::fromStdString(a->get_gos_number()));
        text_edit->append("Вид: "+QString::fromStdString(a->get_last_name()));
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
