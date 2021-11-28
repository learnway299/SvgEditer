#include "mytriangle.h"
#include "myshape.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QPen>
#include <QtGui/QFont>
#include <QtGui/QPainterPath>
#include <QPoint>

MyTriangle::MyTriangle(MyShape *parent):MyShape(parent)
{

}

MyTriangle::MyTriangle(const MyTriangle &copyShape):MyShape(copyShape)
{

}

void MyTriangle::paint(QPainter &painter)
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

    drawpath.moveTo(start.x(),end.y());
    drawpath.lineTo(end.x(), end.y());
    drawpath.lineTo((start.x()+end.x())/2,start.y());
    drawpath.closeSubpath();
    painter.drawPath(drawpath);
}

MyShapeType MyTriangle::getType()
{
    return MyShapeType::trangle;
}

