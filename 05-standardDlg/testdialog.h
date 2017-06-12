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

private slots:

    void on_colorButton_clicked();

    void on_fontButton_clicked();

    void on_fileOpenButton_clicked();

private:
    Ui::TestDialog *ui;
};

#endif // TESTDIALOG_H
