#ifndef PATIENTINFOWIDGET_H
#define PATIENTINFOWIDGET_H

#include <QWidget>
#include "TCPSocket.h"

class PatientInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PatientInfoWidget(QWidget *parent = nullptr);

    TCPSocket *socket;
signals:

};

#endif // PATIENTINFOWIDGET_H
