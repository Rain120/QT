#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include "userdb.h"

/*
 * 单例模式：
 * 1.构造函数私有化
 * 2.添加静态的公共的获取实例的接口函数
 */

class DataBase
{
private:
    DataBase();

public:

   static DataBase* getDatabaseInstance(void);

    // 插入
   bool insertDB(userDB &user);

    // 删除


    // 修改



    // 查询

   void queryAllUsers(void);


private:
   QSqlDatabase _db;
   static DataBase *_sqlDB;     // 保存单个实例




};

#endif // DATABASE_H
