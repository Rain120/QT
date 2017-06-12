#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QTcpServer;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void sendMessage(void);

private:
    Ui::MainWindow *ui;
    QTcpServer* _server;
};

#endif // MAINWINDOW_H
