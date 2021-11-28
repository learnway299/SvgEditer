#include "mypentagon.h"
#include "myshape.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QPen>
#include <QtGui/QPainterPath>
#include <QPoint>

MyPentagon::MyPentagon(MyShape *parent):MyShape(parent)
{

}

MyPentagon::MyPentagon(const MyPentagon &copyShape):MyShape(copyShape)
{

}

void MyPentagon::paint(QPainter &painter)
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
    QPainterPath drawpath;

    drawpath.moveTo((2 * start.x() + end.x())/3, start.y());
    drawpath.lineTo((start.x() + 2 * end.x())/3, start.y());
    drawpath.lineTo(end.x(), (start.y()+end.y())/2);
    drawpath.lineTo((start.x()+ 2 * end.x())/3, end.y());
    drawpath.lineTo((2 * start.x() + end.x())/3, end.y());
    drawpath.lineTo(start.x(), (start.y() + end.y())/2);
    drawpath.closeSubpath();
    painter.drawPath(drawpath);
}

MyShapeType MyPentagon::getType()
{
    return MyShapeType::pentagon;
}
