#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpclientsocket.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connectButton_clicked();

    void on_sendButton_clicked();

    void dispMessage(QMap<QString,QString>msg);

private:
    Ui::MainWindow *ui;

    TcpClientSocket* _tcpSocket;
};

#endif // MAINWINDOW_H
