#ifndef KOSOFREELINE_H
#define KOSOFREELINE_H

class QPainter;
class QPoint;
#include "myshape.h"
#include <QList>

class MyFreeLine : public MyShape
{
public:
    MyFreeLine(MyShape *parent = nullptr);

    MyFreeLine(const MyFreeLine &copyShape);

    ~MyFreeLine(){}


    //绘制
    void virtual paint(QPainter &painter) override;
    //画布缩放坐标
    void virtual zoomChange(const qreal &factor) override;
    //图形缩放坐标
    void virtual zoomShape(const qreal &factor) override;
    //拖动
    void virtual dragMove(const QPoint &beaginP, const QPoint &stopP) override;

    MyShapeType virtual getType() override;

    //计算自由线的矩形区域
    void getArea();
    //添加点
    void addPoint(QPoint point);

private:
    QList<QPoint> pointList;
};

#endif // KOSOFREELINE_H
