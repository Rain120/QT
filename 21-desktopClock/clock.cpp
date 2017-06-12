#include "clock.h"
#include <QTime>


Clock::Clock(QWidget *parent) :
    QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

}


void Clock::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QTime time = QTime::currentTime();

    // j将原点平移到100，100的位置
    painter.translate(100, 100);
    painter.setRenderHint(QPainter::Antialiasing);  // 抗锯齿效果

    // 秒钟
    painter.setBrush(Qt::red); // 画刷
    painter.setPen(Qt::red);  // 画笔
    painter.save();  // 保存painter状态

    painter.rotate(6.0*time.second());
    painter.drawConvexPolygon(sed, 4);
    painter.restore(); //  恢ua复painter状态

    // 分钟
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::blue);
    painter.save();
    painter.rotate(6.0*(time.minute()+time.second()/60.0));
    painter.drawConvexPolygon(min, 4);
    painter.restore();

    // 时钟
    painter.setBrush(Qt::black);
    painter.setPen(Qt::black);
    painter.save();
    painter.rotate(30.0*(time.hour()+time.minute()/60.0));
    painter.drawConvexPolygon(hour, 4);
    painter.restore();

    //刻度
    for (int i=0; i<12; i++) {
        painter.drawLine(0, -98, 0, -90);
        painter.rotate(6);
        for(int j=0; j<4; j++) {
            painter.drawLine(0, -98, 0, -97);
            painter.rotate(6);
        }
    }
}

