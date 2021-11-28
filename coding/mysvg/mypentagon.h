#ifndef KOSOPENTAGON_H
#define KOSOPENTAGON_H

class QPainter;
class QPoint;
#include "myshape.h"

class MyPentagon : public MyShape
{
public:
    MyPentagon(MyShape *parent = nullptr);

    MyPentagon(const MyPentagon &copyShape);

    ~MyPentagon(){}

    //绘制
    void virtual paint(QPainter &painter) override;

    MyShapeType virtual getType() override;

};

#endif // KOSOPENTAGON_H
