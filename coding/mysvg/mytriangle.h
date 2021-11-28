#ifndef KOSOTRIANGLE_H
#define KOSOTRIANGLE_H

class QPainter;
class QPoint;
#include "myshape.h"

class MyTriangle : public MyShape
{
public:
    MyTriangle(MyShape *parent = nullptr);

    MyTriangle(const MyTriangle &copyShape);

    ~ MyTriangle(){}

    //绘制
    void virtual paint(QPainter & painter) override;

    MyShapeType virtual getType() override;

};

#endif // KOSOTRIANGLE_H
