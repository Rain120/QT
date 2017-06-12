#include "server.h"
#include <QMessageBox>
#include <QDebug>

Server::Server(QObject *parent):
    QObject(parent)
{
    _tcpServer = new TcpServer(this);
}

void Server::start(int port)
{
    // 启动监听
    if (false == _tcpServer->listen(QHostAddress::Any, port))
    {
        QMessageBox::warning(NULL, "error", "无法启动监听", QMessageBox::Ok);
        qDebug() << _tcpServer->errorString();
    }
}

void Server::stop()
{
    // 清list
    _clients.clear();;

    // 关闭服务器
    _tcpServer->close();

}

void Server::addClient(TcpClientSocket *c)
{
    _clients.append(c);
}

QList<TcpClientSocket *> Server::getClients()
{
    return _clients;
}
