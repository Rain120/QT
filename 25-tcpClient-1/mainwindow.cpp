#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>

// 1. 客户端向服务器发起连接，等待接收服务器发送的数据。
// 2.服务器端接受连接后，向客户端发送："Hello";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1.创建socket对象
    _tcpSocket = new QTcpSocket(this);
    connect(_tcpSocket, SIGNAL(readyRead()),
            this, SLOT(readMessage()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // 2.获取服务器主机地址
    QHostAddress address = QHostAddress(ui->lineEdit->text());
    _tcpSocket->connectToHost(address, 8888);

}


// socket接收到数据，执行该函数
void MainWindow::readMessage()
{
    QByteArray array;
    array.resize(_tcpSocket->bytesAvailable());

    // 3. 读
    _tcpSocket->read(array.data(), array.size());

    // 显示
    ui->statusLabel->setText(QString(array));

    // 4. 关闭
    _tcpSocket->close();

}
