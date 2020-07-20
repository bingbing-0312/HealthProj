#ifndef HRWIDGET_H
#define HRWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include<QLabel>
class HRWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HRWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
private:
    QLabel *hrl1;
    QLabel *hrl2;
signals:

};

#endif // HRWIDGET_H
