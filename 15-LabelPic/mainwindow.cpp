#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "card.h"

const int width = 80;
const int height = 105;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QPixmap pic(":/file/image/logo.png");  // 创建QPixmap对象
//    ui->label->resize(pic.size());      // 以图片的大小设置label的大小
//    ui->label->setPixmap(pic);
    showPic(Card(Card_2, Diamond));
}




MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::showPic(Card card)
{
    QPixmap pic(":/file/image/card.png");

    int point = card.point();
    int suit = card.suit();

    if (point <= Card_2)
    {
        QPixmap cardPic = pic.copy((point-1)*80, (suit-1)*105, 80, 105).scaled(40, 53);
        ui->label->setPixmap(cardPic);
    }
    else if (point > Card_2 && point < Card_end)
    {
        QPixmap cardPic = pic.copy((point == Card_SJ ? 0 : 1)*80, 4*105, 80, 105).scaled(40, 53);
        ui->label->setPixmap(cardPic);
    }
}

void MainWindow::on_pushButton_clicked()
{
    CardPoint_t p = (CardPoint_t)(ui->pointComboBox->currentIndex() + 1);
    CardSuit_t s = (CardSuit_t)(ui->suitComboBox->currentIndex() + 1);

    showPic(Card(p, s));
}
