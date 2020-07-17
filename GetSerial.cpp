#include "GetSerial.h"

GetSerial::GetSerial(QObject *parent) : QObject(parent)
{
    comPort->setPortName("COM31");
    if(!comPort->open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(NULL, "串口错误", "串口连接失败，错误代码"+QString::number(comPort->error()));
        return;
    }
    comPort->setBaudRate(QSerialPort::Baud115200);
    comPort->setDataBits(QSerialPort::Data8);
    comPort->setFlowControl(QSerialPort::NoFlowControl);
    comPort->setParity(QSerialPort::NoParity);
    comPort->setStopBits(QSerialPort::OneStop);
    connect(comPort, &QSerialPort::readyRead, this, &GetSerial::readMessage);
}

//bool GetSerial::sendString()
//{
//    const char* str = "A Qt Program sent this message to You ! \r\n";
//    if(comPort->write(str))
//        return true;
//    else
//        return false;
//}

void GetSerial::readMessage()
{
    emit receivedData(comPort->readAll());
}
