#include "mystatusbar.h"
#include "ui_mystatusbar.h"

myStatusbar::myStatusbar(QWidget *parent) :
    QWidget(parent),ui(new Ui::myStatusbar)
{
    ui->setupUi(this);
    //过滤非法输入
    QRegExp filter("[0-9]+$");
    validator = new QRegExpValidator(filter);
    ui->hlineEdit->setValidator(validator);
    ui->wlineEdit->setValidator(validator);
    ui->pensizeEdit->setValidator(validator);
    ui->hlineEdit->setAttribute(Qt::WA_InputMethodEnabled,false);
    ui->wlineEdit->setAttribute(Qt::WA_InputMethodEnabled,false);
    ui->pensizeEdit->setAttribute(Qt::WA_InputMethodEnabled,false);

}

myStatusbar::~myStatusbar()
{
    delete ui;
    delete validator;
}

void myStatusbar::showPensize(const int &penSize)
{
    ui->pensizeEdit->setText(QString::number(penSize));
}


void myStatusbar::showsizeInfo(int width, int height)
{
    width = width > 1800 ? 1800 : width;
    width = width < 1 ? 200 : width;
    height = height > 900 ? 900 : height;
    height = height < 1 ? 100 : height;
    ui->wlineEdit->setText(QString::number(width));
    ui->hlineEdit->setText(QString::number(height));
}

void myStatusbar::on_hlineEdit_textChanged(const QString &arg1)
{
    int weight = ui->wlineEdit->text().toInt();
    weight = weight > 1800 ? 1800 : weight;
    weight = weight < 1 ? 200 : weight;
    int height  = arg1.toInt();
    height = height > 900 ? 900 : height;
    height = height < 1 ? 100 : height;
    showsizeInfo(weight, height);
    emit sizeInfo(weight, height);
}

void myStatusbar::on_wlineEdit_textChanged(const QString &arg1)
{
    int height = ui->hlineEdit->text().toInt();
    height = height > 1200 ? 1200 : height;
    height = height < 1 ? 100 : height;
    int weight = arg1.toInt();
    weight = weight > 1800 ? 1800 : weight;
    weight = weight < 1 ? 200 : weight;
    showsizeInfo(weight, height);
    emit sizeInfo(weight, height);
}

void myStatusbar::on_StyleBox_currentIndexChanged(const int &index)
{
    emit penstyleInfo(index);
}

void myStatusbar::on_pensizeEdit_textChanged(const QString &arg1)
{
    int pensize = arg1.toInt();
    pensize = pensize > 15 ? 15 : pensize;
    pensize = pensize < 1  ? 1  : pensize;
    showPensize(pensize);
    emit penSizeInfo(pensize);
}
