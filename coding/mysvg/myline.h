#ifndef KOSOLINE_H
#define KOSOLINE_H

class QPainter;
class QPoint;
#include "myshape.h"

class MyLine : public MyShape
{
public:
    MyLine(MyShape *parent = nullptr);

    MyLine(const MyLine &copyShape);

    ~MyLine(){}

    //绘制
    void virtual paint(QPainter &painter) override;

    MyShapeType virtual getType() override;

};

#endif // KOSOLINE_H
