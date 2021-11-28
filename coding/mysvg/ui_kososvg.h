/********************************************************************************
** Form generated from reading UI file 'kososvg.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOSOSVG_H
#define UI_KOSOSVG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KosoSvg
{
public:
    QAction *pen_action;
    QAction *line_action;
    QAction *reac_action;
    QAction *circle_action;
    QAction *open_action;
    QAction *save_action;
    QAction *text_action;
    QAction *pencolor_action;
    QAction *backColor_action;
    QAction *height_action;
    QAction *weight_action;
    QAction *selector_action;
    QAction *hexagon_action;
    QAction *triangle_action;
    QAction *fill_action;
    QAction *clear_action;
    QAction *new_action;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *styletoolBar;

    void setupUi(QMainWindow *KosoSvg)
    {
        if (KosoSvg->objectName().isEmpty())
            KosoSvg->setObjectName(QString::fromUtf8("KosoSvg"));
        KosoSvg->resize(822, 459);
        KosoSvg->setStyleSheet(QString::fromUtf8(""));
        pen_action = new QAction(KosoSvg);
        pen_action->setObjectName(QString::fromUtf8("pen_action"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/pen.png"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QString::fromUtf8(":/image/pen_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QString::fromUtf8(":/image/pen_s.png"), QSize(), QIcon::Selected, QIcon::On);
        pen_action->setIcon(icon);
        line_action = new QAction(KosoSvg);
        line_action->setObjectName(QString::fromUtf8("line_action"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/line.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/image/line_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/image/line_s.png"), QSize(), QIcon::Selected, QIcon::On);
        line_action->setIcon(icon1);
        reac_action = new QAction(KosoSvg);
        reac_action->setObjectName(QString::fromUtf8("reac_action"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/image/rectangle.png"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/image/rectangle_a.png"), QSize(), QIcon::Active, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/image/rectangle_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/image/rectangle_s.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/image/rectangle_s.png"), QSize(), QIcon::Selected, QIcon::On);
        reac_action->setIcon(icon2);
        circle_action = new QAction(KosoSvg);
        circle_action->setObjectName(QString::fromUtf8("circle_action"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/circle.png"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/image/circle_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/image/circle_s.png"), QSize(), QIcon::Selected, QIcon::On);
        circle_action->setIcon(icon3);
        open_action = new QAction(KosoSvg);
        open_action->setObjectName(QString::fromUtf8("open_action"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        open_action->setIcon(icon4);
        save_action = new QAction(KosoSvg);
        save_action->setObjectName(QString::fromUtf8("save_action"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_action->setIcon(icon5);
        text_action = new QAction(KosoSvg);
        text_action->setObjectName(QString::fromUtf8("text_action"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/image/text.png"), QSize(), QIcon::Normal, QIcon::On);
        icon6.addFile(QString::fromUtf8(":/image/text_a.png"), QSize(), QIcon::Active, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/image/text_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon6.addFile(QString::fromUtf8(":/image/text_s.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/image/text_s.png"), QSize(), QIcon::Selected, QIcon::On);
        text_action->setIcon(icon6);
        pencolor_action = new QAction(KosoSvg);
        pencolor_action->setObjectName(QString::fromUtf8("pencolor_action"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/pencolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/image/pencolor.png"), QSize(), QIcon::Normal, QIcon::On);
        icon7.addFile(QString::fromUtf8(":/image/pencolor_a.png"), QSize(), QIcon::Active, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/image/pencolor_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon7.addFile(QString::fromUtf8(":/image/pencolor_s.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/image/pencolor_s.png"), QSize(), QIcon::Selected, QIcon::On);
        pencolor_action->setIcon(icon7);
        backColor_action = new QAction(KosoSvg);
        backColor_action->setObjectName(QString::fromUtf8("backColor_action"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/backcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/image/pencolor.png"), QSize(), QIcon::Normal, QIcon::On);
        icon8.addFile(QString::fromUtf8(":/image/backcolor_a.png"), QSize(), QIcon::Active, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/image/backcolor_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon8.addFile(QString::fromUtf8(":/image/backcolor_s.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/image/backcolor_s.png"), QSize(), QIcon::Selected, QIcon::On);
        backColor_action->setIcon(icon8);
        height_action = new QAction(KosoSvg);
        height_action->setObjectName(QString::fromUtf8("height_action"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/height.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/image/height.png"), QSize(), QIcon::Normal, QIcon::On);
        icon9.addFile(QString::fromUtf8(":/image/height_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon9.addFile(QString::fromUtf8(":/image/height_s.png"), QSize(), QIcon::Selected, QIcon::On);
        height_action->setIcon(icon9);
        weight_action = new QAction(KosoSvg);
        weight_action->setObjectName(QString::fromUtf8("weight_action"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/image/width.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon10.addFile(QString::fromUtf8(":/image/width.png"), QSize(), QIcon::Normal, QIcon::On);
        icon10.addFile(QString::fromUtf8(":/image/width_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon10.addFile(QString::fromUtf8(":/image/width_s.png"), QSize(), QIcon::Selected, QIcon::On);
        weight_action->setIcon(icon10);
        selector_action = new QAction(KosoSvg);
        selector_action->setObjectName(QString::fromUtf8("selector_action"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/image/select.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QString::fromUtf8(":/image/select.png"), QSize(), QIcon::Normal, QIcon::On);
        icon11.addFile(QString::fromUtf8(":/image/select_a.png"), QSize(), QIcon::Active, QIcon::Off);
        icon11.addFile(QString::fromUtf8(":/image/select_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon11.addFile(QString::fromUtf8(":/image/select_s.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon11.addFile(QString::fromUtf8(":/image/select_s.png"), QSize(), QIcon::Selected, QIcon::On);
        selector_action->setIcon(icon11);
        hexagon_action = new QAction(KosoSvg);
        hexagon_action->setObjectName(QString::fromUtf8("hexagon_action"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/image/hexagon.png"), QSize(), QIcon::Normal, QIcon::On);
        icon12.addFile(QString::fromUtf8(":/image/hexagon_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon12.addFile(QString::fromUtf8(":/image/hexagon_s.png"), QSize(), QIcon::Selected, QIcon::On);
        hexagon_action->setIcon(icon12);
        triangle_action = new QAction(KosoSvg);
        triangle_action->setObjectName(QString::fromUtf8("triangle_action"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/image/triangle.png"), QSize(), QIcon::Normal, QIcon::On);
        icon13.addFile(QString::fromUtf8(":/image/triangle_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon13.addFile(QString::fromUtf8(":/image/triangle_s.png"), QSize(), QIcon::Selected, QIcon::On);
        triangle_action->setIcon(icon13);
        fill_action = new QAction(KosoSvg);
        fill_action->setObjectName(QString::fromUtf8("fill_action"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/image/fill.png"), QSize(), QIcon::Normal, QIcon::On);
        icon14.addFile(QString::fromUtf8(":/image/fill_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon14.addFile(QString::fromUtf8(":/image/fill_s.png"), QSize(), QIcon::Selected, QIcon::On);
        fill_action->setIcon(icon14);
        clear_action = new QAction(KosoSvg);
        clear_action->setObjectName(QString::fromUtf8("clear_action"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/image/clear.png"), QSize(), QIcon::Normal, QIcon::On);
        clear_action->setIcon(icon15);
        new_action = new QAction(KosoSvg);
        new_action->setObjectName(QString::fromUtf8("new_action"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/image/newcancvs_s.png"), QSize(), QIcon::Normal, QIcon::On);
        icon16.addFile(QString::fromUtf8(":/image/newcancvs_a.png"), QSize(), QIcon::Active, QIcon::On);
        icon16.addFile(QString::fromUtf8(":/image/newcancvs.png"), QSize(), QIcon::Selected, QIcon::On);
        new_action->setIcon(icon16);
        centralWidget = new QWidget(KosoSvg);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        KosoSvg->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KosoSvg);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 822, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        KosoSvg->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KosoSvg);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        KosoSvg->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KosoSvg);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        KosoSvg->setStatusBar(statusBar);
        styletoolBar = new QToolBar(KosoSvg);
        styletoolBar->setObjectName(QString::fromUtf8("styletoolBar"));
        styletoolBar->setMinimumSize(QSize(80, 0));
        styletoolBar->setMaximumSize(QSize(90, 16777215));
        KosoSvg->addToolBar(Qt::RightToolBarArea, styletoolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(open_action);
        menu->addAction(save_action);
        menu_2->addAction(new_action);
        menu_2->addAction(clear_action);
        mainToolBar->addAction(selector_action);
        mainToolBar->addAction(pen_action);
        mainToolBar->addAction(line_action);
        mainToolBar->addAction(reac_action);
        mainToolBar->addAction(circle_action);
        mainToolBar->addAction(hexagon_action);
        mainToolBar->addAction(triangle_action);
        mainToolBar->addAction(text_action);
        styletoolBar->addAction(pencolor_action);
        styletoolBar->addAction(backColor_action);
        styletoolBar->addAction(fill_action);

        retranslateUi(KosoSvg);

        QMetaObject::connectSlotsByName(KosoSvg);
    } // setupUi

    void retranslateUi(QMainWindow *KosoSvg)
    {
        KosoSvg->setWindowTitle(QCoreApplication::translate("KosoSvg", "KosoSvg", nullptr));
        pen_action->setText(QCoreApplication::translate("KosoSvg", "\347\224\273\347\254\224", nullptr));
        line_action->setText(QCoreApplication::translate("KosoSvg", "\347\233\264\347\272\277", nullptr));
        reac_action->setText(QCoreApplication::translate("KosoSvg", "\347\237\251\345\275\242", nullptr));
        circle_action->setText(QCoreApplication::translate("KosoSvg", "\345\234\206", nullptr));
        open_action->setText(QCoreApplication::translate("KosoSvg", "\346\211\223\345\274\200SVG\346\226\207\344\273\266", nullptr));
        save_action->setText(QCoreApplication::translate("KosoSvg", "\344\277\235\345\255\230SVG\346\226\207\344\273\266", nullptr));
        text_action->setText(QCoreApplication::translate("KosoSvg", "\346\226\207\346\234\254", nullptr));
        pencolor_action->setText(QCoreApplication::translate("KosoSvg", "\347\224\273\347\254\224\351\242\234\350\211\262", nullptr));
        backColor_action->setText(QCoreApplication::translate("KosoSvg", "\347\224\273\345\270\203\350\211\262", nullptr));
        height_action->setText(QCoreApplication::translate("KosoSvg", "\347\224\273\345\270\203\345\260\272\345\257\270", nullptr));
#if QT_CONFIG(tooltip)
        height_action->setToolTip(QCoreApplication::translate("KosoSvg", "\347\224\273\345\270\203\351\253\230\345\272\246", nullptr));
#endif // QT_CONFIG(tooltip)
        weight_action->setText(QCoreApplication::translate("KosoSvg", "weight", nullptr));
#if QT_CONFIG(tooltip)
        weight_action->setToolTip(QCoreApplication::translate("KosoSvg", "\347\224\273\345\270\203\345\256\275\345\272\246", nullptr));
#endif // QT_CONFIG(tooltip)
        selector_action->setText(QCoreApplication::translate("KosoSvg", "selector", nullptr));
#if QT_CONFIG(tooltip)
        selector_action->setToolTip(QCoreApplication::translate("KosoSvg", "\351\200\211\346\213\251\345\231\250", nullptr));
#endif // QT_CONFIG(tooltip)
        hexagon_action->setText(QCoreApplication::translate("KosoSvg", "hexagon", nullptr));
#if QT_CONFIG(tooltip)
        hexagon_action->setToolTip(QCoreApplication::translate("KosoSvg", "\345\205\255\350\276\271\345\275\242", nullptr));
#endif // QT_CONFIG(tooltip)
        triangle_action->setText(QCoreApplication::translate("KosoSvg", "triangle", nullptr));
#if QT_CONFIG(tooltip)
        triangle_action->setToolTip(QCoreApplication::translate("KosoSvg", "\344\270\211\350\247\222\345\275\242", nullptr));
#endif // QT_CONFIG(tooltip)
        fill_action->setText(QCoreApplication::translate("KosoSvg", "fill", nullptr));
#if QT_CONFIG(tooltip)
        fill_action->setToolTip(QCoreApplication::translate("KosoSvg", "\345\241\253\345\205\205", nullptr));
#endif // QT_CONFIG(tooltip)
        clear_action->setText(QCoreApplication::translate("KosoSvg", "\346\270\205\351\231\244", nullptr));
        new_action->setText(QCoreApplication::translate("KosoSvg", "\346\226\260\345\273\272", nullptr));
        menu->setTitle(QCoreApplication::translate("KosoSvg", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("KosoSvg", "\347\224\273\345\270\203", nullptr));
        styletoolBar->setWindowTitle(QCoreApplication::translate("KosoSvg", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KosoSvg: public Ui_KosoSvg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOSOSVG_H
