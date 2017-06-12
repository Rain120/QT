#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMouseEvent>
#include <QCursor>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    //　设置窗口的鼠标
    this->setCursor(cursor);

    //setMouseTracking(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //if (event->button() & Qt::LeftButton)
    {
        QPoint endPoit = event->globalPos();

        QPoint t = endPoit - _offset;

        this->move(t);
        qDebug()<<"MainWindow::mouseMoveEvent";


    }

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    _offset = event->globalPos() - pos();   // 计算点击的位置和窗口相对桌面的距离差值
    qDebug() << event->globalPos()
             << ":" << event->pos()
             << ":" << pos()
             << ":" << _offset;

    qDebug()<<"MainWindow::mousePressEvent";
    if (event->button() == Qt::LeftButton)
    {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
    }
    else if (event->button() == Qt::RightButton)
    {
        QPixmap pic(":/file/image/help.png");
        QCursor cursor(pic);

        // 使得鼠标暂时修改为cursor
        QApplication::setOverrideCursor(cursor);
    }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"MainWindow::mouseReleaseEvent";
    //　恢复之前的鼠标
    QApplication::restoreOverrideCursor();
}



void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "MainWindow::mouseDoubleClickEvent";
#if 0
    if(event->button() == Qt::LeftButton)
    {
        if (this->isMaximized())
        {
            this->showNormal();
        }
        else
        {
            this->showMaximized();
        }
    }
#endif

#if 0

    if (event->button() == Qt::LeftButton)
    {
        if (windowState() == Qt::WindowMaximized)
        {
            this->setWindowState(Qt::WindowNoState);
        }
        else
        {
            this->setWindowState(Qt::WindowMaximized);
        }
    }
#endif
}



void MainWindow::wheelEvent(QWheelEvent *event)
{

    qDebug() << event->angleDelta();
    if (event->delta() > 0)
    {
        qDebug() << "qian";
    }
    else
    {
        qDebug() << "hou";
    }
}
