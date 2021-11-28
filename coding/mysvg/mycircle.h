#ifndef KOSOCIRCLE_H
#define KOSOCIRCLE_H

class QPainter;
class QPoint;
#include "myshape.h"
//#include <gtest/gtest_prod.h>

class MyCircle : public MyShape
{
public:
    MyCircle(MyShape *parent = nullptr);

    MyCircle(const MyCircle &copyShape);

    ~MyCircle(){}

    //绘制
    void virtual paint(QPainter &painter) override;

    MyShapeType virtual getType() override;

private:
    QPoint midPoint() const;
    int getWidth() const;
    int getHight() const;
//    FRIEND_TEST(kosocircleTestCase, kosocircleTest);
};

#endif // KOSOCIRCLE_H
