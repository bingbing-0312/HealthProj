#include "tempwidget.h"

TEMPWidget::TEMPWidget(QWidget *parent) : QWidget(parent)
{

}

void TEMPWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
