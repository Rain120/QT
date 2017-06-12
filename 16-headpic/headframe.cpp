#include "headframe.h"
#include "ui_headframe.h"
#include <QPixmap>
#include <QDebug>

HeadFrame::HeadFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::HeadFrame)
{
    ui->setupUi(this);
}

HeadFrame::HeadFrame(QString picName, QString nickString, QWidget *parent):
    QFrame(parent),
    ui(new Ui::HeadFrame),
    _picName(picName), _nickString(nickString)
{
    ui->setupUi(this);

    QPixmap pic(_picName);
    ui->picLabel->setPixmap(pic.scaled(ui->picLabel->size()));
    ui->nickLabel->setText(_nickString);
}


HeadFrame::~HeadFrame()
{
    delete ui;
}
QString HeadFrame::picName() const
{
    return _picName;
}

void HeadFrame::setPicName(const QString &picName)
{
    _picName = picName;
    ui->picLabel->setPixmap(QPixmap(picName).scaled(ui->nickLabel->size()));
}

QString HeadFrame::nickString() const
{
    return _nickString;
}

void HeadFrame::setNickString(const QString &nickString)
{
    _nickString = nickString;
    ui->nickLabel->setText(nickString);
}



void HeadFrame::on_pushButton_clicked()
{
    qDebug() << "hahaha 我被点击了";
}
