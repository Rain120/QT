#include "database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

DataBase *DataBase::_sqlDB = NULL;

DataBase::DataBase()
{
    // 1.加载数据库驱动
    _db = QSqlDatabase::addDatabase("QSQLITE", "testConnect");
    _db.setDatabaseName("user.db");

    // 2.打开数据库
    if (!_db.open())
    {
        qDebug() << "打开失败：" << _db.lastError().text();
        return;
    }

    // 打开成功

    // 3.执行sql
    QSqlQuery query(_db);
    QString sql = "create table if not exists t_user(uid integer primary key, userName varchar(50), pwd varchar(50));";
    if (!query.exec(sql))
    {
        qDebug() << query.lastError().text();
    }
}


// 获取单例
DataBase* DataBase::getDatabaseInstance()
{
    if (_sqlDB == NULL)
    {
        _sqlDB = new DataBase;
    }

    return _sqlDB;
}


/*
 *
 * */

bool DataBase::insertDB(userDB &user)
{
    QString sql = QString("insert into t_user values (NULL, '%1', '%2')")
            .arg(user.userName())
            .arg(user.pwd());

    QSqlQuery query(_db);
    if (!query.exec(sql))
    {
        qDebug() << "insert:"<<query.lastError().text();
        return false;
    }
    return true;
}

//
void DataBase::queryAllUsers()
{
    int i=0;
    QString sql = "select * from t_user;";
    QSqlQuery query(_db);
    if (!query.exec(sql))
    {
        qDebug() << "insert:"<<query.lastError().text();
        return ;
    }

    while(query.next())
    {
        QSqlRecord record = query.record();
        qDebug() << record.value(0).toInt();
        qDebug() << record.value(1).toString();
        qDebug() << record.value(2).toString();
    }


}
