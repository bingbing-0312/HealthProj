#include "titlebar.h"

TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    ptitleLabel1=new QLabel(this);
    ptitleLabel2=new QLabel(this);
    ptitleLabel3=new QLabel(this);
    ptitleLabel4=new QLabel(this);
    ptitleLabel5=new QLabel(this);
    ptitleLabel6=new QLabel(this);

    ptitleLabel1->setText("设备：xd001 备注：001");
    ptitleLabel1->setStyleSheet("color: rgb(255, 255, 255);font: 11pt \"黑体\";");
    ptitleLabel1->setGeometry(50,-30,200,100);//(x,y,宽度,大小)

    ptitleLabel2->setText("小人");
    ptitleLabel2->setStyleSheet("color: rgb(255, 255, 255);font: 11pt \"黑体\";");
    ptitleLabel2->setGeometry(0,-30,40,100);//(x,y,宽度,大小)

    ptitleLabel3->setText("云");
    ptitleLabel3->setStyleSheet("color: rgb(255, 255, 255);font: 11pt \"黑体\";");
    ptitleLabel3->setGeometry(600,-30,40,100);//(x,y,宽度,大小)

    ptitleLabel4->setText("感号");
    ptitleLabel4->setStyleSheet("color: rgb(255, 255, 255);font: 11pt \"黑体\";");
    ptitleLabel4->setGeometry(650,-30,40,100);//(x,y,宽度,大小)

    ptitleLabel5->setText("个人");
    ptitleLabel5->setStyleSheet("color: rgb(255, 255, 255);font: 11pt \"黑体\";");
    ptitleLabel5->setGeometry(700,-30,40,100);//(x,y,宽度,大小)

    ptitleLabel6->setText("放大");
    ptitleLabel6->setStyleSheet("color: rgb(255, 255, 255);font: 11pt \"黑体\";");
    ptitleLabel6->setGeometry(750,-30,40,100);//(x,y,宽度,大小)
}

void TitleBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
