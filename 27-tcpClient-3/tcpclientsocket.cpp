#include "tcpclientsocket.h"
#include <QDataStream>


TcpClientSocket::TcpClientSocket(QObject *parent) :
    QTcpSocket(parent)
{
    //
    _blocksize = 0;
    connect(this, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
}

void TcpClientSocket::setServerIP(QString serverip)
{
    _serverIP = serverip;
}

QString TcpClientSocket::getServerIP()
{
    return _serverIP;
}

void TcpClientSocket::setServerPort(QString serverport)
{
    _serverPort = serverport;
}

QString TcpClientSocket::getServerPort()
{
    return _serverPort;
}

// 连接到服务器
bool TcpClientSocket::connectToServer()
{
    bool ret = true;
    abort();        // 中断当前的连接

    ret = testConnect();

    if (!ret)
    {
        return ret;
    }

    // 连接到服务器。
    connectToHost(_serverIP, _serverPort.toInt());
    return ret;

}



bool TcpClientSocket::testConnect()
{
    this->disconnectFromHost();   // 断开当前socket与主机的连接

    // 连接到服务器。
    connectToHost(_serverIP, _serverPort.toInt());

    bool ret = waitForConnected();

    // 断开连接
    disconnectFromHost();

    return ret;

}

// 发送消息
/*
key:  uname
value: lily
"uname:lily"
*/

/*
msg["uname"] = "lily";
msg["sex"]  = "女";
msg["age"] =  "10";
*/


void TcpClientSocket::sendMessage(QMap<QString, QString> msg)
{
    QByteArray block;  //  暂存待发送的数据
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);

    // 预留2个字节的空间
    out << (quint16)0;

    // 写入实际的消息体
    foreach (QString key, msg.keys())
    {
        QString tmpMsg = key + ":" + msg[key];
        out << tmpMsg;
    }

    out.device()->seek(0);
    // 写入实际的消息体大小
    out << (quint16)(block.size() - sizeof(quint16));

    // 发送信息
    this->write(block);
}

// 接收
void TcpClientSocket::receiveMessage()
{
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_5_2);

    // 获取消息体的大小
    if (_blocksize == 0)
    {
        if (this->bytesAvailable() < (int)sizeof(_blocksize))
        {
            return;
        }
        // 接收到了2个字节以上的数据
        in >> _blocksize;
    }

    // 接收消息体
    int initBytes = this->bytesAvailable();

    // 判断消息体是否接收完毕
    if (initBytes < _blocksize)
    {
        return;
    }

    int msgSize = 0;   // 已读取的数据

    // 消息体已经接收完毕
    QMap<QString, QString> msg;

    while(msgSize < _blocksize)
    {
        QString tmpMsg;
        in >> tmpMsg;      // "uname:lily"

        int idxSpiliter = tmpMsg.indexOf(":");
        msg[tmpMsg.mid(0, idxSpiliter)] = tmpMsg.mid(idxSpiliter+1, tmpMsg.length() - idxSpiliter);
        msgSize = initBytes - bytesAvailable();  // 已读消息大小
    }

    // 消息接收完毕
    emit dealMessage(msg);

    // 递归调用，再次处理剩余的数据
    _blocksize = 0;
    if (bytesAvailable() > 0)
    {
        this->receiveMessage();  // 继续接收。
    }
}
