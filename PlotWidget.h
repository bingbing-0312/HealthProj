#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QPixmap>

class PlotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlotWidget(QWidget *parent = nullptr, QColor color_ = Qt::white, int xScale_ = 500, double y0_ = -20, double yScale_ = 20, int updateInterval_ = 5);
    ~PlotWidget();
    QColor color = Qt::white; //笔刷颜色
    int xScale = 500; //x范围
    double y0 = -20; //y起始值
    double yScale = 20; //y最大值
    int updateInterval = 10; //采样间隔ms数，需符合奈奎斯特准则

    void sendData(double d); //外部获取数据函数
    void paintEvent(QPaintEvent *event); //重绘重写函数

private:
    QList<int> data; //数据
    QList<int> time; //数据对应时间
    QPainter *painter; //主painter
    QTimer timer; //重绘定时器
    QPixmap *pix;

    int t = 0; //当前时间
    double xInterval; //时间轴坐标转换乘数
    double yInterval; //y轴坐标转换乘数
    void paintData(); //绘制数据

public slots:
    void paintSlot(); //定时绘制

};

#endif
