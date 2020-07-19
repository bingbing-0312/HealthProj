#include "co2widget.h"

CO2Widget::CO2Widget(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background:rgb(0,0,0)");
    head->setFixedHeight(30);
    head->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    title->setStyleSheet("color:rgb(255, 255, 255);font: 11pt , SimHei;");

    //中部标签
    data->setStyleSheet("color:yellow;font: 30pt , SimHei;");
    bpm->setStyleSheet("color:yellow;font: 11pt , SimHei;");
    //尾部标签
    //QLabel *nothing2 = new QLabel;
    ins->setStyleSheet("color:yellow;font: 11pt , SimHei;");
    awrr->setStyleSheet("color:yellow;font: 11pt , SimHei;");

    //头部标签数据写入
    title->setText("CO2");
    setting->setPixmap(*pix);

    //中部标签数据写入
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
    layoutBody->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding));
    layoutBody->addWidget(data, 0, Qt::AlignCenter|Qt::AlignBottom);
    layoutBody->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding));
    layoutBody->addWidget(bpm ,0 ,Qt::AlignRight | Qt::AlignTop);
    body->setLayout(layoutBody);
    //尾部布局
    layoutBottom->addWidget(ins, 0, Qt::AlignCenter|Qt::AlignTop);
    layoutBottom->addWidget(awrr, 0, Qt::AlignCenter|Qt::AlignTop);
    bottom->setLayout(layoutBottom);

    //整体布局
    layoutResp->addWidget(head,0, Qt::AlignTop);
    layoutResp->addWidget(body, 0,Qt::AlignTop);
    layoutResp->addWidget(bottom, 0, Qt::AlignTop);
    layoutResp->setMargin(0);
    layoutResp->setSpacing(0);
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

void CO2Widget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    *pix = pix->scaledToHeight(head->height()-18, Qt::SmoothTransformation);
    setting->setPixmap(*pix);
}
