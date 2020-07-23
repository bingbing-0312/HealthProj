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
    QLabel *serialPortLable = new QLabel;
    QLabel *serialPortState = new QLabel;

    QLineEdit *deviceIDEdit = new QLineEdit;
    QPushButton *deviceIDSet = new QPushButton;

    QVBoxLayout *allLayout = new QVBoxLayout;
    QHBoxLayout *deviceLayout = new QHBoxLayout;
    QHBoxLayout *badLayout = new QHBoxLayout;
    QHBoxLayout *serialPortLayout = new QHBoxLayout;
    
public slots:
    void setDeviceID();
};

#endif // DEVICESETTINGSWIDGET_H
