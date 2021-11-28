#include "mytext.h"
#include "myshape.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QPen>
#include <QtGui/QFont>
#include <QPoint>
#include <QString>

MyText::MyText(MyShape *parent):MyShape(parent),drawText(QString("")),fontSize(36),textWeight(10),textHeight(10)
{
    fontSize = fontSize >0 && fontSize < 60 ? fontSize : 36;
}

MyText::MyText(const MyText &copyShape):MyShape(copyShape)
{
    drawText = copyShape.drawText;
    fontSize = fontSize >0 && fontSize < 60 ? fontSize : 36;
}

void MyText::paint(QPainter &painter)
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
    QFont font = painter.font();
    font.setPixelSize(fontSize);
    painter.setFont(font);

    painter.drawText(start+QPoint(0,fontSize),drawText);
    textWeight = painter.fontMetrics().width(drawText) + 10;
    textHeight = painter.fontMetrics().height() + 10;
    end.setX(start.x() + textWeight);
    end.setY(start.y() + textHeight);
}

void MyText::zoomChange(const qreal &factor)
{
    setStart(start * factor);
}

void MyText::zoomShape(const qreal &factor)
{
    const qreal currentZoom = factor;
    if ((factor < 1 && currentZoom < 0.1) || (factor > 1 && currentZoom > 10))
        return;
    setFontSize((int)(fontSize * factor));
}


void MyText::dragMove(const QPoint &beaginP, const QPoint &stopP)
{
    int movex = stopP.x() - beaginP.x();
    int movey = stopP.y() - beaginP.y();
    start.setX(start.x() + movex);
    start.setY(start.y() + movey);
}

MyShapeType MyText::getType()
{
    //若内容为空则不要
    if(drawText.isEmpty())
    {
        return MyShapeType::noshape;
    }
    return MyShapeType::text;
}

void MyText::setSPos(const int &x, const int &y)
{
    start.setX(x);
    start.setY(y);
}

void MyText::setDrawText(const QString &value)
{
    drawText = value;
}


void MyText::setFontSize(const int &value)
{
    fontSize = value >0 && value < 60 ? value : 36;
}

QString MyText::getDrawText() const
{
    return drawText;
}
