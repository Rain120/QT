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

signals:
    void retValue(QString str);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public:
    QString _sumStr;

private:
    Ui::TestDialog *ui;
};

#endif // TESTDIALOG_H
