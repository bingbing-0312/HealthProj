#include "spo2widget.h"

SPO2Widget::SPO2Widget(QWidget *parent) : QWidget(parent)
{

}

void SPO2Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
