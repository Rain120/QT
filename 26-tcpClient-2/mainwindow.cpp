#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QTcpSocket>
#include <QDataStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化一
    _length = 0;

    // 1.创建socket对象
    _tcpSocket = new QTcpSocket(this);

    connect(_tcpSocket, SIGNAL(readyRead()),
            this, SLOT(readMessage()));

    // 2.连接到服务器
    _tcpSocket->connectToHost(QHostAddress("127.0.0.1"), 6666);

}

MainWindow::~MainWindow()
{
    delete ui;
}


// readyRead：接收到数据会_tcpSocket发射。
//  接收到数据,如果正在执行readyRead的槽函数，不发射readyRead.

// 读取消息。 tcp 传输的是字节流 —— 粘包问题
// 运用层用代码区分边界；制定一个约定（格式/协议）
// 0x00 0x04 0x85 0x10 0x56  0x44  0x00 0x05 0x55 .... 0x85 0x88
// 1.定长包
// 2.特殊字符结尾 (\n)
// 3.自定更加复杂的协议：
//     包格式： 数据长度（2字节） + 数据体（QString）。


void MainWindow::readMessage()
{
//    // 3.读
//    QByteArray array;
//    array.resize(_tcpSocket->bytesAvailable());

//    // 3. 读
//    _tcpSocket->read(array.data(), array.size());

//    // 显示
//    ui->statusLabel->setText(QString(array));

//    // 4. 关闭
//    _tcpSocket->close();

    // 使用_tcpSocket创建字节流对象
    QDataStream rStream(_tcpSocket);
    rStream.setVersion(QDataStream::Qt_5_2);

    // 接收数据

    // 读取数据长度
    if (_length == 0)
    {
        // 可读数据大于2，读2个字节的长度。
        if (_tcpSocket->bytesAvailable() < 2)
        {
            // 尚未接收到2个字节
            return;
        }
        rStream >> _length;    // 读取数据长度
    }


    // 读数据体
    if (_tcpSocket->bytesAvailable() < _length)
    {
        // 尚未把该包的所有数据体数据接收完整。
        return;
    }
    rStream >> _message;    // 读取数据体

    ui->label->setText(_message);


    // 重新初始化_length以便下一次接收。
    _length = 0;
    if (_tcpSocket->bytesAvailable() > 0)
    {
        // 调用readMessage接收剩余的数据。
        this->readMessage();
    }

}
