#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // 初始化子部件
    ui->radioButton_3->setChecked(true);

    connect(ui->checkBox, SIGNAL(stateChanged(int)), this, SLOT(showToLabel()));
    connect(ui->checkBox_2, SIGNAL(clicked()), this, SLOT(showToLabel()));
    connect(ui->checkBox_3, SIGNAL(clicked()), this, SLOT(showToLabel()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showToLabel()
{
    QString str = "";
    if (ui->checkBox->isChecked())
    {
        str += ui->checkBox->text() + " ";

    }

    if (ui->checkBox_2->isChecked())
    {
        str += ui->checkBox_2->text() + " ";
    }

    if (ui->checkBox_3->isChecked())
    {
        str += ui->checkBox_3->text();
    }

    ui->hobbyLabel->setText(str);

}

