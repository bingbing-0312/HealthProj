#ifndef GETSERIAL_H
#define GETSERIAL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include "PlotWidget.h"

class GetSerial : public QObject
{
    Q_OBJECT
public:
    explicit GetSerial(QObject *parent = nullptr);
    PlotWidget *pw;

signals:

};

#endif // GETSERIAL_H
