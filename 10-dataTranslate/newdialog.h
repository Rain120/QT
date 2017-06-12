#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDialog(QWidget *parent = 0);
    explicit NewDialog(int sum, QWidget *parent = 0);
    ~NewDialog();

private slots:
    void on_pushButton_clicked();

    void getSumResult(QString sumStr);
private:
    Ui::NewDialog *ui;
    int _sum;
};

#endif // NEWDIALOG_H
