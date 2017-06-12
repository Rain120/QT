#ifndef NEWS_H
#define NEWS_H

#include <QObject>

class News : public QObject
{
    Q_OBJECT
public:
    explicit News(QObject *parent = 0);
    explicit News(QString name, QString type, QString content, QObject *parent = 0) :
        _name(name), _type(type), _content(content), QObject(parent)
    {}

    // 发布新闻
    void sendNews(void)
    {
        emit newMessage(_name, _type, _content);
    }

signals:  // 信号
    void newMessage(QString name, QString type, QString content);

public slots:

private:
    QString _name;   // 新闻发布者
    QString _type;   // 新闻类型
    QString _content;  // 内容

};

#endif // NEWS_H
