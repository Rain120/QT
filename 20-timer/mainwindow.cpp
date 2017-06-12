#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTime time = QTime::currentTime();
    QString timeStr = time.toString("HH:mm:ss");
    ui->label->setText(timeStr);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(showCurrentTime()));
    timer->start(1000);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showCurrentTime()
{
    static int flag = 0;
    QTime t = QTime::currentTime();
    QString hStr = t.toString("HH");
    QString mStr = t.toString("mm");
    QString timeStr;
    if (flag == 0)
    {
        timeStr = hStr + ":" + mStr;
        flag = 1;
    }
    else
    {
        timeStr = hStr + " " + mStr;
        flag = 0;
    }
    ui->label->setText(timeStr);
}
