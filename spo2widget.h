#ifndef SPO2WIDGET_H
#define SPO2WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

class SPO2Widget : public QWidget
{
    Q_OBJECT
public:
    explicit SPO2Widget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // SPO2WIDGET_H
