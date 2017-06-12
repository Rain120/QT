#include "testdialog.h"
#include "ui_testdialog.h"

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    ui->setupUi(this);
    _sumStr = "结果：";
}

TestDialog::~TestDialog()
{
    delete ui;
}

void TestDialog::on_pushButton_clicked()
{
#if 0
    // 数据回传
    int num1 = ui->lineEdit->text().toInt();
    int num2 = ui->lineEdit_2->text().toInt();
    _sumStr = QString::number(num1 + num2);

    // 关闭对话框
//    this->accept();
    done(QDialog::Accepted);
#endif

    // 1.计算结果
    int num1 = ui->lineEdit->text().toInt();
    int num2 = ui->lineEdit_2->text().toInt();
    QString sumStr = QString::number(num1 + num2);

    // 2.发送信号
    emit retValue(sumStr);

    // 3.关窗口
    this->close();
}

void TestDialog::on_pushButton_2_clicked()
{
#if 0
//    this->reject();
    done(0);
#endif

    close();
}
