#include "testdialog.h"
#include "ui_testdialog.h"
#include <QDebug>
#include <QMessageBox>

/*
 *
 * 信号发送对象：
 *      1.定义（声明）信号
 *      2.合适的时机/位置发射信号
 *
 * 信号接收对象：
 *      1.定义（声明）一个槽函数（必须与信号匹配）
 *      2.实现槽函数的业务功能
 *
 * 发送对象的信号与接收对象的槽函数必须建立连接。
 *      connect( 发送对象, 发送的信号, 接收对象, 槽函数 );
 *
 * */

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    ui->setupUi(this);

    // 情况1：
    // 发送对象：内部类已经定义好的信号， 发送时机也是内部规定好的。
    // 接收对象：槽函数也内部定义好，并且已经实现了特定的业务功能。

    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(showMaximized()));

    // 情况2：
    // 发送对象：Qt信号已定义，发送时机已确定.
    // 接收对象：Qt槽函数自定义
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(printMessage()));

    // 情况3：
    // 发送对象：Qt信号未定义
    // 接收对象：Qt槽已定义
    connect(this, SIGNAL(showName(QString)), ui->label, SLOT(setText(QString)));

    // 情况4：
    // 发送对象：Qt信号未定义
    // 接收对象：Qt槽未定义， 自定义
    connect(this, SIGNAL(showName(QString)), this, SLOT(showLabelText(QString)));
}

TestDialog::~TestDialog()
{
    delete ui;
}

void TestDialog::printMessage()
{
    qDebug() << "连接成功。。。，我被点击了";
}


// 自动连接，必须调用过QMetaObject::connectSlotsByName(TestDialog);
// 命名规则：on_对象名_信号名
void TestDialog::on_pushButton_clicked()
{
    qDebug() << "手写自动连接";
}



void TestDialog::showLabelText(QString name)
{
    qDebug() << "获取的数据是：" << name;
    ui->label->setText("我的母校是：" + name);
}



// 发送按钮槽函数
void TestDialog::on_pushButton_2_clicked()
{
    int ret = QMessageBox::question(this, "提问", "是否显示你们的母校？", QMessageBox::Yes, QMessageBox::No);
    if (ret == QMessageBox::Yes)
    {
        // label显示学校名称。
        // ui->label->setText("南昌航空大学");
        emit showName("南昌航空大学");  // 发射信号
    }
}

void TestDialog::on_pushButton_3_clicked()
{
    qDebug() << "获取到了信息....";
    QString str = "南昌航空大学";

    emit showName(str);
}
