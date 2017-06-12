#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int id = this->startTimer(1000);
    qDebug() << "aaa:" << id;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    static int i = 0;

    if (i++ < 5)
    {
        qDebug() << event->timerId();
    }
    else
    {

        killTimer(event->timerId());
    }
}
