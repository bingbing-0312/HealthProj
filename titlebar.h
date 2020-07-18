#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

private:
    QLabel *ptitleLabel1;
    QLabel *ptitleLabel2;
    QLabel *ptitleLabel3;
    QLabel *ptitleLabel4;
    QLabel *ptitleLabel5;
    QLabel *ptitleLabel6;
signals:

};

#endif // TITLEBAR_H
