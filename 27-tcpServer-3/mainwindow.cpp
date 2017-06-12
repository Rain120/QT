#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 启动
void MainWindow::on_startButton_clicked()
{
    // 获取服务器对象
    Server* s = Common::getServerInstance();
    int port = ui->portLineEdit->text().toInt();
    s->start(port);

    // 界面处理
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);

}

void MainWindow::on_stopButton_clicked()
{
    // 获取服务器对象
    Server* s = Common::getServerInstance();
    s->stop();

    // 界面处理
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
}


// 发送消息
void MainWindow::on_sendButton_clicked()
{
    // 获取服务器对象
    Server* s = Common::getServerInstance();

    // 获取socket
    QList<TcpClientSocket*> clients = s->getClients();

    foreach (TcpClientSocket* c, clients) {
        // 创建msg
        QMap<QString, QString> msg;
        msg["reply"] = ui->sendLineEdit->text();

        // 发送
        c->sendMessage(msg);
    }
}


// 显示消息
void MainWindow::dispMessage(QMap<QString, QString> msg)
{
    QString str = msg.keys().at(0) + ":" + msg.values().at(0);
    //显示接收到的消息
    ui->recvLineEdit->setText(str);
}
