#include "tcpserver.h"
#include "tcpclientsocket.h"
#include "common.h"
#include "mainwindow.h"

extern MainWindow* mw;

TcpServer::TcpServer(QObject *parent) :
    QTcpServer(parent)
{
}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    // 1.创建socket
    TcpClientSocket* tcpClientSocket = new TcpClientSocket(this);

    // 2.设置socket描述符
    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    // 3.管理tcpClientsocket 添加到list中
    Server* s = Common::getServerInstance();
    s->addClient(tcpClientSocket);

    // 4.建立信号槽关联
    connect(tcpClientSocket, SIGNAL(dealMessage(QMap<QString,QString>)),
            mw, SLOT(dispMessage(QMap<QString,QString>)));

}
