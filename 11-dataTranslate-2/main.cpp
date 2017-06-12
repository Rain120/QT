#include "newdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NewDialog w;
    w.show();

    return a.exec();
}
