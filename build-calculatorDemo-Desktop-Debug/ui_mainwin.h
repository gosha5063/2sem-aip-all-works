/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;

    void setupUi(QWidget *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName(QString::fromUtf8("MainWin"));
        MainWin->resize(210, 173);
        verticalLayout_7 = new QVBoxLayout(MainWin);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lineEdit = new QLineEdit(MainWin);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_6->addWidget(lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButton_3 = new QPushButton(MainWin);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_4->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(MainWin);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_4->addWidget(pushButton_2);

        pushButton = new QPushButton(MainWin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_4->addWidget(pushButton);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        pushButton_8 = new QPushButton(MainWin);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout_5->addWidget(pushButton_8);

        pushButton_7 = new QPushButton(MainWin);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout_5->addWidget(pushButton_7);

        pushButton_4 = new QPushButton(MainWin);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_5->addWidget(pushButton_4);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_2);

        pushButton_9 = new QPushButton(MainWin);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout_6->addWidget(pushButton_9);


        verticalLayout_7->addLayout(verticalLayout_6);

        QWidget::setTabOrder(pushButton_7, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_8);
        QWidget::setTabOrder(pushButton_8, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_9);

        retranslateUi(MainWin);
        QObject::connect(pushButton_9, SIGNAL(clicked(bool)), MainWin, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QWidget *MainWin)
    {
        MainWin->setWindowTitle(QCoreApplication::translate("MainWin", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWin", "C", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWin", "+", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWin", "-", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWin", "=", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWin", "*", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWin", "/", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWin", "\320\267\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
