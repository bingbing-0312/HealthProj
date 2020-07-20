#include "respwidget.h"

RESPWidget::RESPWidget(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background:rgb(0,0,0)");
    head->setStyleSheet("background-color:rgb(75, 75, 75)");
    head->setFixedHeight(30);
    head->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    title->setStyleSheet("color:rgb(255, 255, 255);font: 11pt , SimHei;");
    data->setStyleSheet("color:yellow;font: 36pt , SimHei;");
    bpm->setStyleSheet("color:yellow;font: 11pt , SimHei;");

    //头部标签数据写入
    title->setText("RESP");
    setting->setPixmap(*pix);

    //中部标签数据写入
    //nothing1->setText("    ");
    data->setText("-?-");
    bpm->setText("bpm");

    //尾部标签写入
    //ins->setText("ins -?-");
    //awrr->setText("awrr -?-");

    //头部布局
    layoutHead->addWidget(title,0,Qt::AlignLeft);
    layoutHead->addWidget(setting, 0 ,Qt::AlignRight );
    head->setLayout(layoutHead);
    //中部布局
    layoutBody1->addWidget(bpm ,0 ,Qt::AlignRight | Qt::AlignTop);
    layoutBody2->addWidget(data, 1, Qt::AlignCenter|Qt::AlignTop);
    layoutBody->addLayout(layoutBody1, 0);
    layoutBody->addLayout(layoutBody2, 1);
    body->setLayout(layoutBody);
    //尾部布局
    //layoutBottom->addWidget(nothing2);

    //整体布局
    layoutResp->addWidget(head, 0, Qt::AlignTop);
    layoutResp->addWidget(body, 1, Qt::AlignVCenter);
    layoutResp->setSpacing(0);
    layoutResp->setMargin(0);

    this->setLayout(layoutResp);
}

void RESPWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void RESPWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    *pix = pix->scaledToHeight(head->height() - 18, Qt::SmoothTransformation);
    setting->setPixmap(*pix);
}
