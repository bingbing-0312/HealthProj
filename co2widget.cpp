#include "co2widget.h"

CO2Widget::CO2Widget(QWidget *parent) : QWidget(parent)
{

}

void CO2Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
