#include "newdialog.h"
#include "ui_newdialog.h"

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
}

NewDialog::NewDialog(int sum, QWidget *parent):
    QDialog(parent),
    ui(new Ui::NewDialog), _sum(sum)
{
    ui->setupUi(this);

    //ui->lineEdit->setText(QString::number(sum));
}

NewDialog::~NewDialog()
{
    delete ui;
}

void NewDialog::on_pushButton_clicked()
{
    ui->lineEdit->setText(QString::number(_sum));
}

void NewDialog::getSumResult(QString sumStr)
{
    ui->lineEdit->setText(sumStr);
}
