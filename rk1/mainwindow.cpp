#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "student.h"
#include <QPushButton>
#include <QTextEdit>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton * buttonfind = window()->findChild<QPushButton*>("pushButton_3");
    QPushButton * add1 = window()->findChild<QPushButton*>("pushButton");
    QPushButton * add2 = window()->findChild<QPushButton*>("pushButton_2");

    buttonfind == ui->pushButton_3;
    add1 = ui->pushButton_2;
    add2 = ui->pushButton;

    connect(buttonfind, SIGNAL(clicked()), this, SLOT(find_by_fio()));
    connect(add2, SIGNAL(clicked()), this, SLOT(add_grad_student()));
    connect(add1, SIGNAL(clicked()), this, SLOT(add_student()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::find_by_fio(){
    QString s =  ui->textEdit_7->toPlainText();
    try{
        ui->textEdit_6->setText(g.printStudentInfoByName(s));}
    catch(...){
        ui->textEdit_6->setText("Такого ученика не найдено");
    }

    std::cout<<1;
}
void MainWindow::add_grad_student(){
    QString name = ui->textEdit_2->toPlainText();
    QString age = ui->textEdit->toPlainText();
    QString date = ui->textEdit_5->toPlainText();

    g.addStudent(make_shared<Graduated_sudent>(name, age, date));
    ui->textEdit_2->clear();
    ui->textEdit->clear();
    ui->textEdit_5->clear();

}
void MainWindow::add_student(){
    QString name = ui->textEdit_3->toPlainText();
    QString age = ui->textEdit_4->toPlainText();
    g.addStudent(make_shared<Student>(name, age));
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();

}
