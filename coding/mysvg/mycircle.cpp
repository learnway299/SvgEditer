#include "mycircle.h"
#include "myshape.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QPen>
#include <QPoint>

MyCircle::MyCircle(MyShape *parent):MyShape(parent)
{

}

MyCircle::MyCircle(const MyCircle &copyShape):MyShape(copyShape)
{

}

void MyCircle::paint(QPainter &painter)
{
    painter.setRenderHints(QPainter::Antialiasing,true);
    painter.setBrush(fillColor);
    //画笔
    QPen pen;
    pen.setStyle(penStyle);
    pen.setWidth(penSize);
    pen.setColor(penColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    painter.drawEllipse(midPoint(),getWidth(),getHight());
}

MyShapeType MyCircle::getType()
{
    return MyShapeType::circle;
}

QPoint MyCircle::midPoint() const
{
    int tmpx = (start.x() + end.x())/2;
    int tmpy = (start.y() + end.y())/2;
    return QPoint(tmpx,tmpy);
}

int MyCircle::getWidth() const
{
    return (start.x() - end.x())/2;
}

int MyCircle::getHight() const
{
    return (start.y() - end.y())/2;
}

