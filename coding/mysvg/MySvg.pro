#-------------------------------------------------
#
# Project created by QtCreator 2021-09-30T08:38:00
#
#-------------------------------------------------

QT       += core svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_ICONS = ./image/mysvg.ico
TARGET = MySvg
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    cancvns.cpp \
    main.cpp \
    mycircle.cpp \
    myfreeline.cpp \
    myline.cpp \
    mypentagon.cpp \
    myrect.cpp \
    myshape.cpp \
    mystatusbar.cpp \
    mysvg.cpp \
    mytext.cpp \
    mytriangle.cpp \
    unitTest/cancvnsTest.cpp \
    unitTest/mycircleTest.cpp \
    unitTest/myshapeTest.cpp \
    unitTest/mystatusbarTest.cpp \
    unitTest/mytextTest.cpp

HEADERS += \
    cancvns.h \
    mycircle.h \
    myfreeline.h \
    myline.h \
    mypentagon.h \
    myrect.h \
    myshape.h \
    mystatusbar.h \
    mysvg.h \
    mytext.h \
    mytriangle.h

FORMS += \
    cancvns.ui \
    mystatusbar.ui \
    mysvg.ui

SUBDIRS += \
    KOsoSvg.pro

DISTFILES += \
    KOsoSvg.pro.user \
    image/SVG.png \
    image/backcolor.png \
    image/backcolor_a.png \
    image/backcolor_off.png \
    image/backcolor_s.png \
    image/circle.png \
    image/circle_a.png \
    image/circle_s.png \
    image/line.png \
    image/line_a.png \
    image/line_s.png \
    image/muti.png \
    image/muti1.png \
    image/muti2.png \
    image/muti_a.png \
    image/muti_s.png \
    image/open.png \
    image/pen.png \
    image/pen_a.png \
    image/pen_s.png \
    image/pencolor_a.png \
    image/pencolor_off.png \
    image/pencolor_s.png \
    image/rectangle.png \
    image/rectangle_a.png \
    image/rectangle_s.png \
    image/save.png \
    image/text.png \
    image/text_a.png \
    image/text_s.png \
    image/backcolor.png \
    image/backcolor_a.png \
    image/backcolor_s.png \
    image/circle.png \
    image/circle_a.png \
    image/circle_s.png \
    image/line.png \
    image/line_a.png \
    image/line_s.png \
    image/muti.png \
    image/muti1.png \
    image/muti2.png \
    image/muti_a.png \
    image/muti_s.png \
    image/open.png \
    image/pen.png \
    image/pen_a.png \
    image/pen_s.png \
    image/pencolor.png \
    image/pencolor_a.png \
    image/pencolor_s.png \
    image/rectangle.png \
    image/rectangle_a.png \
    image/rectangle_s.png \
    image/save.png \
    image/size.png \
    image/size_a.png \
    image/size_s.png \
    image/SVG.png \
    image/text.png \
    image/text_a.png \
    image/text_s.png \
    image/backcolor.png \
    image/backcolor_a.png \
    image/backcolor_s.png \
    image/circle.png \
    image/circle_a.png \
    image/circle_s.png \
    image/line.png \
    image/line_a.png \
    image/line_s.png \
    image/muti.png \
    image/muti1.png \
    image/muti2.png \
    image/muti_a.png \
    image/muti_s.png \
    image/open.png \
    image/pen.png \
    image/pen_a.png \
    image/pen_s.png \
    image/pencolor.png \
    image/pencolor_a.png \
    image/pencolor_s.png \
    image/rectangle.png \
    image/rectangle_a.png \
    image/rectangle_s.png \
    image/save.png \
    image/select.png \
    image/select_a.png \
    image/select_s.png \
    image/size.png \
    image/size_a.png \
    image/size_s.png \
    image/SVG.png \
    image/text.png \
    image/text_a.png \
    image/text_s.png \
    unitTest/testFile/mySvg.svg \
    unitTest/testFile/notmySvg.svg

RESOURCES += \
    rec.qrc

#INCLUDEPATH += $$PWD/gtest/include
#LIBS += -L$$PWD/gtest/lib/   -lgtest


#INCLUDEPATH += $$PWD/Vld/include
#LIBS += -L$$PWD/Vld/lib/Win64/   -lvld
