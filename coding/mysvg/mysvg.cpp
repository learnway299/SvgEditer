#pragma once

#include "mysvg.h"
#include "ui_kososvg.h"
#include "cancvns.h"
#include "mystatusbar.h"

#include <QFileDialog>
#include <QScrollArea>

MySvg::MySvg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KosoSvg)
{
    ui->setupUi(this);
    msv = new CanCvns();
    scroll = new QScrollArea(this);
    scroll->setFrameShape(QFrame::NoFrame);
    scroll->setWidget(msv);
    scroll->setAlignment(Qt::AlignCenter);
    mstatusbar = new myStatusbar(this);
    ui->styletoolBar->addWidget(mstatusbar);
    this->setWindowTitle(tr("SVG工具"));
    this->setWindowIcon(QIcon(":/image/SVG.png"));
    setCentralWidget(scroll);
    msv->resetSize(500,500);
    mstatusbar->showsizeInfo(500,500);
    this->resize(600,600);
    mstatusbar->showPensize(3);
    msv->moveToThread(&mCanCvns);

    //画布传值给工具栏
    connect(msv, &CanCvns::tobarSizeInfo, mstatusbar, &myStatusbar::showsizeInfo);

    //工具栏传值给画布
    connect(mstatusbar, &myStatusbar::sizeInfo, msv, &CanCvns::resetSize);
    connect(mstatusbar, &myStatusbar::penSizeInfo, msv, &CanCvns::resetpenSize);
    connect(mstatusbar, &myStatusbar::penstyleInfo, msv, &CanCvns::resetpenStyle);

    connect(&mCanCvns, &QThread::finished, msv, &QObject::deleteLater);
}

MySvg::~MySvg()
{
    delete ui;
}

void MySvg::on_pen_action_triggered()
{
    msv->change(MyShapeType::freeline);
}

void MySvg::on_line_action_triggered()
{
    msv->change(MyShapeType::line);
}

void MySvg::on_reac_action_triggered()
{
    msv->change(MyShapeType::rect);
}

void MySvg::on_circle_action_triggered()
{
    msv->change(MyShapeType::circle);
}


void MySvg::on_hexagon_action_triggered()
{
    msv->change(MyShapeType::pentagon);
}

void MySvg::on_triangle_action_triggered()
{
    msv->change(MyShapeType::trangle);
}
void MySvg::on_text_action_triggered()
{
    msv->change(MyShapeType::text);
}

void MySvg::on_open_action_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("打开"),"/","svg files(*.svg)");
    if (filename.isEmpty())
        return;
    msv->loadSvgFile(filename);
}

void MySvg::on_save_action_triggered()
{
    QString newPath = QFileDialog::getSaveFileName(this, tr("Save SVG"),"/", tr("SVG files (*.svg)"));
    if (newPath.isEmpty())
        return;
    msv->saveSvgFile(newPath);
}

void MySvg::on_pencolor_action_triggered()
{
    msv->setPencolor();
}

void MySvg::on_backColor_action_triggered()
{
    msv->setBackcolor();
}

void MySvg::on_fill_action_triggered()
{
    msv->setFillcolor();
}

void MySvg::on_selector_action_triggered()
{
    msv->setDragable();
}


void MySvg::on_clear_action_triggered()
{
    msv->clearCvns();
}

void MySvg::on_new_action_triggered()
{
    msv->newCvns();
}
