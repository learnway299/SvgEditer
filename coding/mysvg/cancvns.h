#ifndef CANCVNS_H
#define CANCVNS_H

#include <QWidget>
//#include <gtest/gtest_prod.h>
#include "myshape.h"

class MyShape;
class MyFreeLine;
class MyLine;
class MyRect;
class MyCircle;
class MyPentagon;
class MyTriangle;
class MyText;
class QMouseEvent;
class QPaintEvent;
class QWheelEvent;
class QSvgRenderer;
class QPixmap;
class QColor;
class QLineEdit;
class QPoint;
class QMenu;
class QAction;



namespace Ui {
class CanCvns;
}

class CanCvns : public QWidget
{
    Q_OBJECT

    //自定义信号
signals:
    //传给myStatusbar的信号量
    void tobarSizeInfo(int width, int height);

public:
    explicit CanCvns(QWidget *parent = nullptr);
    ~CanCvns();

    void change(const MyShapeType &tmp);

    void loadSvgFile(const QString &filename);

    void saveSvgFile(const QString &filename);

    //画笔颜色
    void setPencolor();
    //画布颜色
    void setBackcolor();
    //填充颜色
    void setFillcolor();
    //响应拖拽对象
    void setDragable();
    //响应鼠标的滚轮事件，使SVG图片能够通过鼠标滚轮的滚动进行缩放
    void wheelEvent(QWheelEvent *event) override;
    //新建画布
    void newCvns();
    //清除画布
    void clearCvns();

public slots:
    //设置画布尺寸
    void resetSize(const int &width, const int &height);
    //复制对象事件
    void onCopyshapeTriggered();
    //粘贴对象事件
    void onPasteshapeTriggered();
    //删除对象事件
    void onDeleteshapeTriggered();
    //画笔尺寸
    void resetpenSize(const int &pensize);
    //画笔样式
    void resetpenStyle(const int &StyleIndex);
    //二次编辑
    void onSecondeditTriggered();

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void onLeftClickOut();

private:
    Ui::CanCvns *ui;
    MyShapeType currShape;
    //画布 尺寸
    int mWidth;
    int mHeight;
    //画笔尺寸
    int penSize;
    //画笔样式
    int styleIndex;
    //记录坐标
    QPoint prePoint,copyPoint,pastePoint,areaSart,areaEnd;
    //生成对象、标记选中对象、要复制的对象
    MyShape *shape,*seclectedShape,*copyedShape;
    //标记可移动
    bool dragFlag;

    //标记鼠标释放
    bool releaseFlag;
    //标记是否为保存文件
    bool saveFlag;
    //标记打开文件是否为通用文件、是否打开
    bool fileType;
    bool fileOpen;
    //标记置于顶层、底层
    bool upORdown;

    bool copyFlag;
    bool editFlag;
    bool secondeditFlag;


    //存储图形对象
    QList<MyShape*> shapeList,copyShapeList,seclectedShapeList;
    QSvgRenderer *m_render;
    QPixmap pixMap;
    //画布全局颜色
    QColor brushColor;
    QColor penColor;
    //对象填充颜色
    QColor fillColor;
    QLineEdit *mEdit;
    //PenStyle
    QList<Qt::PenStyle> penStyleList;
    //标记自定义文件dec属性
    QString fileFlag;
    //右击删除 置于顶层、底层、二次编辑
    QMenu *rightClick;
    QAction *copyShape;
    QAction *pasteShape;
    QAction *deleteShape;
    QAction *toUp;
    QAction *toDown;
    QAction *secondEdit;

    void setMouseMenu();
    void resetMouseMenu();
    void paintPixmap(QPainter &painter);
    void zoomChange(const qreal &factor);
    void setInit();
    bool KosoSvgHander(const QString &filename);
    QColor transQColor(const QString &ColorStr);
    void swapShape();
    int penstyleGetter(const QString &Dasharray);
    void pasteCopedShape(MyShape *copedShape);
    void  drawSelectArea(QPainter &painter);
    void breakEdit();


//    FRIEND_TEST(cancvnsTestCase, cancvnsTest);
};

#endif // CANCVNS_H
