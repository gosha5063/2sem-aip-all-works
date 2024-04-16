#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton * add = ui->pushButton;
    QPushButton * show = ui->pushButton_2;
    QPushButton * del = ui->pushButton_3;
    connect(add, SIGNAL(clicked()), this, SLOT(add()));
    connect(show, SIGNAL(clicked()), this, SLOT(cout()));
    connect(del, SIGNAL(clicked()), this, SLOT(del()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::del(){
    clear();
    QTextEdit * textbox = ui->textEdit;
    try{
        QString word =QString::fromStdString(q.popfront()->toString());
        textbox->setText("запись: " + word + " удалена из очереди");
    }
    catch(...){
        textbox->setText("Очередь пуста");
    }
}
void MainWindow::clear(){
    QTextEdit * textbox = ui->textEdit;
    textbox->clear();
}

void MainWindow::cout(){
    clear();
    QTextEdit * textbox = ui->textEdit;
    QString s = "";
    for(auto&elem:q.print()){
        s += QString::fromStdString(elem->toString()) + "\n";
    }
    textbox -> setText(s);
    if(s == ""){textbox->setText("Очередь пуста");return;}
    textbox->setText(s);
}
void MainWindow:: add(){
    clear();
    QLineEdit * line = ui->lineEdit;
    QTextEdit * textbox = ui->textEdit;
    QString text = line->text();
    if(text == ""){textbox -> setText("Вы ввели пустую строку");return;}
    bool ok;
    int num = text.toInt(&ok);
    if(ok) {
        q.add(make_shared<Tnum>(num));
    } else {
        q.add(make_shared<Tstr>(text.toStdString()));
    }
    textbox -> setText("Запись успешно добавлена в очередь");
    line->clear();
}


