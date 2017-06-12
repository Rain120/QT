#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void dispMessage(QMap<QString, QString> msg);

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_sendButton_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
