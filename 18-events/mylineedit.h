#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent = 0);

signals:

protected:
    void keyPressEvent(QKeyEvent * event);
    bool event(QEvent *ev);
public slots:

};

#endif // MYLINEEDIT_H
