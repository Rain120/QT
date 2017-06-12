#include "digitalclock.h"
#include <QTime>
DigitalClock::DigitalClock(QWidget  *parent) :
    QLCDNumber(parent)
{
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    showTime();
}

void DigitalClock::showTime() {
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() %2) == 0) {
        text[2] = ' ';
    }
    setSegmentStyle(Flat);
    display(text);
}
