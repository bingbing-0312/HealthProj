#ifndef GETSERIAL_H
#define GETSERIAL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include "PlotWidget.h"

class GetSerial : public QObject
{
    Q_OBJECT
public:
    explicit GetSerial(QObject *parent = nullptr);
    QSerialPort *comPort = new QSerialPort(this);
    QSerialPortInfo comsInfo;



public slots:
    //bool sendString();
    void readMessage();
signals:
    void receivedData(QString nowdata);
};

#endif // GETSERIAL_H
