#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>

namespace Ui {
class TestDialog;
}

class TestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestDialog(QWidget *parent = 0);
    ~TestDialog();

signals:   // 信号
    void showName(QString name);

public slots:   // 槽
    void printMessage();
    void on_pushButton_clicked();
    void showLabelText(QString name);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TestDialog *ui;
};

#endif // TESTDIALOG_H
