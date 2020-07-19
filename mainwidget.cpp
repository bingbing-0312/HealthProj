#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    //this->setWindowFlag(Qt::FramelessWindowHint);
    this->resize(1000, 600);

    title.setFixedHeight(50);
    title.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    splitTitle->addWidget(&title);
    splitTitle->addWidget(mainW);
    splitTitle->setMargin(0);
    splitTitle->setSpacing(0);

    title.setStyleSheet("background-color: rgb(50,50,50)");
    mainW->setStyleSheet("background-color: rgb(0,0,0)");
    ecgiiPlot.setStyleSheet("background-color: rgb(50,50,50)");
    spo2Plot.setStyleSheet("background-color: rgb(50,50,50)");
    bpPlot.setStyleSheet("background-color: rgb(50,50,50)");
    hr.setStyleSheet("background-color: rgb(50,50,50)");
    st.setStyleSheet("background-color: rgb(50,50,50)");
    nibp.setStyleSheet("background-color: rgb(50,50,50)");
    spo2.setStyleSheet("background-color: rgb(50,50,50)");
    temp.setStyleSheet("background-color: rgb(50,50,50)");
    resp.setStyleSheet("background-color: rgb(50,50,50)");
    co2.setStyleSheet("background-color: rgb(50,50,50)");

    leftrightLayout->addWidget(left);
    leftrightLayout->addWidget(right);
    leftrightLayout->setStretch(0, 2);
    leftrightLayout->setStretch(1, 1);
    leftrightLayout->setMargin(0);

    leftPlotsLayout->addWidget(&ecgiiPlot);
    leftPlotsLayout->addWidget(&spo2Plot);
    leftPlotsLayout->addWidget(&bpPlot);
    leftPlotsLayout->setMargin(0);

    rightGrids->addWidget(&hr,0, 0, 1, 1);
    rightGrids->addWidget(&st,0, 1, 1, 1);
    rightGrids->addWidget(&nibp,1, 0, 1, 2);
    rightGrids->addWidget(&spo2,2, 0, 1, 1);
    rightGrids->addWidget(&temp,2, 1, 1, 1);
    rightGrids->addWidget(&resp,3, 0, 1, 1);
    rightGrids->addWidget(&co2,3, 1, 1, 1);
    rightGrids->setMargin(0);
    rightGrids->setRowStretch(0, 1);
    rightGrids->setRowStretch(1, 1);
    rightGrids->setRowStretch(2, 1);
    rightGrids->setRowStretch(3, 1);
    rightGrids->setColumnStretch(0, 1);
    rightGrids->setColumnStretch(1, 1);

    left->setLayout(leftPlotsLayout);
    right->setLayout(rightGrids);
    mainW->setLayout(leftrightLayout);

    this->setLayout(splitTitle);

    //测试区
    ecgiiPlot.y0 = 0;
    ecgiiPlot.yScale = 4096;
    ecgiiPlot.xScale = 2000;
    ecgiiPlot.updateInterval = 1;
    ecgiiPlot.color = Qt::green;
    ecgiiPlot.text = "ECG";

    spo2Plot.y0 = 0;
    spo2Plot.yScale = 300;
    spo2Plot.xScale = 2000;
    spo2Plot.updateInterval = 1;
    spo2Plot.color = Qt::red;
    spo2Plot.text = "SPO2";

    bpPlot.y0 = 0;
    bpPlot.yScale = 300;
    bpPlot.xScale = 2000;
    bpPlot.updateInterval = 1;
    bpPlot.color = Qt::yellow;
    bpPlot.text = "BP";
    connect(gs, &GetSerial::receivedECGdata, &ecgiiPlot, &PlotWidget::sendData);
    connect(gs, &GetSerial::receivedBPdata, &bpPlot, &PlotWidget::sendData);
    connect(gs, &GetSerial::receivedSPO2data, &spo2Plot, &PlotWidget::sendData);
    gs->connectPort();
    //qsrand(time(0));
    //tm = new QTimer;
    //connect(tm, &QTimer::timeout, this, &MainWidget::testPlot);
    //tm->start(10);
    //
    //iData = testData.begin();
    //
    //lineedit1->setParent(this);
    //button1->setParent(this);
    //label1->setParent(this);
    //
    //lineedit1->setGeometry(0, 100, 100, 20);
    //button1->setGeometry(0, 120, 100, 30);
    //button1->setText("发送");
    //label1->setGeometry(100, 100, 100, 100);
    //label1->setStyleSheet("background-color: white");
    //connect(button1, &QPushButton::clicked, this, &MainWidget::sendString2Port);
    //connect(getserial, &GetSerial::receivedData, this, &MainWidget::testRead);
    //getserial->connectPort();



}

MainWidget::~MainWidget()
{

}

//void MainWidget::testPlot()
//{
//    ecgiiPlot.sendData(*iData);
//    iData+=10; //压缩，10点采样1次
//    if(iData >= testData.end())
//        iData = testData.begin();
//}
//
//void MainWidget::sendString2Port()
//{
//    QString txt4send = this->lineedit1->text()+"\r\n";
//    if(!getserial->sendString(txt4send))
//        QMessageBox::critical(NULL, "错误", "发送失败");
//}
//
//void MainWidget::testRead(QString str)
//{
//    label1->setText(str);
//}


