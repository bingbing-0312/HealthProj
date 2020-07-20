#include "titlebar.h"

TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    layout->addWidget(peopleIcon);
    layout->addWidget(deviceAndNote);

    layout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

    layout->addWidget(cloudIcon);
    layout->addSpacing(6);
    layout->addWidget(exclamationIcon);
    layout->addSpacing(10);
    layout->addWidget(peopleInfoIcon);
    layout->addSpacing(10);
    layout->addWidget(scaleIcon);
    layout->addSpacing(6);
    layout->setSpacing(8);
    layout->setMargin(6);

    deviceAndNote->setText("设备: xd001 备注: 001");
    deviceAndNote->setStyleSheet("color: white;font: 11pt \"Microsoft Yahei UI Bold\";");

    this->setLayout(layout);
}

void TitleBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void TitleBar::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    *peoplePNG = peoplePNG->scaledToHeight(this->height() - 20, Qt::SmoothTransformation);
    *exclamationPNG = exclamationPNG->scaledToHeight(this->height() - 24, Qt::SmoothTransformation);
    *scalePNG = scalePNG->scaledToHeight(this->height() - 24, Qt::SmoothTransformation);
    *cloudPNG = cloudPNG->scaledToHeight(this->height() - 12, Qt::SmoothTransformation);
    *infoPNG = infoPNG->scaledToHeight(this->height() - 24, Qt::SmoothTransformation);
    peopleIcon->setPixmap(*peoplePNG);
    cloudIcon->setPixmap(*cloudPNG);
    peopleInfoIcon->setPixmap(*infoPNG);
    scaleIcon->setPixmap(*scalePNG);
    exclamationIcon->setPixmap(*exclamationPNG);
}
