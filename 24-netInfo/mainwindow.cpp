#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString hostName = QHostInfo::localHostName();
    QString domainName = QHostInfo::localDomainName();

//    qDebug() << hostName << domainName;
//    QHostInfo info = QHostInfo::fromName(hostName);
//    QList<QHostAddress> list = info.addresses();
//    QHostAddress address;
//    foreach (address, list) {
//        if (address.protocol() == QAbstractSocket::IPv4Protocol)
//        {
//            qDebug() << address;
//            ui->label->setText(address.toString());
//        }
//    }

//    QHostInfo::lookupHost("www.nchu.edu.cn",
//                          this, SLOT(lookedUp(QHostInfo)));


//    QList<QHostAddress> adds = QNetworkInterface::allAddresses();
//    foreach (QHostAddress address, adds) {
//        if (address.protocol() == QAbstractSocket::IPv4Protocol)
//        {
//            qDebug() << address;
//            ui->label->setText(address.toString());
//        }
//    }
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface inter, interfaces) {
        QList<QNetworkAddressEntry> entrys = inter.addressEntries();

        foreach (QNetworkAddressEntry entry, entrys) {
           qDebug() << "ip:" << entry.ip();
           qDebug() << "broadcast:" << entry.broadcast();
           qDebug() << "netmask:" << entry.netmask();
        }
    }
    //QNetworkAddressEntry

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lookedUp(const QHostInfo &host)
{
    if (host.error() != QHostInfo::NoError) {
            qDebug() << "Lookup failed:" << host.errorString();
            return;
        }

        foreach (const QHostAddress &address, host.addresses())
            qDebug() << "Found address:" << address.toString();
}
