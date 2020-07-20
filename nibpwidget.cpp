#include "nibpwidget.h"

NIBPWidget::NIBPWidget(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background:rgb(0,0,0)");

    playoutHead->addWidget(title,0,Qt::AlignLeft);
    playoutHead->addWidget(setting,0,Qt::AlignRight);
    wholehead->setFixedHeight(30);
    wholehead->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    wholehead->setLayout(playoutHead);
    playoutBody->addWidget(bodyleft,0,Qt::AlignCenter);
    playoutBody->addWidget(bodymiddle,0,Qt::AlignCenter);
    playoutBody->addWidget(bodyright,0,Qt::AlignCenter);
    playoutmiddle->addWidget(pCurrentTimeLabel,0,Qt::AlignCenter|Qt::AlignTop);
    playoutmiddle->addWidget(middlemiddle,1,Qt::AlignCenter|Qt::AlignCenter);
    bodymiddle->setLayout(playoutmiddle);
    playoutRight->addWidget(righttop,0,Qt::AlignRight|Qt::AlignTop);
    playoutRight->addWidget(rightmiddle);
    bodyright->setLayout(playoutRight);
    wholebody->setLayout(playoutBody);
    playoutWhole->addWidget(wholehead,0,Qt::AlignTop);
    playoutWhole->addWidget(wholebody,0,Qt::AlignTop);
    playoutWhole->setMargin(0);
    playoutRight->setMargin(0);
    playoutmiddle->setMargin(0);
    playoutBody->setMargin(0);
    this->setLayout(playoutWhole);

    title->setStyleSheet("color:rgb(255, 255, 255); font: 11pt , Adobe 黑体 Std R;");
    pCurrentTimeLabel->setStyleSheet("color: rgb(255, 255, 255);font: 10pt Adobe 黑体 Std R;");
    wholehead->setStyleSheet("background-color:rgb(75, 75, 75)");
    bodyleft->setStyleSheet("color: rgb(7, 135, 255); font: 14pt , Adobe 黑体 Std R");
    middlemiddle->setStyleSheet("color: rgb(7, 135, 255); font: 30pt , Adobe 黑体 Std R");
    righttop->setStyleSheet("color: rgb(7, 135, 255); font: 11pt , Adobe 黑体 Std R");
    rightmiddle->setStyleSheet("color: rgb(7, 135, 255); font: 30pt , Adobe 黑体 Std R");

    time = QTime::currentTime();
    timer.start(50);
    pCurrentTimeLabel->setText(time.toString("hh:mm:ss"));
    setting->setPixmap(*pix);
    title->setText("NIBP");
    bodyleft->setText("-?-");
    middlemiddle->setText("/ -?-");
    righttop->setText("mmHg");
    rightmiddle->setText("-?-");
    connect(&timer, &QTimer::timeout, this, &NIBPWidget::setLCDTime);
}


void NIBPWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    *pix = pix->scaledToHeight(wholehead->height() - 18, Qt::SmoothTransformation);
    setting->setPixmap(*pix);
}

void NIBPWidget::setLCDTime()
{
    time = QTime::currentTime();
    timeStr = time.toString("hh:mm:ss");
    pCurrentTimeLabel->setText(timeStr);
}

void NIBPWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

