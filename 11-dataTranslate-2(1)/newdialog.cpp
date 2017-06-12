#include "newdialog.h"
#include "ui_newdialog.h"
#include "testdialog.h"

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
}

NewDialog::~NewDialog()
{
    delete ui;
}


// 新建
void NewDialog::on_pushButton_clicked()
{
#if 0
    // 1.弹出新的对话框
    TestDialog dlg;
    int ret = dlg.exec();

    if (QDialog::Accepted == ret)
    {
        // 对话框已经关闭
        QString str = dlg._sumStr;
        ui->label->setText(str);
    }
#endif

    // 2.非模态（其他窗口）
    TestDialog *pdlg = new TestDialog;

//    connect(pdlg, SIGNAL(retValue(QString)),
//            this, SLOT(getValue(QString)));

    connect(pdlg, SIGNAL(retValue(QString)),
            ui->label, SLOT(setText(QString)));

    pdlg->setAttribute(Qt::WA_DeleteOnClose);
    pdlg->show();

}

void NewDialog::getValue(QString str)
{
    ui->label->setText(str);

}
