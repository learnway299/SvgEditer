#ifndef MYSTATUSBAR_H
#define MYSTATUSBAR_H

#include <QWidget>
//#include <gtest/gtest_prod.h>

class QValidator;
namespace Ui {
class myStatusbar;
}

class myStatusbar : public QWidget
{
    Q_OBJECT

signals:
    //传给myStatusbar的信号量
    void sizeInfo(int width, int height);
    void penSizeInfo(int penSize);
    void penstyleInfo(int penStyle);

public:
    explicit myStatusbar(QWidget *parent = 0);
    ~myStatusbar();
    void showPensize(const int &penSize);


public slots:
    void showsizeInfo(int width,int height);

private slots:
    void on_hlineEdit_textChanged(const QString &arg1);

    void on_wlineEdit_textChanged(const QString &arg1);

    void on_StyleBox_currentIndexChanged(const int &index);

    void on_pensizeEdit_textChanged(const QString &arg1);

private:
    Ui::myStatusbar *ui;
    QValidator *validator;
//    FRIEND_TEST(myStatusbarTestCase, myStatusbarTest);
};

#endif // MYSTATUSBAR_H
