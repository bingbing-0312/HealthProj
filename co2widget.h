#ifndef CO2WIDGET_H
#define CO2WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QLayout>
#include <QLabel>



class CO2Widget : public QWidget
{
    Q_OBJECT
public:
    explicit CO2Widget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // CO2WIDGET_H
