#ifndef HRWIDGET_H
#define HRWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

class HRWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HRWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // HRWIDGET_H
