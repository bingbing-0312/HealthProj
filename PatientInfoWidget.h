#ifndef PATIENTINFOWIDGET_H
#define PATIENTINFOWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class PatientInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PatientInfoWidget(QWidget *parent = nullptr);

private:
    QWidget *ptopWidget = new QWidget;
    QWidget *pmiddle1Widget = new QWidget;
    QWidget *pmiddle2Widget = new QWidget;
    QWidget *pbottomWidget = new QWidget;
    QWidget *pIDnumberWidget = new QWidget;
    QLabel *name = new QLabel;
    QLabel *sex = new QLabel;
    QLabel *age = new QLabel;
    QLabel *IDnumber = new QLabel;
    QLineEdit *nameLineEdit = new QLineEdit;
    QLineEdit *sexLineEdit = new QLineEdit;
    QLineEdit *ageLineEdit = new QLineEdit;
    QLineEdit *IDnumberLineEdit = new QLineEdit;
    QPushButton *update = new QPushButton;
    QPushButton *alter = new QPushButton;
    QPushButton *save = new QPushButton;

    QVBoxLayout *pwholeLayout = new QVBoxLayout;
    QHBoxLayout *ptopLayout = new QHBoxLayout;
    QHBoxLayout *pmiddle1Layout = new QHBoxLayout;
    QHBoxLayout *pmiddle2Layout = new QHBoxLayout;
    QHBoxLayout *pbottomLayout = new QHBoxLayout;
    QHBoxLayout *pIDnumberLayout = new QHBoxLayout;

private slots:
    void savetButton_clicked();
    void alterButton_clicked();


};

#endif // PATIENTINFOWIDGET_H
