#include "co2widget.h"

CO2Widget::CO2Widget(QWidget *parent) : QWidget(parent)
{
  this->setStyleSheet("background:rgb(0,0,0)");
    //几个Layout
    QVBoxLayout *layoutResp = new QVBoxLayout;
    QHBoxLayout *layoutHead = new QHBoxLayout;
    QHBoxLayout *layoutBody = new QHBoxLayout;
    QHBoxLayout *layoutBottom = new QHBoxLayout;
    //几个Wiget
    QWidget *head = new QWidget;
    head->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    QWidget *body = new QWidget;
    QWidget *bottom = new QWidget;
    //头部标签
    QLabel *title = new QLabel;
    QLabel *setting = new QLabel;
    title->setStyleSheet("color:rgb(255, 255, 255);font: 11pt , Adobe 黑体 Std R;");
    //中部标签
    QLabel *nothing1 = new QLabel;
    QLabel *data = new QLabel;
    QLabel *bpm = new QLabel;
    data->setStyleSheet("color:yellow;font: 30pt , Adobe 黑体 Std R;");
    bpm->setStyleSheet("color:yellow;font: 11pt , Adobe 黑体 Std R;");
    //尾部标签
    //QLabel *nothing2 = new QLabel;
    QLabel *ins = new QLabel;
    QLabel *awrr = new QLabel;
    ins->setStyleSheet("color:yellow;font: 11pt , Adobe 黑体 Std R;");
    awrr->setStyleSheet("color:yellow;font: 11pt , Adobe 黑体 Std R;");
    //头部标签数据写入
    QPixmap *pix = new QPixmap;
    pix->load("setting.jpg");
    title->setText("CO2");
    setting->setPixmap(*pix);

    //中部标签数据写入
    nothing1->setText("     ");
    data->setText("-?-");
    bpm->setText("mmHg");

    //尾部标签写入
    ins->setText("ins -?-  ");
    awrr->setText("  awrr -?-");

    //头部布局
    layoutHead->addWidget(title,0,Qt::AlignLeft);
    layoutHead->addWidget(setting, 0 ,Qt::AlignRight );
    head->setStyleSheet("background-color:rgb(75, 75, 75)");
    head->setLayout(layoutHead);
    //中部布局
    layoutBody->addWidget(nothing1);
    layoutBody->addWidget(data, 0, Qt::AlignCenter|Qt::AlignBottom);
    layoutBody->addWidget(bpm ,0 ,Qt::AlignRight | Qt::AlignTop);
//    layoutBody->setStretch(1, 3);
//    layoutBody->setStretch(2, 4);
//    layoutBody->setStretch(3, 3);
    body->setLayout(layoutBody);
    //尾部布局
    layoutBottom->addWidget(ins, 0, Qt::AlignCenter|Qt::AlignTop);
    layoutBottom->addWidget(awrr, 0, Qt::AlignCenter|Qt::AlignTop);
    bottom->setLayout(layoutBottom);

    //整体布局
    layoutResp->addWidget(head,0, Qt::AlignTop);
    layoutResp->addWidget(body, 0,Qt::AlignTop);
    layoutResp->addWidget(bottom, 0, Qt::AlignTop);
    this->setLayout(layoutResp);
}

void CO2Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
