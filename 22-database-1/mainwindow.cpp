#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QStringList strlist = QSqlDatabase::drivers();
//    qDebug() << strlist;

    // 1.加载数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "testConnect");
    db.setDatabaseName("stu.db");

    // 2.打开数据库
    if (!db.open())
    {
        qDebug() << "打开失败：" << db.lastError().text();
        return;
    }

    // 打开成功

    // 3.执行sql
    QSqlQuery query(db);
    QString sql = "create table if not exists t_stu(uid integer primary key, uname varchar(50) not null,"
            "cLang int, java int, cpp int);";
   if (!query.exec(sql))
   {
       qDebug() << query.lastError().text();
   }


    sql = "insert into t_stu values (NULL, '李雷', 100, 66, 90);";
    query.exec(sql);

    sql = "insert into t_stu values (NULL, '韩梅梅', 100, 78, 90);";
    query.exec(sql);

    sql = "insert into t_stu values (NULL, '李华', 100, 66, 90);";
    query.exec(sql);


    sql = "select * from t_stu";
    query.exec(sql);
    if (!query.isActive())
    {
        qDebug() << query.lastError().text();
    }


    while(query.next())
    {
       qDebug() << "uid:" << query.value(0).toInt();
       qDebug() << "uname:" << query.value(1).toString();
       qDebug() << "cLang:" << query.value(2).toInt();
       qDebug() << "java:" << query.value(3).toInt();
       qDebug() << "cpp:" << query.value(4).toInt();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
