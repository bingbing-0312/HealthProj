#include "stwidget.h"

STWidget::STWidget(QWidget *parent) : QWidget(parent)
{

}

void STWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
