#include "titlebar.h"

TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{

}

void TitleBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
