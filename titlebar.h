#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // TITLEBAR_H
