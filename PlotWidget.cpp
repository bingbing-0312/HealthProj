#include "PlotWidget.h"

PlotWidget::PlotWidget(QWidget *parent,
                       QColor color_, int xScale_, double y0_, double yScale_, int updateInterval_) : QWidget(parent),
                        color(color_), xScale(xScale_), y0(y0_), yScale(yScale_), updateInterval(updateInterval_)
{
    connect(&timer, &QTimer::timeout, this, &PlotWidget::paintSlot);
    timer.setInterval(updateInterval);
    painter = new QPainter;
    pix = new QPixmap(this->width(), this->height());
    pix->fill(Qt::black);
}

PlotWidget::~PlotWidget()
{
    timer.stop();
    delete painter;
}

void PlotWidget::sendData(double d)
{
    data.append(d);
    time.append(t);
    timer.start(updateInterval);
}

void PlotWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    paintData();
    painter->begin(this);
    painter->drawPixmap(0, 0, pix->width(), pix->height(),*pix);
    painter->end();
}

void PlotWidget::paintData()
{
    int i;
    xInterval = this->width()/xScale;
    yInterval = this->height()/(yScale-y0);
    painter->begin(pix);
    for(i=1;i<data.size();i++)
    {
        if(i==1){
            painter->setPen(QPen(Qt::black, 10));
            painter->drawLine(0, 0,
                              0, this->height());
        }
        painter->setPen(QPen(Qt::black, 10));
        painter->drawLine((time.at(i))*xInterval, 0,
                          (time.at(i))*xInterval, this->height());
        painter->setPen(QPen(color, 2));
        painter->drawLine(time.at(i-1)*xInterval, this->height()-(data.at(i-1)-y0)*yInterval,
                          time.at(i)*xInterval, this->height()-(data.at(i)-y0)*yInterval);
    }
    painter->end();
}

void PlotWidget::paintSlot()
{
    t += 1;
    if(t==xScale)
    {
        t = 0;
        data.clear();
        time.clear();
    }
    this->update();
}

