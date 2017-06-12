#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylineedit.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _lineEdit = new MyLineEdit(this);
    _lineEdit->resize(100, 30);
    _lineEdit->move(20, 20);

    _lineEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "MainWindow::keyPressEvent";
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (_lineEdit == watched)
    {
        if (event->type() == QEvent::KeyPress)
            qDebug() << "MainWindow::eventFilter";
    }
    return QMainWindow::enterEvent(watched, event);

}
