#include "hrwidget.h"
#include<QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPixmap>
HRWidget::HRWidget(QWidget *parent) : QWidget(parent)
{

}

void HRWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    hrl1->setText("80");
    hrl1->setStyleSheet("background-color:rgb(0,255,0);");
    hrl2->setText("bpm");
    hrl2->setStyleSheet("background-color:rgb(0,255,0);");


    //创建窗口对象，初始化
    QWidget *hrleftWidget =new QWidget;
    hrleftWidget->setStyleSheet("background-color:rgb(255,0,0);");


    //创建布局器
    QVBoxLayout *hrlayout =new QVBoxLayout;

    //将窗口添加到布局器中
    hrlayout->addWidget(hrleftWidget);

    //80与bpm的位置
    hrlayout->addWidget(hrleftWidget);
    hrlayout->addWidget(hrl1,0,Qt::AlignCenter);
    hrlayout->addWidget(hrl2,0,Qt::AlignRight|Qt::AlignTop);

    hrleftWidget->setLayout(hrlayout);











}
