#ifndef USERDB_H
#define USERDB_H

#include <QString>

class userDB
{
public:
    userDB(QString name, QString pwd);

    QString userName() const;
    void setUserName(const QString &value);

    QString pwd() const;
    void setPwd(const QString &pwd);

private:
    QString _userName;
    QString _pwd;
};

#endif // USERDB_H
