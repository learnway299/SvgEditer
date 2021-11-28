#ifndef KOSOTEXT_H
#define KOSOTEXT_H

class QPainter;
class QPoint;
class QString;
#include "myshape.h"

class MyText : public MyShape
{
public:
    MyText(MyShape *parent = nullptr);

    MyText(const MyText &copyShape);

    ~ MyText(){}

    //绘制
    void virtual paint(QPainter &painter) override;
    //画布缩放坐标
    void virtual zoomChange(const qreal &factor) override;
    //图形缩放坐标
    void virtual zoomShape(const qreal &factor) override;
    //选中
//    bool virtual isSeclect(const QPoint &point) override;
    //拖动
    void virtual dragMove(const QPoint &beaginP, const QPoint &stopP) override;
    //虚线框
//    void virtual drawdotBox(QPainter &painter) override;

    MyShapeType virtual getType() override;

    //从文件获取对象
    void setSPos(const int &x,const int &y);

    void setDrawText(const QString &value);

    void setFontSize(const int &value);

    QString getDrawText() const;

protected:
    //文本
    QString drawText;
    int fontSize;
    int textWeight;
    int textHeight;
};

#endif // KOSOTEXT_H
