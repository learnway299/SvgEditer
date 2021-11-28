#ifndef KOSORECT_H
#define KOSORECT_H

class QPainter;
class QPoint;
#include "myshape.h"

class MyRect : public MyShape
{
public:
    MyRect(MyShape *parent = nullptr);

    MyRect(const MyRect &copyShape);

    ~MyRect(){}

    //绘制
    void virtual paint(QPainter &painter) override;

    MyShapeType virtual getType() override;

};

#endif // KOSORECT_H
