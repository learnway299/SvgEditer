/********************************************************************************
** Form generated from reading UI file 'mystatusbar.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSTATUSBAR_H
#define UI_MYSTATUSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myStatusbar
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *hlineEdit;
    QLabel *label_2;
    QLineEdit *wlineEdit;
    QLabel *label_3;
    QLineEdit *pensizeEdit;
    QLabel *label_4;
    QComboBox *StyleBox;

    void setupUi(QWidget *myStatusbar)
    {
        if (myStatusbar->objectName().isEmpty())
            myStatusbar->setObjectName(QString::fromUtf8("myStatusbar"));
        myStatusbar->resize(82, 192);
        myStatusbar->setMaximumSize(QSize(100, 16777215));
        gridLayout = new QGridLayout(myStatusbar);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(myStatusbar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(123, 209, 255);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        hlineEdit = new QLineEdit(myStatusbar);
        hlineEdit->setObjectName(QString::fromUtf8("hlineEdit"));
        hlineEdit->setStyleSheet(QString::fromUtf8("color: rgb(123, 209, 255);"));

        gridLayout->addWidget(hlineEdit, 1, 0, 1, 1);

        label_2 = new QLabel(myStatusbar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(123, 209, 255);"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        wlineEdit = new QLineEdit(myStatusbar);
        wlineEdit->setObjectName(QString::fromUtf8("wlineEdit"));
        wlineEdit->setStyleSheet(QString::fromUtf8("color: rgb(123, 209, 255);"));

        gridLayout->addWidget(wlineEdit, 3, 0, 1, 1);

        label_3 = new QLabel(myStatusbar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(123, 209, 255);"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        pensizeEdit = new QLineEdit(myStatusbar);
        pensizeEdit->setObjectName(QString::fromUtf8("pensizeEdit"));
        pensizeEdit->setStyleSheet(QString::fromUtf8("color: rgb(123, 209, 255);"));

        gridLayout->addWidget(pensizeEdit, 5, 0, 1, 1);

        label_4 = new QLabel(myStatusbar);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(123, 209, 255);"));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        StyleBox = new QComboBox(myStatusbar);
        StyleBox->addItem(QString());
        StyleBox->addItem(QString());
        StyleBox->addItem(QString());
        StyleBox->addItem(QString());
        StyleBox->addItem(QString());
        StyleBox->setObjectName(QString::fromUtf8("StyleBox"));
        StyleBox->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(StyleBox, 7, 0, 1, 1);


        retranslateUi(myStatusbar);

        QMetaObject::connectSlotsByName(myStatusbar);
    } // setupUi

    void retranslateUi(QWidget *myStatusbar)
    {
        myStatusbar->setWindowTitle(QCoreApplication::translate("myStatusbar", "Form", nullptr));
        label->setText(QCoreApplication::translate("myStatusbar", "height", nullptr));
        label_2->setText(QCoreApplication::translate("myStatusbar", "wdith", nullptr));
        label_3->setText(QCoreApplication::translate("myStatusbar", "penSize", nullptr));
        pensizeEdit->setText(QString());
        label_4->setText(QCoreApplication::translate("myStatusbar", "penStyle", nullptr));
        StyleBox->setItemText(0, QCoreApplication::translate("myStatusbar", "SolidLine", nullptr));
        StyleBox->setItemText(1, QCoreApplication::translate("myStatusbar", "DashLine", nullptr));
        StyleBox->setItemText(2, QCoreApplication::translate("myStatusbar", "DotLine", nullptr));
        StyleBox->setItemText(3, QCoreApplication::translate("myStatusbar", "DashDotLine", nullptr));
        StyleBox->setItemText(4, QCoreApplication::translate("myStatusbar", "DashDotDotLine", nullptr));

    } // retranslateUi

};

namespace Ui {
    class myStatusbar: public Ui_myStatusbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSTATUSBAR_H
