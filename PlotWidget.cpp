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
    label.setParent(this);
    label.move(0,0);
    label.setStyleSheet("font: 10pt \"黑体\"; background-color: black; color: white");
}

PlotWidget::~PlotWidget()
{
    timer.stop();
    delete painter;
}

void PlotWidget::sendData(double d)
{
    data.append(pix->height() - (d-y0)*pix->height()/(yScale-y0));
    time.append(t*pix->width()/xScale);
    if(!timer.isActive())
        timer.start(updateInterval);
}

void PlotWidget::paintEvent(QPaintEvent *event)
{
    label.setText(text);
    label.adjustSize();
    Q_UNUSED(event);
    paintData();
    painter->begin(this);
    painter->drawPixmap(0, 0, this->width(), this->height(),*pix);
    painter->end();
}

void PlotWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    *pix = pix->scaled(this->width(), this->height());
}

void PlotWidget::paintData()
{
    int s = data.size()-1;
    painter->begin(pix);
    painter->setRenderHint(QPainter::Antialiasing,true);
    if(s>-1)
    {
        painter->setPen(QPen(Qt::black, 1));
        painter->setBrush(Qt::black);
        if(s<10)
            painter->drawRect(time.at(s), 0, 10, this->height());
        painter->drawRect(time.at(s)+10, 0, 10, this->height());
    }

    if(s>1)
    {
        painter->setPen(QPen(color, 2));
        painter->drawLine(time.at(s-1), data.at(s-1),
                          time.at(s), data.at(s));
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

