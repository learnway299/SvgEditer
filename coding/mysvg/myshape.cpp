#include "myshape.h"
#include <QtGui/QColor>

MyShape::MyShape(QObject *parent):QObject(parent),start(QPoint(0,0)),end(QPoint(0,0)),
    fillColor(QColor(0,0,0,0)),penColor(Qt::gray),penSize(3),penStyle(Qt::SolidLine)
{

}

MyShape::MyShape(const MyShape &copyShape)
{
    start = copyShape.start;
    end = copyShape.end;
    fillColor = copyShape.fillColor;
    penColor = copyShape.penColor;
    penSize = copyShape.penSize;
    penStyle = copyShape.penStyle;
}

QPoint MyShape::getStart() const
{
    return start;
}

void MyShape::setStart(const QPoint &value)
{
    start = value;
}

QPoint MyShape::getEnd() const
{
    return end;
}

void MyShape::setEnd(const QPoint &value)
{
    end = value;
}

void MyShape::setFillColor(const QColor &value)
{
    fillColor = value;
}

void MyShape::setPenColor(const QColor &value)
{
    penColor = value;
}

void MyShape::setPenSize(const int &value)
{
    penSize = value;
}

void MyShape::setPenStyle(const Qt::PenStyle &value)
{
    penStyle = value;
}


void MyShape::setPos(const int &x1, const int &y1, const int &x2, const int &y2)
{
    start.setX(x1);
    start.setY(y1);
    end.setX(x2);
    end.setY(y2);
}

void MyShape::drawdotBox(QPainter &painter)
{
    QRect boundingRect;
    QPen pen = painter.pen();
    pen.setColor(Qt::red);
    pen.setWidth(penSize);
    pen.setStyle(penStyle);
    painter.setPen(pen);
    pen.setBrush(QColor(0,0,0,0));
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(boundingRect.adjusted(start.x(), start.y(), end.x(),  end.y()));
}

void MyShape::zoomChange(const qreal &factor)
{
    const qreal currentZoom = factor;
    if ((factor < 1 && currentZoom < 0.1) || (factor > 1 && currentZoom > 10))
        return;
    setStart(getStart() * factor);
    setEnd(getEnd() * factor);
}

void MyShape::zoomShape(const qreal &factor)
{
    const qreal currentZoom = factor;
    if ((factor < 1 && currentZoom < 0.1) || (factor > 1 && currentZoom > 10))
        return;
    setEnd(getEnd() * factor);
}

bool MyShape::isSeclect(const QPoint &point)
{
    bool selectedFlag = false;
    //起点左上角 终点右下角
    if(start.x() < end.x() && start.y() < end.y())
    {
        selectedFlag = isInArea(point.x(),point.y(),start.x(),start.y(),end.x(),end.y())  ? true : selectedFlag;
        //起点右上角 终点左下角
    }else if(end.x() < start.x() && start.y() < end.y())
    {
        selectedFlag = isInArea(point.x(),point.y(),end.x(),start.y(),start.x(),end.y())  ? true : selectedFlag;
        //起点右下角 终点左上角
    }  else if(start.x() < end.x() && end.y() < start.y())
    {
        selectedFlag = isInArea(point.x(),point.y(),start.x(),end.y(),end.x(),start.y())  ? true : selectedFlag;
        //起点左下角 终点右上角
    }    else if(end.x() < start.x() && end.y() < start.y())
    {
        selectedFlag = isInArea(point.x(),point.y(),end.x(),end.y(),start.x(),start.y())  ? true : selectedFlag;
    }
    return selectedFlag;
}

bool MyShape::isAreaSeclect(const QPoint &pointX, const QPoint &pointY)
{
    bool selectedFlag = false;
    //多选区域 起点左上角 终点右下角
    if(pointX.x() < pointY.x() && pointX.y() < pointY.y())
    {
        selectedFlag = isInArea(start.x(),start.y(),pointX.x(),pointX.y(),pointY.x(),pointY.y())  ? true : selectedFlag;
        selectedFlag = isInArea(start.x(),end.y(),pointX.x(),pointX.y(),pointY.x(),pointY.y())  ? true : selectedFlag;
        selectedFlag = isInArea(end.x(),start.y(),pointX.x(),pointX.y(),pointY.x(),pointY.y())  ? true : selectedFlag;
        selectedFlag = isInArea(end.x(),end.y(),pointX.x(),pointX.y(),pointY.x(),pointY.y())  ? true : selectedFlag;
        //多选区域 起点右下角 终点左上角
    }else if(pointY.x() < pointX.x() && pointY.y() < pointX.y())
    {
        selectedFlag = isInArea(start.x(),start.y(),pointY.x(),pointY.y(),pointX.x(),pointX.y())  ? true : selectedFlag;
        selectedFlag = isInArea(start.x(),end.y(),pointY.x(),pointY.y(),pointX.x(),pointX.y())  ? true : selectedFlag;
        selectedFlag = isInArea(end.x(),start.y(),pointY.x(),pointY.y(),pointX.x(),pointX.y())  ? true : selectedFlag;
        selectedFlag = isInArea(end.x(),end.y(),pointY.x(),pointY.y(),pointX.x(),pointX.y())  ? true : selectedFlag;
        //多选区域 起点右上角 终点左下角
    }else if(pointY.x() < pointX.x() && pointX.y() < pointY.y())
    {
        selectedFlag = isInArea(start.x(),start.y(),pointY.x(),pointX.y(),pointX.x(),pointY.y())  ? true : selectedFlag;
        selectedFlag = isInArea(start.x(),end.y(),pointY.x(),pointX.y(),pointX.x(),pointY.y())  ? true : selectedFlag;
        selectedFlag = isInArea(end.x(),start.y(),pointY.x(),pointX.y(),pointX.x(),pointY.y())  ? true : selectedFlag;
        selectedFlag = isInArea(end.x(),end.y(),pointY.x(),pointX.y(),pointX.x(),pointY.y())  ? true : selectedFlag;
        //多选区域  起点左下角 终点右上角
    }else if(pointX.x() < pointY.x() && pointY.y() < pointX.y())
    {
        selectedFlag = isInArea(start.x(),start.y(),pointX.x(),pointY.y(),pointY.x(),pointX.y())  ? true : selectedFlag;
        selectedFlag = isInArea(start.x(),end.y(),pointX.x(),pointY.y(),pointY.x(),pointX.y())  ? true : selectedFlag;
        selectedFlag = isInArea(end.x(),start.y(),pointX.x(),pointY.y(),pointY.x(),pointX.y())  ? true : selectedFlag;
        selectedFlag = isInArea(end.x(),end.y(),pointX.x(),pointY.y(),pointY.x(),pointX.y())  ? true : selectedFlag;
    }
    return selectedFlag;
}

bool MyShape::isInArea(int x, int y, int x1, int y1, int x2, int y2)
{
    return ((x1 < x ) && (x < x2) && (y1 < y) & (y < y2)) ? true : false;
}

void MyShape::dragMove(const QPoint &beaginP, const QPoint &stopP)
{
    int movex = stopP.x() - beaginP.x();
    int movey = stopP.y() - beaginP.y();

    start.setX(start.x() + movex);
    start.setY(start.y() + movey);
    end.setX(end.x() + movex);
    end.setY(end.y() + movey);
}

