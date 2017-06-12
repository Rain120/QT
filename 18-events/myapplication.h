#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>

class MyApplication : public QApplication
{
    Q_OBJECT
public:
    explicit MyApplication(int argc, char *argv[]);
    bool notify(QObject * receiver, QEvent * e);

signals:

protected:
   bool eventFilter(QObject *watched, QEvent *event);

public slots:

};

#endif // MYAPPLICATION_H
