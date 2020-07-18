#ifndef RESPWIDGET_H
#define RESPWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

class RESPWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RESPWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // RESPWIDGET_H
