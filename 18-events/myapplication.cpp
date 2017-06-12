#include "myapplication.h"
#include <QDebug>

MyApplication::MyApplication(int argc, char *argv[]) :
    QApplication(argc, argv)
{
}

bool MyApplication::notify(QObject *receiver, QEvent *e)
{
    if (e->type() == QEvent::KeyPress)
    {
        qDebug() << "MyApplication::notify ->" << receiver;
    }

    return QApplication::notify(receiver, e);
}

bool MyApplication::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        qDebug() << "MyApplication::eventFilter ->" << watched;
    }
    return QApplication::eventFilter(watched, event);
}
