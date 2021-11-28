#include "myline.h"
#include "myshape.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QPen>
#include <QPoint>

MyLine::MyLine(MyShape *parent):MyShape(parent)
{

}

MyLine::MyLine(const MyLine &copyShape):MyShape(copyShape)
{

}

void MyLine::paint(QPainter &painter)
{
    painter.setRenderHints(QPainter::Antialiasing,true);
    painter.setBrush(QColor(0,0,0,0));

    //画笔
    QPen pen;
    pen.setStyle(penStyle);
    pen.setWidth(penSize);
    pen.setColor(penColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    painter.drawLine(start,end);
}

MyShapeType MyLine::getType()
{
    return MyShapeType::line;
}
