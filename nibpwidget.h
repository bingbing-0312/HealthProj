#ifndef NIBPWIDGET_H
#define NIBPWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

class NIBPWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NIBPWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // NIBPWIDGET_H
