#include "testdialog.h"
#include "ui_testdialog.h"

/*
 * 新闻：
 *  新闻发布者：  _name
 *  类型： _type
 *  内容： _content
 *
 *  发布新闻： 发射信号
 *
 *
 *
 *
 * 新闻读者：
 *   姓名：  _name
 *
 * */



TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    ui->setupUi(this);
}

TestDialog::~TestDialog()
{
    delete ui;
}
