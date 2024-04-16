#include "mainwin.h"
#include "ui_mainwin.h"

MainWin::MainWin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWin),res(0.0), oper('@')
{
    ui->setupUi(this);
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),
                this,SLOT(on_pushButton_3_clicked()));
        connect(ui->pushButton_2,SIGNAL(clicked(bool)),
                this,SLOT(on_pushButton_2_clicked()));
        connect(ui->pushButton_4,SIGNAL(clicked(bool)),
                this,SLOT(on_pushButton_2_clicked()));
        connect(ui->pushButton_7,SIGNAL(clicked(bool)),
                this,SLOT(on_pushButton_2_clicked()));
        connect(ui->pushButton_8,SIGNAL(clicked(bool)),
                this,SLOT(on_pushButton_2_clicked()));
        connect(ui->pushButton,SIGNAL(clicked(bool)),
                this,SLOT(on_pushButton_2_clicked()));
//        connect(ui->pushButton_9,SIGNAL(clicked(bool)),
//                this,SLOT(close()));
}

MainWin::~MainWin()
{
    delete ui;
}


void MainWin::on_pushButton_3_clicked()
{
    ui -> lineEdit -> clear();
        ui -> lineEdit -> setFocus();
        res = 0.0;    oper = '@';

}


void MainWin::on_pushButton_2_clicked()
{
    double r = ui->lineEdit->text().toDouble();
        if (oper == '+')  res+=r;
        else
            if (oper == '-')  res-=r;
            else
                if (oper == '*')  res*=r;
                else
               if (oper == '/')  res/=r;
               else  res = r;
            // определяем виджет, отправившый сигнал – sender()
        QPushButton* buttonSender =
                qobject_cast<QPushButton*>(sender());
        oper = (buttonSender->text())[0];
        QString str;
        if (oper == '=')
           ui->lineEdit->setText(str.setNum(res));
        else ui->lineEdit->setText("");
            ui->lineEdit->setFocus();
}

