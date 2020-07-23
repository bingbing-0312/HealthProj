#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include "TCPSocket.h"
#include <QTimer>
#include "PlotWidget.h"
#include "hrwidget.h"
#include "stwidget.h"
#include "nibpwidget.h"
#include "respwidget.h"
#include "co2widget.h"
#include "spo2widget.h"
#include "tempwidget.h"
#include "tempwidget.h"
#include "titlebar.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    QTimer *tcpSendTimer;
    TCPSocket *socket;
    QString ipAddr;
    quint16 port;
    QString facilityName;
    QString facilitySerialNum;
    bool connected = false;
    int counterX = 1;
    PlotWidget *ecgiiPlot;
    PlotWidget *spo2Plot;
    PlotWidget *bpPlot;

    HRWidget *hr;
    STWidget *st;
    NIBPWidget *nibp;
    SPO2Widget *spo2;

    TEMPWidget *temp;
    RESPWidget *resp;
    CO2Widget *co2;

    TitleBar *titlebar;


public slots:
    void initALL();
    void setTCPIP(QString ip, quint16 mport);
    void TCPGetMessage(QByteArray ba);
    void sendTCPOthers();
    void sendTCPWaves(int flag);

signals:

};

#endif // CLIENT_H
