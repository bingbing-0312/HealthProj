#ifndef RESPWIDGET_H
#define RESPWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>
#include <QLayout>

class RESPWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RESPWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    QVBoxLayout *layoutResp = new QVBoxLayout;
    QHBoxLayout *layoutHead = new QHBoxLayout;
    QVBoxLayout *layoutBody = new QVBoxLayout;
    QHBoxLayout *layoutBody1 = new QHBoxLayout;
    QHBoxLayout *layoutBody2 = new QHBoxLayout;
    QWidget *head = new QWidget;
    QWidget *body = new QWidget;

    //头部标签
    QLabel *title = new QLabel;
    QLabel *setting = new QLabel;

    //中部标签
    QLabel *nothing1 = new QLabel;
    QLabel *data = new QLabel;
    QLabel *bpm = new QLabel;

    //头部标签图
    QPixmap *pix = new QPixmap(":/icons/settings.png");

signals:

};

#endif // RESPWIDGET_H
