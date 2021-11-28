#include "myfreeline.h"
#include "myshape.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QPen>
#include <QtGui/QPainterPath>
#include <QPoint>

MyFreeLine::MyFreeLine(MyShape *parent):MyShape(parent)
{
}

MyFreeLine::MyFreeLine(const MyFreeLine &copyShape):MyShape(copyShape)
{
    if(copyShape.pointList.size()>0)
    {
        for(auto point : copyShape.pointList)
        {
            addPoint(point);
        }
    }
}

void MyFreeLine::paint(QPainter &painter)
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
    QPainterPath drawpath;

    if(pointList.size()>0)
    {
        drawpath.moveTo(pointList[0].x(),pointList[0].y());
        for(auto point : pointList)
        {
            drawpath.lineTo(point.x(),point.y());

        }
    }
    painter.drawPath(drawpath);
}

void MyFreeLine::zoomChange(const qreal &factor)
{
    const qreal currentZoom = factor;
    if ((factor < 1 && currentZoom < 0.1) || (factor > 1 && currentZoom > 10))
        return;
    for(auto &point : pointList)
    {
        point *= factor;
    }
    getArea();
}

void MyFreeLine::zoomShape(const qreal &factor)
{
    const qreal currentZoom = factor;
    if ((factor < 1 && currentZoom < 0.1) || (factor > 1 && currentZoom > 10))
        return;

    for(auto &point : pointList)
    {
        point.setY(point.y() * factor);
    }
    getArea();
}

void MyFreeLine::dragMove(const QPoint &beaginP, const QPoint &stopP)
{
    int movex = stopP.x() - beaginP.x();
    int movey = stopP.y() - beaginP.y();

    for(auto &point : pointList)
    {
        point.setX(point.x() + movex);
        point.setY(point.y() + movey);
    }
    getArea();
}

MyShapeType MyFreeLine::getType()
{
    if(pointList.size()>0)
    {
        return MyShapeType::freeline;
    }
    return MyShapeType::noshape;
}

void MyFreeLine::getArea()
{
    int minx,miny,maxx,maxy;
    minx =  pointList[0].x();
    miny =  pointList[0].y();
    maxx =  pointList[0].x();
    maxy =  pointList[0].y();
    for(int j = 0; j<pointList.size() - 1; ++j)
    {
        minx = minx > pointList[j].x() ? pointList[j].x() : minx;
        miny = miny > pointList[j].y() ? pointList[j].y() : miny;
        maxx = maxx > pointList[j].x() ? maxx : pointList[j].x();
        maxy = maxy > pointList[j].y() ? maxy : pointList[j].y();
    }
    start.setX(minx);
    start.setY(miny);
    end.setX(maxx);
    end.setY(maxy);
}

void MyFreeLine::addPoint(QPoint point)
{
    pointList.push_back(point);
}
