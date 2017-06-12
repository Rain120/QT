#include "testdialog.h"
#include <QApplication>
#include <QPushButton>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestDialog w;

  /*  // 创建对象
    QPushButton *pbt = new QPushButton("最小化", &w);
    pbt->setGeometry(10, 10, 100, 20);
    //pbt->show();
    QObject::connect(pbt, SIGNAL(clicked()), &w, SLOT(showMinimized()));
*/


    w.show();  // 建立连接

    // 父窗口：
    // 父类：









    return a.exec();
}
