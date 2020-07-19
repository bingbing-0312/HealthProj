#ifndef NIBPWIDGET_H
#define NIBPWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QTimer>
#include <QTime>
#include <QLabel>

class NIBPWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NIBPWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
//    void resizeEvent(QResizeEvent *event) override;
//    QLabel *LCDClock = new QLabel;
    QTimer timer;
    QString timeStr;


public slots:
//    void setLCDTime();

private:
    QLabel *pCurrentTimeLabel;
    QTime time;

signals:

};

#endif // NIBPWIDGET_H
