#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "headframe.h"
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _head = new HeadFrame(":/file/image/background.jpg", "哈哈哈", this);

    QLineEdit* l = new QLineEdit("adfadfasd", this);
    l->resize(200, 200);

    _head->raise();

   // head->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    _head->setPicName(":/file/image/logo.png");
    _head->setNickString("嘻嘻嘻");
}
