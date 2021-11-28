#ifndef KOSOSHAPE_H
#define KOSOSHAPE_H

#include <QObject>
#include <QtGui/QPainter>
#include <QPoint>
//#include <gtest/gtest_prod.h>

class QColor;

enum MyShapeType
{
    freeline,
    line,
    rect,
    circle,
    pentagon,
    trangle,
    text,
    noshape
};

class MyShape:public QObject
{
    Q_OBJECT

public:
    MyShape(QObject *parent = nullptr);

    MyShape(const MyShape &copyShape);

    virtual  ~MyShape(){}

    QPoint getStart() const;

    void setStart(const QPoint &value);

    QPoint getEnd() const;

    void setEnd(const QPoint &value);

    void setFillColor(const QColor &value);

    void setPenColor(const QColor &value);

    void setPenSize(const int &value);

    void setPenStyle(const Qt::PenStyle &value);

    //从文件获取对象
    void setPos(const int &x1,const int &y1,const int &x2,const int &y2);
    //虚线框
    void virtual drawdotBox(QPainter &painter);
    //绘制
    void virtual paint(QPainter &painter) = 0;
    //画布缩放坐标
    void virtual zoomChange(const qreal &factor);
    //图形缩放坐标
    void virtual zoomShape(const qreal &factor);
    //选中
    bool virtual isSeclect(const QPoint &point);
    bool virtual isAreaSeclect(const QPoint &pointX, const QPoint &pointY);
    bool isInArea(int x, int y, int x1, int y1, int x2, int y2);

    //拖动
    void virtual dragMove(const QPoint &beaginP, const QPoint &stopP);
    //判断是否为文本对象
    MyShapeType virtual getType() = 0;


protected:

    QPoint start;
    QPoint end;
    QColor fillColor;
    QColor penColor;
    int penSize;
    Qt::PenStyle penStyle;

//    FRIEND_TEST(kososhapeTestCase, kososhapeTest);
};

#endif // KOSOSHAPE_H
