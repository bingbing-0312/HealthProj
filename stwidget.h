#ifndef STWIDGET_H
#define STWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include<QLabel>

class STWidget : public QWidget
{
    Q_OBJECT
public:
    explicit STWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
private:
    QLabel *stl1;
    QLabel *stl2;
    QLabel *stl3;
private:
    QLabel *hrsttil1;
    QLabel *hrsttil2;
    QLabel *hrsttil3;


signals:

};

#endif // STWIDGET_H
