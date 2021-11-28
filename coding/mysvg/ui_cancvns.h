/********************************************************************************
** Form generated from reading UI file 'cancvns.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANCVNS_H
#define UI_CANCVNS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CanCvns
{
public:

    void setupUi(QWidget *CanCvns)
    {
        if (CanCvns->objectName().isEmpty())
            CanCvns->setObjectName(QString::fromUtf8("CanCvns"));
        CanCvns->resize(400, 300);

        retranslateUi(CanCvns);

        QMetaObject::connectSlotsByName(CanCvns);
    } // setupUi

    void retranslateUi(QWidget *CanCvns)
    {
        CanCvns->setWindowTitle(QCoreApplication::translate("CanCvns", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CanCvns: public Ui_CanCvns {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANCVNS_H
