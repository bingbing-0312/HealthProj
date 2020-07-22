#ifndef DEVICESETTINGSWIDGET_H
#define DEVICESETTINGSWIDGET_H

#include <QWidget>
#include "TCPSocket.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>

class DeviceSettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DeviceSettingsWidget(QWidget *parent = nullptr);
    TCPSocket *socket;

signals:

private:
    void setWindowSize(int w, int h);

    QLabel *deviceID = new QLabel;
    QLabel *badID = new QLabel;
    QLabel *serialPortLable = new QLabel;
    QLabel *netConnectLable = new QLabel;
    QLabel *serialPortState = new QLabel;
    QLabel *netConnectState = new QLabel;

    QLineEdit *deviceIDEdit = new QLineEdit;
    QLineEdit *badIDEdit = new QLineEdit;

    QPushButton *deviceIDSet = new QPushButton;
    QPushButton *badIDSet = new QPushButton;

    QVBoxLayout *allLayout = new QVBoxLayout;
    QHBoxLayout *deviceLayout = new QHBoxLayout;
    QHBoxLayout *badLayout = new QHBoxLayout;
    QHBoxLayout *serialPortLayout = new QHBoxLayout;
    QHBoxLayout *netConnectLayout = new QHBoxLayout;
    
public slots:
    void setDeviceID();
    void setBadID();
};

#endif // DEVICESETTINGSWIDGET_H
