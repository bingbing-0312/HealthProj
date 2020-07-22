#ifndef DEVICESETTINGSWIDGET_H
#define DEVICESETTINGSWIDGET_H

#include <QWidget>
#include "TCPSocket.h"

class DeviceSettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DeviceSettingsWidget(QWidget *parent = nullptr);
    TCPSocket *socket;

signals:

};

#endif // DEVICESETTINGSWIDGET_H
