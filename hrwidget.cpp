#include "hrwidget.h"

HRWidget::HRWidget(QWidget *parent) : QWidget(parent)
{

}

void HRWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
