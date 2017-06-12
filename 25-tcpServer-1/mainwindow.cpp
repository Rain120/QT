#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1.创建服务器对象。
    _server = new QTcpServer(this);

    // 建立信号槽
    connect(_server, SIGNAL(newConnection()),
            this, SLOT(sendMessage()));

    // 2.绑定和监听
    if (!_server->listen(QHostAddress::Any, 8888))
    {
        qDebug() <<"监听失败";
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


// 发送数据
void MainWindow::sendMessage()
{
    // 3.accept成功后，进行读写

    // (1)获取连接套接字
    QTcpSocket* tcpSocket = _server->nextPendingConnection();

    // （2）写数据
    QByteArray array("hello, 你好");
    tcpSocket->write(array);

    qDebug() << "发送完毕！！";

    // （3）断开连接
    tcpSocket->disconnectFromHost();
}
