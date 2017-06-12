#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QTcpSocket;

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
    void readMessage(void);

private:
    Ui::MainWindow *ui;
    QTcpSocket *_tcpSocket;

    quint16 _length;    // 保存每个包的数据长度
    QString _message;   // 保存每个包的数据体。
};

#endif // MAINWINDOW_H
