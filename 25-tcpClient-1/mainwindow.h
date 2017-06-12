#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QTcpSocket;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void readMessage(void);

private:
    Ui::MainWindow *ui;
    QTcpSocket* _tcpSocket;
};

#endif // MAINWINDOW_H
