#include "nibpwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

NIBPWidget::NIBPWidget(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background:rgb(0,0,0)");

//    connect(&timer, &QTimer::timeout, this, &NIBPWidget::setLCDTime);
//    timer.start(50);
    //时间显示
    time = QTime::currentTime();
    pCurrentTimeLabel = new QLabel(this);
    pCurrentTimeLabel->setText(time.toString("hh:mm:ss"));
    pCurrentTimeLabel->setStyleSheet("color: rgb(255, 255, 255);font: 18pt \"Agency FB\";");
//整体（上一半）
    //创建窗口
    QWidget *wholehead = new QWidget;
    QWidget *wholebody = new QWidget;
    wholehead->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    wholehead->setStyleSheet("background-color:rgb(75, 75, 75)");
    //给定布局器
    QVBoxLayout *playoutWhole = new QVBoxLayout;
    //设置拉伸因子
    //playoutWhole->setStretchFactor(wholehead,1);
    //playoutWhole->setStretchFactor(wholebody,4);
    //将布局器在NibpWidget窗口显示

//上部
    //创建窗口
    QLabel *title = new QLabel;
    QLabel *setting = new QLabel;
    //样式设计+数据数入
    QPixmap *pix = new QPixmap;
    pix->load("setting.jpg");
    setting->setPixmap(*pix);
    title->setText("NIBP");
    title->setStyleSheet("color:rgb(255, 255, 255);"
                         "font: 11pt , Adobe 黑体 Std R;");
    //给定布局器
    QHBoxLayout *playoutHead = new QHBoxLayout;
    //将窗口放进布局器中
    playoutHead->addWidget(title,0,Qt::AlignLeft);
    playoutHead->addWidget(setting,0,Qt::AlignRight);
    //布局器在wholehead窗口上显示
    wholehead->setLayout(playoutHead);

//下部
    //给定窗口
    QLabel *bodyleft = new QLabel;
    QLabel *bodymiddle = new QLabel;
    QLabel *bodyright = new QLabel;
    //样式设计+数据输入
    bodyleft->setStyleSheet("color: rgb(7, 135, 255);"
                            "font: 14pt , Adobe 黑体 Std R");
    bodyleft->setText("-?-");
    //给定布局器
    QHBoxLayout *playoutBody = new QHBoxLayout;
    //将窗口放进布局器中
    playoutBody->addWidget(bodyleft,0,Qt::AlignCenter);
    playoutBody->addWidget(bodymiddle);
    playoutBody->addWidget(bodyright);
    //布局器在wholebody上显示
    wholebody->setLayout(playoutBody);

//下部中
    //给定窗口
    QLabel *middlemiddle = new QLabel;
    QLabel *middlebottom = new QLabel;
    //LCDClock->setStyleSheet("color: rgb(7, 135, 255);");
    middlemiddle->setStyleSheet("color: rgb(7, 135, 255);"
                                "font: 30pt , Adobe 黑体 Std R");
    middlemiddle->setText("/ -?-");
    //给定布局器
    QVBoxLayout *playoutmiddle =new QVBoxLayout;
    //将窗口放进布局器中
    playoutmiddle->addWidget(pCurrentTimeLabel);
    playoutmiddle->addWidget(middlemiddle,0,Qt::AlignLeft|Qt::AlignTop);
    playoutmiddle->addWidget(middlebottom);
    //将布局器放进bodymiddle窗口
    bodymiddle->setLayout(playoutmiddle);

//下部右
    //给定窗口
    QLabel *righttop = new QLabel;
    QLabel *rightmiddle = new QLabel;
    QLabel *rightbottom = new QLabel;
    //样式设计+数据输入
    righttop->setStyleSheet("color: rgb(7, 135, 255);"
                            "font: 11pt , Adobe 黑体 Std R");
    rightmiddle->setStyleSheet("color: rgb(7, 135, 255);"
                               "font: 30pt , Adobe 黑体 Std R");
    righttop->setText("mmHg");
    rightmiddle->setText("-?-");
    //给定布局器
    QVBoxLayout *playouRight = new QVBoxLayout;
    //将窗口放进布局器中
    playouRight->addWidget(righttop,0,Qt::AlignRight|Qt::AlignTop);
    playouRight->addWidget(rightmiddle);
    //将布局器放进窗口中
    bodyright->setLayout(playouRight);

//整体（下一半）
    //两窗口放进布局器中
    playoutWhole->addWidget(wholehead,0,Qt::AlignTop);
    playoutWhole->addWidget(wholebody,0,Qt::AlignTop);
    this->setLayout(playoutWhole);
}


//void NIBPWidget::resizeEvent(QResizeEvent *event)
//{
//}

//void NIBPWidget::setLCDTime()
//{
//    time = QTime::currentTime();
//    timeStr = time.toString("hh:mm:ss");
//    LCDClock->setText(timeStr);
//}

void NIBPWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

