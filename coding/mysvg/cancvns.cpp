#pragma once
#include "cancvns.h"
#include "ui_cancvns.h"
#include "myshape.h"
#include "myfreeline.h"
#include "myline.h"
#include "myrect.h"
#include "mycircle.h"
#include "mypentagon.h"
#include "mytriangle.h"
#include "mytext.h"

#include <QMouseEvent>
#include <QPaintEvent>
#include <QWheelEvent>
#include <QPainter>
#include <QPixmap>
#include <QBrush>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include <QColor>
#include <QColorDialog>
#include <QLineEdit>
#include <QByteArray>
#include <QPen>
#include <QXmlStreamReader>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

CanCvns::CanCvns(QWidget *parent) :
    QWidget(parent), ui(new Ui::CanCvns),
    currShape(noshape),mWidth(500),mHeight(500),penSize(3),styleIndex(0),prePoint(QPoint(10,10)),
    copyPoint(QPoint(10,10)),pastePoint(QPoint(10,10)),areaSart(QPoint(10,10)),areaEnd(QPoint(10,10)),
    shape(NULL),seclectedShape(nullptr),copyedShape(nullptr),dragFlag(false),releaseFlag(false),saveFlag(false),
    fileType(false),fileOpen(false),upORdown(false),copyFlag(false),editFlag(false),secondeditFlag(false),
    m_render(nullptr),brushColor(Qt::white),penColor(Qt::gray),fillColor(QColor(0,0,0,0))
{
    ui->setupUi(this);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    fileFlag = QString("My_Svg");
    setInit();

    m_render = new QSvgRenderer(this);
    mEdit = new QLineEdit(this);
    mEdit->setFont(QFont("STXingKai",18));
    mEdit->hide();

    penStyleList << Qt::SolidLine <<Qt::DashLine << Qt::DotLine <<Qt::DashDotLine << Qt::DashDotDotLine;
    setMouseMenu();
}

CanCvns::~CanCvns()
{
    clearCvns();
    delete ui;
}

void CanCvns::change(const MyShapeType &tmp)
{
    setInit();
    currShape = tmp;
}

void CanCvns::loadSvgFile(const QString &filename)
{
    setInit();
    //清除缓冲区
    m_render->load(QString(" "));

    fileType = KosoSvgHander(filename);
    if(!fileType)
    {
        m_render->load(filename);
        fileOpen = true;
    }
}

void CanCvns::saveSvgFile(const QString &filename)
{
    setInit();
    QSvgGenerator generator;
    generator.setFileName(filename);
    generator.setSize(QSize(this->width(),this->height()));
    generator.setViewBox(QRect(0, 0, this->width(), this->height()));
    generator.setTitle(tr("MySVG Drawed"));
    generator.setDescription(fileFlag);
    saveFlag = true;
    QPainter painter(this);
    painter.begin(&generator);
    paintPixmap(painter);
    painter.end();
}

void CanCvns::setPencolor()
{
    breakEdit();
    QColor tmpColor = QColorDialog::getColor(Qt::gray,this,tr("选择画笔颜色"));
    if (false == tmpColor.isValid())
    {
        return;
    }
    penColor = tmpColor;
    if(nullptr != seclectedShape)
    {
        seclectedShape->setPenColor(penColor);
    }else if(seclectedShapeList.size() > 0)
    {
        for(auto tmpshape : seclectedShapeList)
        {
            tmpshape->setPenColor(penColor);
        }
    }else if(shapeList.size() > 0)
    {
        for(auto tmpshape : shapeList)
        {
            tmpshape->setPenColor(penColor);
        }
    }
    update();
}

void CanCvns::setBackcolor()
{
    breakEdit();
    QColor tmpColor = QColorDialog::getColor(Qt::white,this,tr("选择画布颜色"));
    if (false == tmpColor.isValid())
    {
        return;
    }
    brushColor = tmpColor;
    update();
}

void CanCvns::setFillcolor()
{
    breakEdit();
    QColor tmpColor = QColorDialog::getColor(Qt::white,this,tr("选择填充颜色"));
    if (false == tmpColor.isValid())
    {
        return;
    }
    fillColor = tmpColor;
    if(nullptr != seclectedShape)
    {
        seclectedShape->setFillColor(fillColor);
    }else if(seclectedShapeList.size() > 0)
    {
        for(auto tmpshape : seclectedShapeList)
        {
            tmpshape->setFillColor(fillColor);
        }
    }else if(shapeList.size() > 0)
    {
        for(auto tmpshape : shapeList)
        {
            tmpshape->setFillColor(fillColor);
        }
    }
}

void CanCvns::setDragable()
{
    setInit();
    dragFlag = true;
}


void CanCvns::wheelEvent(QWheelEvent *event)
{
    breakEdit();
    //diff值表示每次滚轮滚动一定的值，图片大小改变的比例
    const double diff = 0.1;
    //利用QWheelEvent的delta()函数获得滚轮滚动的距离值，通过此值来判断滚轮滚动的方向
    qreal factor = event->delta() > 0 ? 1 + diff : 1 - diff;

    //缩放图形
    if(nullptr != seclectedShape)
    {
        seclectedShape->zoomShape(factor);
        update();
    }else if(seclectedShapeList.size() > 0)
    {
        for(auto tmpshape : seclectedShapeList)
        {
            tmpshape->zoomShape(factor);
        }
        update();
    }else
    {
        factor = int( this->width() * factor) < 50   ? factor + diff : factor;
        factor = int( this->height() * factor) > 900 ? factor - diff : factor;
        factor = int( this->height() * factor) < 25  ? factor + diff : factor;
        factor = int( this->width() * factor) > 1800 ? factor - diff : factor;
        //缩放画布
        mWidth = int( this->width() * factor);
        mHeight = int( this->height() * factor);
        zoomChange(factor);

        //调整尺寸
        emit tobarSizeInfo(mWidth,mHeight);
        event->accept();
    }
}

void CanCvns::newCvns()
{
    setInit();
    if(shapeList.size() > 0 || fileOpen)
    {
        QMessageBox msg(this);
        msg.setWindowTitle(tr("新建画布"));
        msg.setWindowIcon(QIcon(":/image/newcancvs_s.png"));
        msg.setText(tr("clear the cancvns yes or no"));
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        if(msg.exec() == QMessageBox::Ok)
        {
            clearCvns();
            brushColor = Qt::white;
            resetSize(500,500);
            emit tobarSizeInfo(500,500);
        }else{

        }
    }else
    {
        brushColor = Qt::white;
        resetSize(500,500);
        emit tobarSizeInfo(500,500);
    }
    update();
}

void CanCvns::clearCvns()
{
    setInit();
    if(shapeList.size() > 0)
    {
        foreach(MyShape* tmpshape , shapeList)
        {
            if(tmpshape)
            {
                shapeList.removeOne(tmpshape);
                delete tmpshape;
                tmpshape = nullptr;
            }
        }

        shape = nullptr;
        seclectedShape = nullptr;
        copyedShape = nullptr;
        copyShapeList.clear();
        seclectedShapeList.clear();
    }

    if(nullptr != shape)
    {
        delete shape;
        shape = nullptr;
    }

    if(false == fileType)
    {
        m_render->load(QString(" "));
        fileOpen = false;
    }
    update();
}

void CanCvns::resetSize(const int &width, const int &height)
{
    //缩放画布
    qreal wfactor = width / this->width();
    qreal hfactor = height / this->height();
    mWidth = width;
    mHeight = height;
    pixMap.scaled(wfactor, hfactor,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    //调整尺寸
    this->resize(mWidth,mHeight);
    pixMap.scaled(mWidth,mHeight);
    update();
}


void CanCvns::onCopyshapeTriggered()
{
    if(nullptr != seclectedShape)
    {
        copyedShape = seclectedShape;
        copyShapeList.clear();
        copyFlag = true;
    }else if (seclectedShapeList.size() > 0)
    {
        copyShapeList.clear();
        for(auto tmpshape : seclectedShapeList)
        {
            if(tmpshape->isAreaSeclect(areaSart,areaEnd))
            {
                copyShapeList << tmpshape;
            }
        }
        copyedShape = nullptr;
        copyFlag = true;
    }
}

void CanCvns::onPasteshapeTriggered()
{
    if(nullptr != copyedShape)
    {
        pasteCopedShape(copyedShape);
    }else if (copyShapeList.size() > 0)
    {
        for(auto tmpshape : copyShapeList)
        {
            pasteCopedShape(tmpshape);
        }
    }
    update();
}

void CanCvns::onDeleteshapeTriggered()
{
    if(nullptr != seclectedShape)
    {
        if(seclectedShape == shape)
        {
            shape = nullptr;
        }
        if(seclectedShape == copyedShape)
        {
            copyedShape = nullptr;
        }

        if(copyShapeList.contains(seclectedShape))
        {
            copyShapeList.removeOne(seclectedShape);
        }
        if(seclectedShapeList.contains(seclectedShape))
        {
            seclectedShapeList.removeOne(seclectedShape);
        }

        shapeList.removeOne(seclectedShape);
        delete seclectedShape;
        seclectedShape = nullptr;
    }else if (seclectedShapeList.size() > 0)
    {
        for(auto tmpshape : seclectedShapeList)
        {
            if(tmpshape == shape)
            {
                shape = nullptr;
            }
            if(tmpshape == copyedShape)
            {
                copyedShape = nullptr;
            }
            seclectedShapeList.removeOne(tmpshape);
            if(shapeList.contains(tmpshape))
            {
                shapeList.removeOne(tmpshape);
            }
            if(copyShapeList.contains(tmpshape))
            {
                copyShapeList.removeOne(tmpshape);
            }
            delete tmpshape;
            tmpshape = nullptr;
        }

    }
    update();
}
void CanCvns::resetpenSize(const int &pensize)
{
    breakEdit();
    penSize = pensize;
    if(nullptr != seclectedShape)
    {
        seclectedShape->setPenSize(penSize);
    }else if(seclectedShapeList.size() > 0)
    {
        for(auto tmpshape : seclectedShapeList)
        {
            tmpshape->setPenSize(penSize);
        }
    }else if(shapeList.size() > 0)
    {
        for(auto tmpshape : shapeList)
        {
            tmpshape->setPenSize(penSize);
        }
    }
    update();
}

void CanCvns::resetpenStyle(const int &StyleIndex)
{
    breakEdit();
    styleIndex = StyleIndex;
    if(nullptr != seclectedShape)
    {
        seclectedShape->setPenStyle(penStyleList[styleIndex]);
    }else if(seclectedShapeList.size() > 0)
    {
        for(auto tmpshape : seclectedShapeList)
        {
            tmpshape->setPenStyle(penStyleList[styleIndex]);
        }
    }else if(shapeList.size() > 0)
    {
        for(auto tmpshape : shapeList)
        {
            tmpshape->setPenStyle(penStyleList[styleIndex]);
        }
    }
    update();
}

void CanCvns::onSecondeditTriggered()
{
    if(nullptr == seclectedShape || MyShapeType::text != seclectedShape->getType())
        return;
    //二次绘制文字
    mEdit->setFocus();
    mEdit->setGeometry(seclectedShape->getStart().x(),seclectedShape->getStart().y(),90,40);
    mEdit->setText(static_cast<MyText*>(seclectedShape)->getDrawText());
    static_cast<MyText*>(seclectedShape)->setDrawText("");
    secondeditFlag = true;
    update();
    mEdit->show();
    connect(mEdit, &QLineEdit::textEdited, this, [&]{
        mEdit->setFixedSize(mEdit->fontMetrics().width(mEdit->text()) + 10, mEdit->fontMetrics().height() * 2);});
    connect(mEdit, &QLineEdit::editingFinished, this, [&]{});
}


void CanCvns::paintEvent(QPaintEvent *event)
{
    QPainter painter(&pixMap);
    saveFlag = false;
    paintPixmap(painter);
}

void CanCvns::mousePressEvent(QMouseEvent *event)
{
    prePoint = event->pos();
    breakEdit();

    if(currShape != MyShapeType::noshape && Qt::LeftButton == event->button())
    {
        switch (currShape)
        {
        case MyShapeType::freeline:
        {
            shape = new MyFreeLine();
            break;
        }
        case MyShapeType::line:
        {
            shape = new MyLine();
            break;
        }
        case MyShapeType::rect:
        {
            shape = new MyRect();
            break;
        }
        case MyShapeType::circle:
        {
            shape = new MyCircle();
            break;
        }
        case MyShapeType::pentagon:
        {
            shape = new MyPentagon();
            break;
        }
        case MyShapeType::trangle:
        {
            shape = new MyTriangle();
            break;
        }
        case MyShapeType::text:
        {
            if(false == editFlag)
            {
                shape = new MyText();
                mEdit->setGeometry(event->x(),event->y(),90,40);
                mEdit->setPlaceholderText("input");
                mEdit->setFocus();
                mEdit->show();
                connect(mEdit, &QLineEdit::textEdited, this, [&]{
                    mEdit->setFixedSize(mEdit->fontMetrics().width(mEdit->text()) + 10, mEdit->fontMetrics().height() * 2);
                });
                connect(mEdit, &QLineEdit::editingFinished, this, [&]{});
                editFlag = true;
            }
            break;
        }
        default:
        {
            shape = nullptr;
            break;
        }
        }

        if(nullptr != shape)
        {
            //绘制自由线
            if(MyShapeType::freeline == shape->getType())
            {
                static_cast<MyFreeLine*>(shape)->addPoint(event->pos());
            }
            shape->setPenSize(penSize);
            shape->setPenStyle(penStyleList[styleIndex]);
            shape->setPenColor(penColor);
            shape->setStart(event->pos());
        }
    }else if(event->button() == Qt::LeftButton && dragFlag)
    {
        seclectedShape = nullptr;
        //确定选中的对象
        foreach(MyShape * preshape, shapeList)
        {
            if(preshape->isSeclect(prePoint))
            {
                seclectedShape = preshape;
            }else
            {
            }
        }

        if(nullptr != seclectedShape)
        {
            seclectedShapeList.clear();
        }else
        {
            areaSart = event->pos();
        }
    }else if (event->button() == Qt::RightButton)
    {
        onLeftClickOut();
        if(copyFlag)
        {
            pastePoint = event->pos();
        }else
        {
            copyPoint = event->pos();
        }
        resetMouseMenu();
        rightClick->popup(event->globalPos());
    }else
    {
        setDragable();
    }
    releaseFlag = false;
}

void CanCvns::mouseMoveEvent(QMouseEvent *event)
{
    if(dragFlag)
    {
        if(nullptr != seclectedShape)
        {
            seclectedShape->dragMove(prePoint,event->pos());
        }else if(seclectedShapeList.size() > 0)
        {
            for (auto tmpshape : seclectedShapeList)
            {
                tmpshape->dragMove(prePoint,event->pos());
            }
        }else if(nullptr == seclectedShape)
        {
            areaEnd = event->pos();
        }
        prePoint = event->pos();
        update();
    }else if(nullptr != shape && false == releaseFlag)
    {
        if(MyShapeType::text != currShape && MyShapeType::freeline != currShape)
        {
            shape->setEnd(event->pos());
        }

        if(MyShapeType::freeline == currShape)
        {
            static_cast<MyFreeLine*>(shape)->addPoint(event->pos());
            static_cast<MyFreeLine*>(shape)->getArea();
        }else
        {
        }
        update();
    }
}


void CanCvns::mouseReleaseEvent(QMouseEvent *event)
{
    if(dragFlag)
    {
        if(nullptr != seclectedShape)
        {
            seclectedShape->dragMove(prePoint,event->pos());
            prePoint = event->pos();
            update();
        }else if(seclectedShapeList.size()>0)
        {
            for (auto tmpshape : seclectedShapeList)
            {
                tmpshape->dragMove(prePoint,event->pos());
            }
            prePoint = event->pos();
            update();
        }else if(nullptr == seclectedShape)
        {
            areaEnd = event->pos();
            for(auto tmpshape : shapeList)
            {
                if(tmpshape->isAreaSeclect(areaSart,areaEnd))
                {
                    seclectedShapeList << tmpshape;
                }
            }
            if(seclectedShapeList.size() > 0)
            {
                update();
            }
        }
    }else if(nullptr != shape)
    {
        if(MyShapeType::text != currShape && MyShapeType::freeline != currShape)
        {
            shape->setEnd(event->pos());
        }
        if( MyShapeType::freeline == currShape)
        {
            static_cast<MyFreeLine*>(shape)->addPoint(event->pos());
            static_cast<MyFreeLine*>(shape)->getArea();
            update();
        }else
        {
            update();
        }

        if(true == editFlag)
        {
        }else
        {
            onLeftClickOut();
        }
    }
    releaseFlag = true;
    update();
}

void CanCvns::onLeftClickOut()
{
    if(nullptr != shape)
    {
        if(MyShapeType::text == shape->getType())
        {
        } else if(MyShapeType::noshape == shape->getType() || shape->getStart() == shape->getEnd()
                  || 0 == (shape->getStart().x() * shape->getEnd().x()))
        {
            delete shape;
            shape = nullptr;
        }else
        {
            shapeList<<shape;
            shape = nullptr;
        }
    }
}


void CanCvns::setMouseMenu()
{
    rightClick = new QMenu(this);
    copyShape = new QAction(rightClick);
    pasteShape = new QAction(rightClick);
    deleteShape = new QAction(rightClick);
    toUp = new QAction(rightClick);
    toDown = new QAction(rightClick);
    secondEdit = new QAction(rightClick);
    copyShape->setText(tr("复制"));
    pasteShape->setText(tr("粘贴"));
    deleteShape->setText(tr("删除"));
    toUp->setText(tr("置于顶层"));
    toDown->setText(tr("置于底层"));
    secondEdit->setText(tr("编辑文本"));
    copyShape->setIcon(QIcon(":/image/copyshape.png"));
    pasteShape->setIcon(QIcon(":/image/pasteshape.png"));
    deleteShape->setIcon(QIcon(":/image/deleteshape.png"));
    toUp->setIcon(QIcon(":/image/toup.png"));
    toDown->setIcon(QIcon(":/image/todown.png"));
    secondEdit->setIcon(QIcon(":/image/secondedit.png"));
    rightClick->addAction(copyShape);
    rightClick->addAction(pasteShape);
    rightClick->addAction(deleteShape);
    rightClick->addAction(toUp);
    rightClick->addAction(toDown);
    rightClick->addAction(secondEdit);
    connect(deleteShape,SIGNAL(triggered()),this,SLOT(onDeleteshapeTriggered()));
    connect(copyShape,SIGNAL(triggered()),this,SLOT(onCopyshapeTriggered()));
    connect(pasteShape,SIGNAL(triggered()),this,SLOT(onPasteshapeTriggered()));
    connect(toUp,&QAction::triggered,this,[&]{ upORdown = true; swapShape();});
    connect(toDown,&QAction::triggered,this,[&]{ upORdown = false; swapShape();});
    connect(secondEdit,SIGNAL(triggered()),this,SLOT(onSecondeditTriggered()));
}

void CanCvns::resetMouseMenu()
{
    copyShape->setEnabled(false);
    //当未选中单个对象
    if(nullptr == seclectedShape)
    {
        //存在复制的对象指针
        if(nullptr != copyedShape || copyShapeList.size() > 0)
        {
            pasteShape->setEnabled(true);
        }else
        {
            pasteShape->setEnabled(false);
        }
        // 选中多个对象
        if(seclectedShapeList.size() > 0)
        {
            copyShape->setEnabled(true);
            deleteShape->setEnabled(true);
        }else
        {
            copyShape->setEnabled(false);
            deleteShape->setEnabled(false);
        }
        toUp->setEnabled(false);
        toDown->setEnabled(false);
        secondEdit->setEnabled(false);
        update();
    }else     //当选中单个对象
    {
        //当未选中单个text对象
        if(MyShapeType::text == seclectedShape->getType())
        {
            secondEdit->setEnabled(true);
        }else
        {
            secondEdit->setEnabled(false);
        }
        copyShape->setEnabled(true);
        pasteShape->setEnabled(false);
        deleteShape->setEnabled(true);
        toUp->setEnabled(true);
        toDown->setEnabled(true);
    }
}

void CanCvns::paintPixmap(QPainter &painter)
{
    painter.setRenderHints(QPainter::Antialiasing,true);
    painter.begin(this);
    //画布背景色brushColor
    painter.setBrush(brushColor);
    painter.drawRect(0, 0, this->width(), this->height());

    //画文件
    if(nullptr != m_render && false == fileType)
    {
        pixMap.fill(Qt::transparent);
        pixMap.scaled(this->size(),Qt::KeepAspectRatio);
        m_render->render(&painter);
    }

    //设置透明
    painter.setBrush(QColor(0,0,0,0));

    //画界面
    if(shapeList.size()>0)
    {
        foreach(MyShape * tmpshape, shapeList)
        {
            tmpshape->paint(painter);
        }
    }

    if(nullptr != shape && false == saveFlag)
    {
        if(MyShapeType::noshape == shape->getType() || shape->getStart() == shape->getEnd()
                || 0 == (shape->getStart().x() * shape->getEnd().x()))
        {

        }else
        {
            shape->paint(painter);
            //绘制虚线边框
            if( currShape != MyShapeType::noshape && !dragFlag)
            {
                shape->drawdotBox(painter);
            }
        }
    }
    if(true == dragFlag && false == saveFlag && false == editFlag)
    {
        if(nullptr != seclectedShape)
        {
            //绘制虚线边框
            seclectedShape->drawdotBox(painter);
        }else
        {
            if(seclectedShapeList.size()>0)
            {
                for (auto tmpshape : seclectedShapeList)
                {
                    tmpshape->drawdotBox(painter);
                }
            }
        }
    }
    if(false == saveFlag && nullptr == shape && 0 == seclectedShapeList.size() && nullptr == seclectedShape)
    {
        drawSelectArea(painter);
    }

    painter.end();
}

void CanCvns::zoomChange(const qreal &factor)
{
    const qreal currentZoom = factor;
    if ((factor < 1 && currentZoom < 0.1) || (factor > 1 && currentZoom > 10))
        return;
    foreach(MyShape * tmpshape, shapeList)
    {
        tmpshape->zoomChange(factor);
    }
    if(nullptr != shape)
    {
        shape->zoomChange(factor);
    }
}

void CanCvns::setInit()
{
    breakEdit();
    dragFlag = false;
    seclectedShapeList.clear();
    copyFlag = false;
    saveFlag = false;
    fillColor = QColor(0,0,0,0);
    fileType = false;
    copyFlag = false;
    //表示当前功能为非图形绘制
    currShape = MyShapeType::noshape;
}

bool CanCvns::KosoSvgHander(const QString &filename)
{
    QXmlStreamReader reader;
    QList<MyShape*> tmpList;
    //记录属性
    QString dasharray = "";
    int tmpStyle = 0;
    int stroke_width = 3;
    int font_size = 28;


    QFile file(filename);
    if (false == file.open(QFile::ReadOnly | QFile::Text)) {
        return false;
    }

    //存储点坐标
    QString  points = "";
    QStringList pointlist;
    //填充色
    QString fillColor = "";
    QString mfillColor = "";

    //画笔色
    QString strokeColor = "";
    //标记打开文件类型
    bool fileType = false;
    //标记线
    bool polylineFlag = false;
    //标记文本
    bool textFlag = false;
    //标记画布尺寸
    bool sizeFlag = true;
    //标记矩形
    bool rectFlag = false;
    //标记圆
    bool circleFlag = false;
    //标记多边形
    bool pathFlag = false;
    //区别是否为自己生成的文件
    QString descText = "";
    //存储文本
    QString textText = "";
    //存储类型
    MyShapeType shapetype = MyShapeType::noshape;

    int x = 0,y = 0,width = 0,height = 0,sx = 0,sy = 0,mwidth = 0,mheight = 0;

    //将文件设置成xml阅读器的输入设备
    reader.setDevice(&file);

    //外部循环，未到文件结尾就一直循环读取
    while (false == reader.atEnd())
    {
        reader.readNext();
        shapetype = MyShapeType::noshape;
        if (reader.name() == "g")
        {
            if(false == points.isEmpty())
            {
                points.replace("M","");
                points.replace("L","");
                points.replace(","," ");
                pointlist = points.split(' ');
                //待完善
                if(points.contains('c') || points.contains('z') || points.contains('C') || points.contains('Z'))
                {
                    fileType = false;
                    file.close();
                    return  fileType;
                }
            }
            if(true == pathFlag)
            {
                if(pointlist.size() == 8)
                {
                    shape = new MyTriangle();
                    shapetype = MyShapeType::trangle;
                    shape->setPos(pointlist[0].toInt(),pointlist[5].toInt(),pointlist[2].toInt(),pointlist[3].toInt());
                    shape->setFillColor(transQColor(fillColor));
                }else if(pointlist.size() == 14)
                {
                    shape = new MyPentagon();
                    shapetype = MyShapeType::pentagon;
                    shape->setPos(pointlist[10].toInt(),pointlist[1].toInt(),pointlist[4].toInt(),pointlist[7].toInt());
                    shape->setFillColor(transQColor(fillColor));
                }else if(pointlist.size() > 14)
                {
                    shape = new MyFreeLine();
                    shapetype = MyShapeType::freeline;
                    for (int i=0; i< pointlist.size(); i++)
                    {
                        if( i % 2 == 0 )
                        {
                            static_cast<MyFreeLine*>(shape)->addPoint(QPoint(pointlist[i].toInt(),pointlist[i+1].toInt()));
                        }
                    }
                    static_cast<MyFreeLine*>(shape)->getArea();
                }else
                {
                }
                points.clear();

            }else if(true == polylineFlag)
            {
                points.replace(',',' ');
                pointlist = points.split(' ');

                if(pointlist.size() == 5)
                {
                    shape = new MyLine();
                    shapetype = MyShapeType::line;
                    shape->setPos(pointlist[0].toInt(),pointlist[1].toInt(),pointlist[2].toInt(),pointlist[3].toInt());
                }else
                {
                    fileType = false;
                }
                points.clear();
            }else if(true == rectFlag && false == sizeFlag)
            {
                shape = new MyRect();
                shapetype = MyShapeType::rect;
                shape->setPos(x, y, x + width,y + height);
                shape->setFillColor(transQColor(fillColor));
            }else if(true == circleFlag)
            {
                shape = new MyCircle();
                shapetype = MyShapeType::circle;
                shape->setPos(x - width, y - height, x + width, y + height);
                shape->setFillColor(transQColor(fillColor));
            }else if(true == textFlag)
            {
                shape = new MyText();
                shapetype = MyShapeType::text;
                static_cast<MyText*>(shape)->setSPos(sx , sy);
                static_cast<MyText*>(shape)->setDrawText(textText);
            }else
            {
            }

            if( shapetype != MyShapeType::noshape)
            {
                shape->setPenColor(transQColor(strokeColor));
                shape->setPenStyle(penStyleList[tmpStyle]);
                shape->setPenSize(stroke_width);
                if(shapetype == MyShapeType::text)
                {
                    static_cast<MyText*>(shape)->setFontSize(font_size);
                }
                tmpList<<shape;
            }

            fillColor = reader.attributes().value("fill").toString();
            strokeColor = reader.attributes().value("stroke").toString();
            dasharray = reader.attributes().value("stroke-dasharray").toString();
            tmpStyle = penstyleGetter(dasharray);
            stroke_width = reader.attributes().value("stroke-width").toInt();
            font_size = reader.attributes().value("font-size").toInt();

            polylineFlag = false;
            rectFlag = false;
            circleFlag = false;
            textFlag = false;
            pathFlag = false;
        }

        else if (reader.name() == "text")
        {
            textFlag = true;
            sx = reader.attributes().value("x").toInt();
            sy = reader.attributes().value("y").toInt();
            textText = reader.readElementText();
        }else if (reader.name() == "desc")
        {
            descText = reader.readElementText();
            if(descText == fileFlag)
            {
                fileType = true;
            }else{
                file.close();
                return false;
            }
        }
        else if (reader.name() == "polyline")
        {
            polylineFlag = true;
            points +=  reader.attributes().value("points");
        } else if (reader.name() == "path")
        {
            pathFlag = true;
            points +=  reader.attributes().value("d");
        } else if (reader.name() == "rect")
        {
            if(reader.attributes().value("x").toInt() == 0)
            {
                if(sizeFlag)
                {
                    mwidth = reader.attributes().value("width").toInt();
                    mheight = reader.attributes().value("height").toInt();
                    mfillColor = fillColor;
                }
                sizeFlag = false;
            }else if(reader.attributes().value("width").toInt() != 0)
            {
                rectFlag = true;
                x = reader.attributes().value("x").toInt();
                y = reader.attributes().value("y").toInt();
                width = reader.attributes().value("width").toInt();
                height = reader.attributes().value("height").toInt();
            }
        } else if (reader.name() == "ellipse")
        {
            if(reader.attributes().value("rx").toInt() != 0){
                circleFlag = true;
                x = reader.attributes().value("cx").toInt();
                y = reader.attributes().value("cy").toInt();
                width = reader.attributes().value("rx").toInt();
                height = reader.attributes().value("ry").toInt();
            }
        }  else
        {
            continue;
        }
    }
    //关闭文件，如果读取发生错误（hasError()）或者文件有错误，输出错误信息，返回false,
    file.close();

    if(true == fileType)
    {
        resetSize(mwidth,mheight);
        brushColor = transQColor(mfillColor);
        if(tmpList.size()>0)
        {
            foreach (MyShape*  tmPShape , tmpList)
            {
                shapeList << tmPShape;
            }
        }
        update();
    }
    shape = nullptr;
    return fileType;
}

QColor CanCvns::transQColor(const QString &ColorStr)
{
    if(!ColorStr.startsWith("#"))
    {
        if(ColorStr == "black")
        {
            return Qt::black;
        }else if(ColorStr == "none")
        {
            return Qt::gray;
        }else
        {
            return Qt::white;
        }
    }else if(ColorStr == "#000000" )
    {
        return QColor(0,0,0,0);
    }else
    {
        QString tmps="0x"+ColorStr.right(6);
        return QColor(tmps.toUInt(NULL,16));
    }
}

void CanCvns::swapShape()
{
    MyShape *tmpshape = seclectedShape;
    if( shapeList.size() > 1)
    {
        if(true == upORdown)
        {
            shapeList.removeOne(tmpshape);
            tmpshape = nullptr;
            shapeList.push_back(seclectedShape);
            update();
        }else
        {
            shapeList.removeOne(tmpshape);
            tmpshape = nullptr;
            shapeList.push_front(seclectedShape);
            update();
        }
    }
}

int CanCvns::penstyleGetter(const QString &Dasharray)
{
    QStringList tmpstyle = Dasharray.split(",");
    if(tmpstyle.size() == 4)
    {
        return 3;
    }else if(tmpstyle.size() == 6)
    {
        return 4;
    }else if(tmpstyle.size() == 2)
    {
        int ax = tmpstyle.at(0).toInt();
        int bx = tmpstyle.at(1).toInt();
        if(ax < bx)
        {
            return 2;
        }else
        {
            return 1;
        }
    }
    return 0;
}

void CanCvns::pasteCopedShape( MyShape *copedShape)
{
    if(nullptr == copedShape)
        return;
    switch(copedShape->getType())
    {
    case MyShapeType::freeline:
    {
        shape = new MyFreeLine(*static_cast<MyFreeLine*>(copedShape));
        break;
    }
    case MyShapeType::line:
    {
        shape = new MyLine(*static_cast<MyLine*>(copedShape));
        break;
    }
    case MyShapeType::rect:
    {
        shape = new MyRect(*static_cast<MyRect*>(copedShape));
        break;
    }
    case MyShapeType::circle:
    {
        shape = new MyCircle(*static_cast<MyCircle*>(copedShape));
        break;
    }
    case MyShapeType::pentagon:
    {
        shape = new MyPentagon(*static_cast<MyPentagon*>(copedShape));
        break;
    }
    case MyShapeType::trangle:
    {
        shape = new MyTriangle(*static_cast<MyTriangle*>(copedShape));
        break;
    }
    case MyShapeType::text:
    {
        shape = new MyText(*static_cast<MyText*>(copedShape));
        break;
    }
    default:
    {
        shape = nullptr;
        break;
    }
    }
    if(nullptr != shape)
    {
        shape->dragMove(copyPoint,pastePoint);
        shapeList<<shape;
        shape = nullptr;
    }
    update();
}

void CanCvns::drawSelectArea(QPainter &painter)
{
    QRect boundingRect;
    QPen pen = painter.pen();
    pen.setColor(Qt::cyan);
    pen.setWidth(penSize);
    pen.setStyle(penStyleList[styleIndex]);
    painter.setPen(pen);
    pen.setBrush(Qt::NoBrush);
    painter.setBrush(Qt::NoBrush);
    if(false == releaseFlag)
    {
        painter.drawRect(boundingRect.adjusted(areaSart.x(), areaSart.y(), areaEnd.x(),  areaEnd.y()));
    }
}

void CanCvns::breakEdit()
{
    if(true == secondeditFlag)
    {
        static_cast<MyText*>(seclectedShape)->setDrawText(mEdit->text());
        mEdit->hide(); mEdit->clear();
        disconnect(mEdit,&QLineEdit::editingFinished,0,0);
        secondeditFlag = false;
        update();
    }
    if(shape != nullptr && true == editFlag)
    {
        static_cast<MyText*>(shape)->setDrawText(mEdit->text());
        disconnect(mEdit,&QLineEdit::editingFinished,0,0);
        mEdit->hide(); mEdit->clear(); editFlag = false;
        if(MyShapeType::text == shape->getType())
        {
            shapeList<<shape;
            shape = nullptr;
        }
        update();
    }
}
