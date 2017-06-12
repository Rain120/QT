#include "userdb.h"

userDB::userDB(QString name, QString pwd):
    _userName(name), _pwd(pwd)
{    
}
QString userDB::userName() const
{
    return _userName;
}

void userDB::setUserName(const QString &value)
{
    _userName = value;
}
QString userDB::pwd() const
{
    return _pwd;
}

void userDB::setPwd(const QString &pwd)
{
    _pwd = pwd;
}


