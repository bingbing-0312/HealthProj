#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    //this->setWindowFlag(Qt::FramelessWindowHint);
    this->resize(800, 600);

    title->setFixedHeight(50);
    title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    splitTitle->addWidget(title);
    splitTitle->addWidget(mainW);
    splitTitle->setMargin(0);
    splitTitle->setSpacing(0);

    title->setStyleSheet("background-color: rgb(50,50,50)");
    mainW->setStyleSheet("background-color: rgb(0,0,0)");
    ecgiiPlot.setStyleSheet("background-color: rgb(50,50,50)");
    spo2Plot.setStyleSheet("background-color: rgb(50,50,50)");
    respPlot.setStyleSheet("background-color: rgb(50,50,50)");
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
    leftPlotsLayout->addWidget(&respPlot);
    leftPlotsLayout->setMargin(0);

    rightGrids->addWidget(&hr,0, 0, 1, 1);
    rightGrids->addWidget(&st,0, 1, 1, 1);
    rightGrids->addWidget(&nibp,1, 0, 1, 2);
    rightGrids->addWidget(&spo2,2, 0, 1, 1);
    rightGrids->addWidget(&temp,2, 1, 1, 1);
    rightGrids->addWidget(&resp,3, 0, 1, 1);
    rightGrids->addWidget(&co2,3, 1, 1, 1);
    rightGrids->setMargin(0);

    left->setLayout(leftPlotsLayout);
    right->setLayout(rightGrids);
    mainW->setLayout(leftrightLayout);

    this->setLayout(splitTitle);

    //测试区
    qsrand(time(0));
    tm = new QTimer;
    connect(tm, &QTimer::timeout, this, &MainWidget::testPlot);
    tm->start(2);

    //button1->setParent(this);
    //button1->setGeometry(0,0,100,100);
    //button1->setText("发送至串口");
    //label1->setParent(this);
    //label1->setGeometry(100,0,100,100);
    //label1->setStyleSheet("background-color: rgb(255,255,255); color: rgb(0,0,0);");
    //connect(button1, &QPushButton::clicked, getserial, &GetSerial::sendString);
    //connect(getserial, &GetSerial::receivedData, this, &MainWidget::setLabelText);

    iData = testData.begin();
    //testWidget.setParent(this);
    //testWidget.setGeometry(0,0,800,600);
    ecgiiPlot.y0 = 1500;
    ecgiiPlot.yScale = 3000;
    ecgiiPlot.xScale = 4000;
    ecgiiPlot.updateInterval = 1;
}

MainWidget::~MainWidget()
{

}

void MainWidget::testPlot()
{
    ecgiiPlot.sendData(*iData);
    if(iData == testData.end()-5)
        iData = testData.begin();
    iData++;
}


