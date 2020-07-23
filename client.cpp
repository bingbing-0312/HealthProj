#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
}

void Client::initALL()
{
    socket =  new TCPSocket;
    tcpSendTimer = new QTimer;
    connect(titlebar, &TitleBar::middleTCP, this, &Client::setTCPIP);
    connect(tcpSendTimer, &QTimer::timeout, this, &Client::sendTCPOthers);
    connect(socket, &TCPSocket::dealMessage, this, &Client::TCPGetMessage);
    connect(ecgiiPlot, &PlotWidget::dataFulledForTCP, this, &Client::sendTCPWaves);
    connect(spo2Plot, &PlotWidget::dataFulledForTCP, this, &Client::sendTCPWaves);
    connect(bpPlot, &PlotWidget::dataFulledForTCP, this, &Client::sendTCPWaves);
}

void Client::setTCPIP(QString ip, quint16 mport)
{
    ipAddr = ip;
    port = mport;
    socket->abort();
    if(socket->connectToServer(ipAddr, port))
    {
        socket->SendMessage(QString("facility,%1;").arg(facilitySerialNum).toUtf8());
        //socket->SendMessage(QString("facility,%1;").arg(facilitySerialNum).toUtf8());
        tcpSendTimer->start(142);
        connected = true;
    }
    //tcpWaveSendTimer->start(10000);
}

void Client::TCPGetMessage(QByteArray ba)
{
    QString msg = QString(ba).split(";")[1];
    QStringList msgList = msg.split(",");
    if(msgList[0] == "faciID")
    {
        facilityName = msgList[1];
    }
}

void Client::sendTCPOthers()
{
    if(counterX == 1)
    {
        counterX++;
        socket->SendMessage(QString("hr,%1,%2;").arg(facilityName).arg(hr->dataForTCPSend).toUtf8());
    }
    else if(counterX == 2)
    {
        counterX++;
        socket->SendMessage(QString("st,%1,%2,%3,%4;").arg(facilityName)
                        .arg(st->dataForTCPSend1)
                        .arg(st->dataForTCPSend2)
                        .arg(st->dataForTCPSend3).toUtf8());
    }
    else if(counterX == 3)
    {
        counterX++;
    socket->SendMessage(QString("nibp,%1,%2,%3,%4;").arg(facilityName)
                        .arg(nibp->dataForTCPSend1)
                        .arg(nibp->dataForTCPSend2)
                        .arg(nibp->dataForTCPSend3).toUtf8());
    }

    else if(counterX == 4)
    {
        counterX++;
    socket->SendMessage(QString("spo2,%1,%2,%3;").arg(facilityName)
                        .arg(spo2->dataForTCPSend1)
                        .arg(spo2->dataForTCPSend2).toUtf8());
    }
    else if(counterX == 5)
    {
        counterX++;
    socket->SendMessage(QString("temp,%1,%2,%3,%4;").arg(facilityName)
                        .arg(temp->dataForTCPSend1)
                        .arg(temp->dataForTCPSend2)
                        .arg(temp->dataForTCPSend3).toUtf8());
    }
    else if(counterX == 6)
    {
        counterX++;
    socket->SendMessage(QString("resp,%1,%2;").arg(facilityName)
                        .arg(resp->dataForTCPSend).toUtf8());
    }
    else if(counterX == 7)
    {
        counterX = 1;
    socket->SendMessage(QString("co2,%1,%2,%3,%4;").arg(facilityName)
                        .arg(co2->dataForTCPSend1)
                        .arg(co2->dataForTCPSend2)
                        .arg(co2->dataForTCPSend3).toUtf8());
    }
}

void Client::sendTCPWaves(int flag)
{
    if(connected)
    {
        QString strForTCP = "";
        if(flag == 1)
        {
            TCPSocket *socket2 = new TCPSocket;
            socket2->connectToServer(ipAddr, port);
            strForTCP= QString("ecgplot,%1,").arg(facilityName);
            for(int i=0;i<ecgiiPlot->dataForTCP.size();i++)
            {
                strForTCP.append(QString("%1").arg(ecgiiPlot->dataForTCP.at(i)));
                if(i < ecgiiPlot->dataForTCP.size() - 1)
                {
                    strForTCP.append(".");
                }
            }
            strForTCP.append(";");
            socket2->SendMessage(strForTCP.toUtf8());
            socket2->close();
            ecgiiPlot->dataForTCP.clear();
        }
        else if(flag == 2)
        {
            TCPSocket *socket3 = new TCPSocket;
            socket3->connectToServer(ipAddr, port);
            strForTCP= QString("spo2plot,%1,").arg(facilityName);
            for(int i=0;i<spo2Plot->dataForTCP.size();i++)
            {
                strForTCP.append(QString("%1").arg(spo2Plot->dataForTCP.at(i)));
                if(i < spo2Plot->dataForTCP.size() - 1)
                {
                    strForTCP.append(".");
                }
            }
            strForTCP.append(";");
            socket3->SendMessage(strForTCP.toUtf8());
            socket3->close();
            spo2Plot->dataForTCP.clear();
        }
        else if(flag == 3)
        {
            TCPSocket *socket4 = new TCPSocket;
            socket4->connectToServer(ipAddr, port);
            strForTCP= QString("bpplot,%1,").arg(facilityName);
            for(int i=0;i<bpPlot->dataForTCP.size();i++)
            {
                strForTCP.append(QString("%1").arg(bpPlot->dataForTCP.at(i)));
                if(i < bpPlot->dataForTCP.size() - 1)
                {
                    strForTCP.append(".");
                }
            }
            strForTCP.append(";");
            socket4->SendMessage(strForTCP.toUtf8());
            socket4->close();
            bpPlot->dataForTCP.clear();
        }
    }
}
