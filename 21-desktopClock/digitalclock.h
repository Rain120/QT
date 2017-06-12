#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber>
#include <QTimer>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT
public:
    explicit DigitalClock(QWidget *parent = 0);

private slots:
    void showTime();

};

#endif // DIGITALCLOCK_H
