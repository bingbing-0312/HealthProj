#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QThread>
#include "PlotWidget.h"
#include "GetSerial.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    //注意：由于Qt对象树在销毁时，含有子对象且在栈区的对象，销毁时会把子对象也销毁
    //     而子对象还会销毁一遍，这样就出错了，会无法退出，因此这里用指针将其放在堆区
    //布局Layout
    QVBoxLayout *splitTitle = new QVBoxLayout;
    QVBoxLayout *leftPlotsLayout = new QVBoxLayout;
    QHBoxLayout *leftrightLayout = new QHBoxLayout;
    QGridLayout *rightGrids = new QGridLayout;

    //布局Widget
    QWidget *left = new QWidget(this);
    QWidget *right = new QWidget(this);
    QWidget *title = new QWidget(this);
    QWidget *mainW = new QWidget(this);

    //待提升的Widget
    PlotWidget ecgiiPlot;
    QWidget spo2Plot;
    QWidget respPlot;

    QWidget hr;
    QWidget st;
    QWidget nibp;
    QWidget spo2;
    QWidget temp;
    QWidget resp;
    QWidget co2;

    QTimer *tm;
    int i = 10;
    int flag = 0;
public slots:
    void testPlot();
};
#endif // MAINWIDGET_H
