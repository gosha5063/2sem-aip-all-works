/********************************************************************************
** Form generated from reading UI file 'calcdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCDIALOG_H
#define UI_CALCDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_calcDialog
{
public:

    void setupUi(QDialog *calcDialog)
    {
        if (calcDialog->objectName().isEmpty())
            calcDialog->setObjectName(QString::fromUtf8("calcDialog"));
        calcDialog->resize(800, 600);

        retranslateUi(calcDialog);

        QMetaObject::connectSlotsByName(calcDialog);
    } // setupUi

    void retranslateUi(QDialog *calcDialog)
    {
        calcDialog->setWindowTitle(QCoreApplication::translate("calcDialog", "calcDialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calcDialog: public Ui_calcDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCDIALOG_H
