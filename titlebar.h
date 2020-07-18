#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>
#include <QLayout>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QHBoxLayout *layout = new QHBoxLayout(this);

    QLabel *deviceAndNote = new QLabel(this);
    QLabel *peopleIcon = new QLabel(this);
    QLabel *cloudIcon = new QLabel(this);
    QLabel *exclamationIcon = new QLabel(this);
    QLabel *peopleInfoIcon = new QLabel(this);
    QLabel *scaleIcon = new QLabel(this);

    QPixmap *peoplePNG = new QPixmap(":/icons/people.png");
    QPixmap *exclamationPNG = new QPixmap(":/icons/exclamation.png");
    QPixmap *scalePNG = new QPixmap(":/icons/scale.png");
    QPixmap *cloudPNG = new QPixmap(":/icons/cloud.png");
    QPixmap *infoPNG = new QPixmap(":/icons/info.png");
signals:

};

#endif // TITLEBAR_H
