//#pragma once

//#include <gtest/gtest.h>
//#include "myshape.h"
//#include "myrect.h"
//#include "mytext.h"

//TEST(kososhapeTestCase, kososhapeTest) {
//    MyShape *test = new MyRect();
//    MyText *test01 = new MyText();
//    //test func setStart()、getStart()、setEnd()、getEnd()
//    QPoint testPoint(10,20);
//    test->setStart(testPoint);
//    test01->setEnd(testPoint);
//    bool startFlag = testPoint == test->getStart() ? true : false;
//    ASSERT_TRUE(startFlag);
//    bool endFlag = testPoint == test01->getEnd() ? true : false;
//    ASSERT_TRUE(endFlag);

//    //test func dragMove()
//    int x = 10, y = 20;
//    QPoint startPoint = test->getStart();
//    test->dragMove(QPoint(0,0),QPoint(x,y));
//    QPoint endPoint = test->getStart();
//    EXPECT_EQ(x, (endPoint.x() - startPoint.x()));
//    EXPECT_EQ(y, (endPoint.y() - startPoint.y()));
//    //test func isSeclect()
//    test->setStart(QPoint(0,0));
//    test->setEnd(QPoint(10,10));
//    EXPECT_FALSE(test->isSeclect(QPoint(5,20)));
//    EXPECT_TRUE(test->isSeclect(QPoint(5,5)));
//    //test func zoomChange()
//    int zoomInt = 2;
//    testPoint = test->getEnd();
//    test->zoomChange(zoomInt);
//    EXPECT_TRUE(test->getEnd() == testPoint * zoomInt);
//    //test func zoomShape()
//    test01->setStart(QPoint(0,0));
//    test01->setEnd(QPoint(10,10));
//    testPoint = test01->getStart();
//    test01->zoomShape(zoomInt);
//    EXPECT_TRUE(test01->getStart() == testPoint * zoomInt);
//    delete test;
//    delete test01;
//}
