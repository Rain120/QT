#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>
#include <QMap>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = 0);

    void setServerIP(QString serverip);
    QString getServerIP(void);

    void setServerPort(QString serverport);
    QString getServerPort(void);

    //
    // 连接到服务器
    bool connectToServer(void);
    bool testConnect(void);

    // 发送消息
    // "uname:lily"
    // "pwd:123"
    void sendMessage(QMap<QString, QString> msg);

signals:
    void dealMessage(QMap<QString, QString> msg);

public slots:
    // 接收消息
    // "uname:lily"
    // "pwd:123"
    void receiveMessage(void);


private:
    QString _serverIP;   // 服务器的IP
    QString _serverPort;  // 服务器端口号

    quint16 _blocksize;   // 消息体的大小


};

#endif // TCPCLIENTSOCKET_H
