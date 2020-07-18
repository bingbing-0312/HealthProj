#include "respwidget.h"

RESPWidget::RESPWidget(QWidget *parent) : QWidget(parent)
{

}

void RESPWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
