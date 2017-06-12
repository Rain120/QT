#include "mainwindow.h"
#include <QApplication>
#include "myapplication.h"

int main(int argc, char *argv[])
{
    MyApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
