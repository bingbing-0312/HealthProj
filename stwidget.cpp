#include "stwidget.h"
#include"hrwidget.h"
#include<QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
STWidget::STWidget(QWidget *parent) : QWidget(parent)
{

}

void STWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    //ST\PVC内容及样式
    stl1->setText("ST1 -?-");
    stl1->setStyleSheet("background-color:rgb(0,255,0);");
    stl2->setText("ST2 -?-");
    stl2->setStyleSheet("background-color:rgb(0,255,0);");
    stl3->setText("PVCs -?-");
    stl3->setStyleSheet("background-color:rgb(0,255,0);");

    //窗体
    QWidget *strightWidget =new QWidget;
    strightWidget->setStyleSheet("background-color:rgb(0,255,0);");

    //布局
     QVBoxLayout *stlayout = new QVBoxLayout;
     stlayout->addWidget(strightWidget);
     stlayout->addWidget(stl1,0,Qt::AlignTop);
     stlayout->addWidget(stl2,0,Qt::AlignCenter);
     stlayout->addWidget(stl3,0,Qt::AlignBottom);

     strightWidget->setLayout(stlayout);

     //标题栏
     hrsttil1->setText("HR");
     hrsttil1->setStyleSheet("background-color:rgb(255,255,255);");
     hrsttil2->setText("ST");
     hrsttil2->setStyleSheet("background-color:rgb(255,255,255);");
     hrsttil3->setText(" ");
     hrsttil3->setStyleSheet("background-color:rgb(255,255,255);");

     QWidget *hrsttiWidget =new QWidget;
     hrsttiWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

     //布局
      QHBoxLayout *hrsttilayout = new QHBoxLayout;
      hrsttilayout->addWidget(hrsttiWidget);
      hrsttilayout->addWidget(hrsttil1,0,Qt::AlignLeft);
      hrsttilayout->addWidget(hrsttil2,0,Qt::AlignCenter);
      hrsttilayout->addWidget(hrsttil3,0,Qt::AlignRight);
      hrsttiWidget->setStyleSheet("background-color:rgb(75, 75, 75)");
      hrsttiWidget->setLayout(hrsttilayout);


      //整体布局
      QWidget *hrstWidget1=new QWidget;
      QWidget *hrstWidget2=new QWidget;
      QVBoxLayout *hrstlayout = new QVBoxLayout;

      //标题和内容1:4
      hrstlayout->setStretchFactor(hrstWidget1,1);
      hrstlayout->setStretchFactor(hrstWidget2,4);


      hrstWidget1->setLayout(hrsttilayout);
      hrstWidget2->setLayout(hrlayout);
      hrstWidget2->setLayout(stlayout);
}
