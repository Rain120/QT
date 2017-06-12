#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QDebug>

/*
 * 1.QMainWindow 有默认layout(QLayout),需要设置布局管理器，需要在它的中心窗口中添加。
 * 2.QWidget和QDialog没有默认layout。
 *
 * 3.只要是QWidget的派生类都可以添加layout。QWidget::setLayout().
 * 4.布局管理器可以通过addWidget()来添加窗口，还可以通过addLayout()来添加一个布局管器。
 *
 */


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *w = new QWidget;
    this->setCentralWidget(w);


    QHBoxLayout *hlayout = new QHBoxLayout;

    QRadioButton *r1 = new QRadioButton("aaaaa");
    QRadioButton *r2 = new QRadioButton("aaaaa");
    QRadioButton *r3 = new QRadioButton("aaaaa");
    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(r1);
    vlayout->addWidget(r2);
    vlayout->addWidget(r3);
    QGroupBox* g = new QGroupBox("radio", this);
    g->resize(100, 150);
    g->setLayout(vlayout);
    hlayout->addWidget(g);

    QCheckBox *c1 = new QCheckBox("bbbbbbbbbb");
    QCheckBox *c2 = new QCheckBox("bbbbbbbbbb");
    QCheckBox *c3 = new QCheckBox("bbbbbbbbbb");
    QVBoxLayout *v2 = new QVBoxLayout;
    v2->addWidget(c1);
    v2->addWidget(c2);
    v2->addWidget(c3);

    QGroupBox* g2 = new QGroupBox("checkbox", this);
    g2->resize(100, 150);
    g2->setLayout(v2);
    hlayout->addWidget(g2);

    w->setLayout(hlayout);

    qDebug() << g->children();


}

MainWindow::~MainWindow()
{
    delete ui;
}
