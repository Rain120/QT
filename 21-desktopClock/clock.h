#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

static QPoint sed[4] = {QPoint(0,-70),QPoint(2,0),QPoint(0,10),QPoint(-2,0)};
static QPoint min[4] = {QPoint(0,-60),QPoint(4,0),QPoint(0,12),QPoint(-4,0)};
static QPoint hour[4] = {QPoint(0,-50),QPoint(6,0),QPoint(0,13),QPoint(-6,0)};

class Clock : public QWidget
{
    Q_OBJECT
public:
    explicit Clock(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // CLOCK_H
