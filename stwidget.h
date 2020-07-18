#ifndef STWIDGET_H
#define STWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

class STWidget : public QWidget
{
    Q_OBJECT
public:
    explicit STWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // STWIDGET_H
