#include "dialog.h"
#include "ui_dialog.h"
#include <QRadioButton>
#include <QCheckBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QGridLayout *hlayout = new QGridLayout;

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
    hlayout->addWidget(g, 0, 0, 1, 2);

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
    hlayout->addWidget(g2, 0, 2, 1, 1);

    QPushButton *pb1 = new QPushButton("ppppppppp");
    QPushButton *pb2 = new QPushButton("ppppppppp");
    QVBoxLayout *v3 = new QVBoxLayout;
    v3->addWidget(pb1);
    v3->addWidget(pb2);
    hlayout->addLayout(v3, 1, 0, 1, 1);

    this->setLayout(hlayout);



}

Dialog::~Dialog()
{
    delete ui;
}
