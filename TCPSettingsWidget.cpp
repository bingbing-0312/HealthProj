#include "TCPSettingsWidget.h"

TCPSettingsWidget::TCPSettingsWidget(QWidget *parent) : QWidget(parent)
{
    ipLayout->addWidget(ipLabel);
    ipLayout->addWidget(ipEdit);
    portLayout->addWidget(portLabel);
    portLayout->addWidget(portEdit);
    buttonLayout->addWidget(testBtn);
    buttonLayout->addWidget(applyBtn);
    all->addLayout(ipLayout);
    all->addLayout(portLayout);
    all->addLayout(buttonLayout);
    this->setLayout(all);

    ipLabel->setText("IP:");
    portLabel->setText("PORT:");
    testBtn->setText("测试");
    applyBtn->setText("应用");

    connect(applyBtn, &QPushButton::clicked, this, &TCPSettingsWidget::setTCPIP);
    connect(testBtn, &QPushButton::clicked, this, &TCPSettingsWidget::testTCPIP);
}

void TCPSettingsWidget::setTCPIP()
{
    emit tcpipChanged(ipEdit->text(), portEdit->text().toUInt());
}

void TCPSettingsWidget::testTCPIP()
{
    socketForTest->abort();
    if(socketForTest->connectToServer(ipEdit->text(), portEdit->text().toUInt()))
        QMessageBox::information(NULL, "Succes", "成功！");
    else
        QMessageBox::information(NULL, "Failed", "失败！");
    socketForTest->close();
}

void TCPSettingsWidget::setWindowSize(int w, int h)
{
    this->resize(w, h);
}
