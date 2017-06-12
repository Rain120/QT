#ifndef SERVER_H
#define SERVER_H

#include "tcpserver.h"
#include "tcpclientsocket.h"

class Server :QObject
{
public:
    Server(QObject *parent = 0);

    // 启动服务器
    void start(int port);

    // 停止服务器
    void stop(void);

    // 管理连接socket
    void addClient(TcpClientSocket* c);

    // 获取连接socket
    QList<TcpClientSocket*> getClients(void);


private:
    TcpServer* _tcpServer;   // 监听服务器对象
    QList<TcpClientSocket*> _clients;  // 连接socket
};

#endif // SERVER_H
