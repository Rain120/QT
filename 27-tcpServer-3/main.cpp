#include "mainwindow.h"
#include <QApplication>

MainWindow* mw = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    mw = &w;

    return a.exec();
}
