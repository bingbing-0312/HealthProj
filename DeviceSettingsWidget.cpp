#include "DeviceSettingsWidget.h"

DeviceSettingsWidget::DeviceSettingsWidget(QWidget *parent) : QWidget(parent)
{
    //this->setStyleSheet("background-color: black");
    //this->resize(500,200);

    deviceLayout->addWidget(deviceID);
    deviceLayout->addWidget(deviceIDEdit);
    deviceLayout->addWidget(deviceIDSet);
    serialPortLayout->addWidget(serialPortLable);
    serialPortLayout->addWidget(serialPortState);
    allLayout->addStretch(2);
    allLayout->addLayout(deviceLayout);
    allLayout->addStretch(1);
    allLayout->addLayout(badLayout);
    allLayout->addStretch(1);
    allLayout->addLayout(serialPortLayout);
    allLayout->addStretch(1);
    allLayout->addStretch(2);

    this->setLayout(allLayout);

    //设置标签文本
    deviceID->setText("设备ID：");
    serialPortLable->setText("串口连接状态：");

    //设置文本框初始值
    deviceIDEdit->setText("1");

    deviceIDSet->setText("设置");


    connect(deviceIDSet, &QPushButton::clicked,
            this, &DeviceSettingsWidget::setDeviceID);
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


