#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendar.h"
#include "digitalclock.h"
#include "clock.h"
#include <QLabel>
#include <QGroupBox>
#include <QBoxLayout>
#include <QTextCodec>
#include <QGridLayout>
#include <QLayout>
#include <QDate>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Mainwidow设置一个中心窗口。
    QWidget* widget = new QWidget();
    this->setCentralWidget(widget);

    QGridLayout *layout = new QGridLayout;
    //当日日期与数字时间
    QDate date = QDate::currentDate();
    QString text1 = date.toString(" yyyy年MM月dd日");
    QString text2 = date.toString("     dddd");

    QGroupBox *groupbox1=new QGroupBox("今天是");
//    groupbox1->resize(160, 100);
    QLabel *label1=new QLabel(text1) ;
    QLabel *label2=new QLabel(text2) ;

    QFont font3  = label1->font();
    font3.setPointSize(24);
    font3.setBold(true);
    label1->setFont(font3);
    QPalette palette1;
    palette1.setColor(QPalette::WindowText,Qt::red);
    label1->setPalette(palette1);

    QVBoxLayout *layout1=new QVBoxLayout() ;
    layout1->addWidget(label1);
    layout1->addWidget(label2);
    groupbox1->setLayout(layout1);

    // 设置字体（读-改-写）
    QFont font1  = groupbox1->font();
    font1.setPointSize(12);
    font1.setBold(true);
    groupbox1->setFont(font1);

    layout->addWidget(groupbox1, 0, 0, 1, 1);

    //刻度时间
    Clock *clock=new Clock;
    QGroupBox *groupbox2=new QGroupBox(tr("刻度时间"));
    groupbox2->setFixedSize(240, 240);
    QVBoxLayout *layout2=new QVBoxLayout ;
    layout2->addWidget(clock);
    groupbox2->setLayout(layout2);

    QFont font2  = groupbox2->font();
    font2.setPointSize(12);
    font2.setBold(true);
    groupbox2->setFont(font2);

    layout->addWidget(groupbox2, 0, 1, 1, 1);


    // 数字时钟
    DigitalClock *digitalClock=new DigitalClock;
    QGroupBox *groupbox3=new QGroupBox(tr("数字时钟"));
    QVBoxLayout *layout3=new QVBoxLayout ;
    layout3->addWidget(digitalClock);
    groupbox3->setLayout(layout3);

    layout->addWidget(groupbox3, 1, 0, 1, 1);


    //日历查询

    Calendar *calendar=new Calendar(this) ;
    QVBoxLayout *layout4=new QVBoxLayout ;
    layout4->addWidget(calendar);
    layout->addLayout(layout4, 1, 1, 1, 1);
    widget->setLayout(layout);

    //layout6->setSizeConstraint(QLayout::SetDefaultConstraint);

    QFont font4  = calendar->font();
    font4.setPointSize(12);
    font4.setBold(true);
    calendar->setFont(font4);


    widget->setLayout(layout);

    resize(520,520);
}

MainWindow::~MainWindow()
{
    delete ui;
}
