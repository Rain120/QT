#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



protected:
    void keyPressEvent(QKeyEvent * event);
    bool eventFilter(QObject * watched, QEvent * event);

private:
    Ui::MainWindow *ui;
    MyLineEdit *_lineEdit;
};

#endif // MAINWINDOW_H
