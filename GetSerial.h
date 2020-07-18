#ifndef GETSERIAL_H
#define GETSERIAL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include "PlotWidget.h"

class GetSerial : public QSerialPort
{
    Q_OBJECT
public:
    explicit GetSerial(QString portName_ = "COM31", QObject *parent = nullptr);
    QString portName;
    QList<QString> getPortsName();
    void connectPort();

private:
    void statusMachine(char data);
    int status;
    char pkgType;
    char pkgDataHead;
    int dataLength;
    int pkgDataCnt;
    char pkgData[7];
    int pkgDataInt[3];
    unsigned int dataForSending;

    bool flagCount = true;

public slots:
    //bool sendString(QString str);
    void readMessage();
signals:
    //void receivedData(QString nowdata);
    void receivedECGdata(int data);
    void receivedBPdata(int data);
    void receivedSPO2data(int data);

};

#endif // GETSERIAL_H
