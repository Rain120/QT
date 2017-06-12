#include "testdialog.h"
#include "ui_testdialog.h"
#include <QDebug>
#include <QColorDialog>
#include <QPalette>

#include <QFontDialog>
#include <QFileDialog>
#include <QFile>

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("标准对话框测试");
}

TestDialog::~TestDialog()
{
    delete ui;
}


// 弹出颜色对话框
/*
QColor QColorDialog::getColor(const QColor & initial = Qt::white,
                              QWidget * parent = 0,
                              const QString & title = QString(),
                              ColorDialogOptions options = 0)      */

void TestDialog::on_colorButton_clicked()
{
#if 0
    // 1.模态弹出颜色对话框
    QColor color = QColorDialog::getColor(Qt::black, this, "我是颜色对话框");

    // 2.判断用户点击ok还是cancel
    if (color.isValid())
    {
        // 3.修改label字体颜色。

        // 3.1 读
        QPalette palett = ui->statusLabel->palette();

        // 3.2 改
        palett.setColor(QPalette::WindowText, color);

        // 3.3 写
        ui->statusLabel->setPalette(palett);

    }
    else
    {
        qDebug() << "取消颜色选择";
    }

    QRgb rgb = color.rgb();
  //  qDebug() << rgb;
    qDebug() << "#" << QString::number(rgb, 16) ;
#endif

    QColorDialog colorDlg(Qt::red, this);   // 创建对象
    colorDlg.setOption(QColorDialog::ShowAlphaChannel, true);  // 打开alpha通道
    colorDlg.exec();  // 模态弹出
    QColor color = colorDlg.currentColor();

    // 3.1 读
    QPalette palett = ui->statusLabel->palette();

    // 3.2 改
    palett.setColor(QPalette::WindowText, color);

    // 3.3 写
    ui->statusLabel->setPalette(palett);


}


// 字体对话框
void TestDialog::on_fontButton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this, "字体对话框");
    if (ok) {
        // font is set to the font the user selected
        ui->statusLabel->setFont(font);
    } else {
        // the user canceled the dialog; font is set to the initial
        // value, in this case Times, 12.

    }
}

// 文件对话框
/*QString QFileDialog::getOpenFileName(QWidget * parent = 0,
                                     const QString & caption = QString(),
                                     const QString & dir = QString(),
                                     const QString & filter = QString(),
                                     QString * selectedFilter = 0,
                                     Options options = 0)  */

// 1. 打开文件  2.操作文件  3.关闭文件
void TestDialog::on_fileOpenButton_clicked()
{
#if 0
    // 通过打开对话框获取文件路径
    QString path = QFileDialog::getOpenFileName(this, "文件打开对话框", "D:/",
                                                "图片(*.png *.jpg *.gif);;文本文件(*.txt);;所有文件(*)");
    qDebug() << path;

    // 创建文件对象
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // 打开成功

        // 读
        QByteArray array = file.readAll();

        QString text = QString::fromLocal8Bit(array);  // 讲读取的内容从本地编码转为UTF-8
        // 显示到label
        ui->statusLabel->setText(text);

        file.close();

    }
    else
    {
        // 打开失败
        qDebug() << "文件打开失败";
    }



#endif

    QStringList strlist = QFileDialog::getOpenFileNames(this, "打开文件对话框",
                                                       "D:/", "文本文件（*.txt);;所有文件(*.*)");
    for (int i=0; i<strlist.length(); i++)
    {
        QFile file(strlist[i]);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QByteArray array = file.readAll();
            qDebug() << QString::fromLocal8Bit(array);

            file.close();
        }
    }

}
