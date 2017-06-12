#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _tcpSocket = new TcpClientSocket(this);
    connect(_tcpSocket, SIGNAL(dealMessage(QMap<QString,QString>)),
            this, SLOT(dispMessage(QMap<QString,QString>)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    QString strIp = ui->ipLineEdit->text();
    QString strPort = ui->portLineEdit->text();

    _tcpSocket->setServerIP(strIp);
    _tcpSocket->setServerPort(strPort);

    _tcpSocket->connectToServer();
}

// 发送
void MainWindow::on_sendButton_clicked()
{
    QMap<QString, QString> msg;
    msg["chat"] = ui->sendLineEdit->text();

    _tcpSocket->sendMessage(msg);
}

// 显示消息
void MainWindow::dispMessage(QMap<QString, QString> msg)
{
    QString str = msg.keys().at(0) + ":" + msg.values().at(0);
    //显示接收到的消息
    ui->recvLineEdit->setText(str);
}
