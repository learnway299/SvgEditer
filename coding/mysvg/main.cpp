//#include <vld.h>
#include "mysvg.h"
#include <QApplication>
//#include "unitTest/myshapeTest.cpp"
//#include "unitTest/mytextTest.cpp"
//#include "unitTest/mycircleTest.cpp"
//#include "unitTest/cancvnsTest.cpp"
//#include "unitTest/mystatusbarTest.cpp"

int main(int argc, char *argv[])
{
//#if 0
    QApplication a(argc, argv);
    MySvg w;
    w.show();

    return a.exec();
//#else
//    QApplication a(argc, argv);
//    // 分析gtest程序的命令行参数
//    ::testing::InitGoogleTest(&argc, argv);

//    // 调用RUN_ALL_TESTS()运行所有测试用例
//    // main函数返回RUN_ALL_TESTS()的运行结果
//    return RUN_ALL_TESTS();
//#endif
}
