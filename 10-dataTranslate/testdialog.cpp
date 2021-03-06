#include "testdialog.h"
#include "ui_testdialog.h"
#include "newdialog.h"

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(calcPushButton()));
}

TestDialog::~TestDialog()
{
    delete ui;
}


// 计算按钮
void TestDialog::calcPushButton()
{

#if 0
    //1.获取数据
    int num1 = ui->lineEdit->text().toInt();
    int num2 = ui->lineEdit_2->text().toInt();
    int sum = num1 + num2;

    //2.弹出新的对话框
    NewDialog dlg(sum);

    dlg.exec();

#endif


#if 0
    //1.获取数据
    int num1 = ui->lineEdit->text().toInt();
    int num2 = ui->lineEdit_2->text().toInt();
    QString sumStr = QString::number(num1 + num2);

    //2.弹出新的对话框
    NewDialog dlg;


    connect(this, SIGNAL(sumResult(QString)), &dlg, SLOT(getSumResult(QString)));
    emit sumResult(sumStr);

    dlg.exec();
#endif

    //1.获取数据
    int num1 = ui->lineEdit->text().toInt();
    int num2 = ui->lineEdit_2->text().toInt();
    QString sumStr = QString::number(num1 + num2);

    //2.弹出新的对话框
    NewDialog *pdlg = new NewDialog;
    //pdlg->setModal(true);
    connect(this, SIGNAL(sumResult(QString)), pdlg, SLOT(getSumResult(QString)));
    pdlg->show();

    emit sumResult(sumStr);
}
