#include "mylineedit.h"
#include <QDebug>
#include <QKeyEvent>

MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "MyLineEdit::keyPressEvent";
    //event->accept();

    QLineEdit::keyPressEvent(event);

    event->ignore();


}

// event
bool MyLineEdit::event(QEvent *ev)
{
    if (ev->type() == QEvent::KeyPress)
    {
        qDebug() << "MyLineEdit::event";
    }
    return QLineEdit::event(ev);
}
