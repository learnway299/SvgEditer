//#pragma once

//#include <gtest/gtest.h>
//#include "cancvns.h"
//TEST(cancvnsTestCase, cancvnsTest) {

//    CanCvns *test = new CanCvns();
//    QString tmpfileName(":/image/testFile/mySvg.svg");
//    QString tmpfileName01(":/image/testFile/notmySvg.svg");
//    //test func KosoSvgHander()
//    EXPECT_TRUE(test->KosoSvgHander(tmpfileName));
//    EXPECT_FALSE(test->KosoSvgHander(tmpfileName01));

//    //test func penstyleGetter()
//    QString DashArray("");
//    EXPECT_EQ(0, test->penstyleGetter(DashArray));
//    DashArray = QString ("12,6");
//    EXPECT_EQ(1, test->penstyleGetter(DashArray));
//    DashArray = QString ("3,6");
//    EXPECT_EQ(2, test->penstyleGetter(DashArray));
//    DashArray = QString ("12,6,3,6");
//    EXPECT_EQ(3, test->penstyleGetter(DashArray));
//    DashArray = QString ("12,6,3,6,3,6");
//    EXPECT_EQ(4, test->penstyleGetter(DashArray));

//    //test func transQColor()
//    QString tmpColorStr("#000000");
//    EXPECT_TRUE(test->transQColor(tmpColorStr) == QColor(0,0,0,0));
//    tmpColorStr = QString ("black");
//    EXPECT_TRUE(test->transQColor(tmpColorStr) == Qt::black);
//    tmpColorStr = QString ("none");
//    EXPECT_TRUE(test->transQColor(tmpColorStr) == Qt::gray);
//    delete test;
//}
