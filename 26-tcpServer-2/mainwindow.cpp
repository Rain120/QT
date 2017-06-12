#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QDebug>
#include <QDataStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建服务器对象
    _tcpserver = new QTcpServer(this);

    connect(_tcpserver, SIGNAL(newConnection()),
            this, SLOT(sendMessage()));

    // 绑定和监听
    if(!_tcpserver->listen(QHostAddress::Any, 6666))
    {
        qDebug() << "监听失败";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 发送数据
// 自定更加复杂的协议：
//     包格式： 数据长度（2字节） + 数据体（QString）

void MainWindow::sendMessage()
{
    QByteArray array;
    QDataStream wStream(&array, QIODevice::WriteOnly);
    wStream.setVersion(QDataStream::Qt_5_2);

    // 1.数据大小(2bytes)
    wStream << (quint16)0;   // 大小暂时定位为0， 预留2字节的空间

    // 2.数据体
    QString str = "hello 中国";
    wStream << str;

    // 定位到0位置，写入数据体实际大小
    wStream.device()->seek(0);
    wStream << (quint16)(array.size() - sizeof(quint16));

    // 获取连接套接字
    QTcpSocket* tcpSocket = _tcpserver->nextPendingConnection();
    tcpSocket->write(array);

    qDebug() << "发送结束";


}
