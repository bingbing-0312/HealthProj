#include "DeviceSettingsWidget.h"

DeviceSettingsWidget::DeviceSettingsWidget(QWidget *parent) : QWidget(parent)
{
  this->setStyleSheet("background-color: black");
    //this->resize(500,200);

    deviceLayout->addWidget(deviceID);
    deviceLayout->addWidget(deviceIDEdit);
    deviceLayout->addWidget(deviceIDSet);
    badLayout->addWidget(badID);
    badLayout->addWidget(badIDEdit);
    badLayout->addWidget(badIDSet);
    serialPortLayout->addWidget(serialPortLable);
    serialPortLayout->addWidget(serialPortState);
    netConnectLayout->addWidget(netConnectLable);
    netConnectLayout->addWidget(netConnectState);
    allLayout->addStretch(2);
    allLayout->addLayout(deviceLayout);
    allLayout->addStretch(1);
    allLayout->addLayout(badLayout);
    allLayout->addStretch(1);
    allLayout->addLayout(serialPortLayout);
    allLayout->addStretch(1);
    allLayout->addLayout(netConnectLayout);
    allLayout->addStretch(2);

    this->setLayout(allLayout);

    //设置标签文本
    deviceID->setText("设备ID：");
    deviceID->setStyleSheet("color:white");
    badID->setText("床位ID：");
    badID->setStyleSheet("color:white");
    serialPortLable->setText("串口连接状态：");
    serialPortLable->setStyleSheet("color:white");
    netConnectLable->setText("网络连接状态：");
    netConnectLable->setStyleSheet("color:white");
        //获取连接状态（如何获取连接状态）然后设置两个状态标签(serialPortState netConnectState)的文本

    //设置文本框初始值
    deviceIDEdit->setText("1");
    deviceIDEdit->setStyleSheet("color:white");
    badIDEdit->setText("1");
    badIDEdit->setStyleSheet("color:white");

    deviceIDSet->setText("设置设备ID");
    deviceIDSet->setStyleSheet("color:white");
    badIDSet->setText("设置床位ID");
    badIDSet->setStyleSheet("color:white");

    serialPortState->setStyleSheet("color:white");
    netConnectState->setStyleSheet("color:white");


    connect(deviceIDSet, &QPushButton::clicked,
            this, &DeviceSettingsWidget::setDeviceID);

    connect(badIDSet, &QPushButton::clicked,
            this, &DeviceSettingsWidget::setBadID);


}

void DeviceSettingsWidget::setWindowSize(int w, int h)
{
    //虽然我不知道这么些的作用，我还是按照已有的TCPSettingsWidget写的
    this->resize(w, h);
}

void DeviceSettingsWidget::setDeviceID()
{
    QString deviceIDData = deviceIDEdit->text();
    qDebug() << "设置设备ID";
    //再跟数据库连接啥的我不会了（上课困死我了 我一直在睡觉我有错）
}

void DeviceSettingsWidget::setBadID()
{
    QString deviceIDData = badIDEdit->text();
    //同上一个槽函数
    qDebug() << "设置病床ID";
}

