#include "testdialog.h"
#include <QApplication>
#include "news.h"
#include "reader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestDialog w;
    w.show();

    // 新闻对象
    News n1("腾讯新闻", "体育新闻", "篮球决赛。。。。");
    News n2("新浪新闻", "爆料新闻", "小伙与大妈抢广场...");
    News n3("腾讯新闻", "娱乐八卦", "吴伟斌决定退出娱乐圈");

    // 读者对象
    Reader r1("aaa");
    Reader r2("bbb");

    // 建立连接 == 订阅新闻
    QObject::connect(&n1, SIGNAL(newMessage(QString,QString,QString)),
                     &r1, SLOT(readMessage(QString,QString,QString)));

    QObject::connect(&n2, SIGNAL(newMessage(QString,QString,QString)),
                     &r1, SLOT(readMessage(QString,QString,QString)));


    QObject::connect(&n3, SIGNAL(newMessage(QString,QString,QString)),
                     &r2, SLOT(readMessage(QString,QString,QString)));
    QObject::connect(&n2, SIGNAL(newMessage(QString,QString,QString)),
                     &r2, SLOT(readMessage(QString,QString,QString)));

    // 发布新闻
    n1.sendNews();
    n3.sendNews();
    n2.sendNews();

    return a.exec();
}
