#include "myrect.h"
#include "myshape.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QPen>
#include <QPoint>

MyRect::MyRect(MyShape *parent):MyShape(parent)
{

}

MyRect::MyRect(const MyRect &copyShape):MyShape(copyShape)
{

}

void MyRect::paint(QPainter &painter)
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
    painter.drawRect(start.x(), start.y(), end.x() - start.x(), end.y() - start.y());
}

MyShapeType MyRect::getType()
{
    return MyShapeType::rect;
}
