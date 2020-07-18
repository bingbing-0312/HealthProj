#ifndef TEMPWIDGET_H
#define TEMPWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

class TEMPWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TEMPWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // TEMPWIDGET_H
