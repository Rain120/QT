#ifndef READER_H
#define READER_H

#include <QObject>
#include <QDebug>

class Reader : public QObject
{
    Q_OBJECT
public:
    explicit Reader(QString name, QObject *parent = 0);

signals:

public slots:
    void readMessage(QString name, QString type, QString content)
    {
        qDebug() << _name << "看了" << name << "发布的" << type << "新闻";
        qDebug() << "新闻内容是：" << content;
    }

private:
    QString _name;   // 姓名

};

#endif // READER_H
