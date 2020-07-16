#include "GetSerial.h"

GetSerial::GetSerial(QObject *parent) : QObject(parent)
{
    comPort->setPortName("COM31");
    if(!comPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "错误代码" << comPort->error();
        return;
    }
    comPort->setBaudRate(QSerialPort::Baud115200);
    comPort->setDataBits(QSerialPort::Data8);
    comPort->setFlowControl(QSerialPort::NoFlowControl);
    comPort->setParity(QSerialPort::NoParity);
    comPort->setStopBits(QSerialPort::OneStop);
    connect(comPort, &QSerialPort::readyRead, this, &GetSerial::readMessage);
}

bool GetSerial::sendString()
{
    const char* str = "A Qt Program sent this message to You ! \r\n";
    if(comPort->write(str))
        return true;
    else
        return false;
}

void GetSerial::readMessage()
{
    QString nowdata = comPort->readAll();
    alldata += nowdata;
    emit receivedData(nowdata);
}
