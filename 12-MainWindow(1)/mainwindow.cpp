#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>


/*
 * QMainWindow:
 *     菜单条， 工具条， 状态栏， 主工作窗口
 * QWidget:
 *      所有窗口类的父类。
 * QDialog:
 *
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu *pm = new QMenu("Test");

//    QIcon icon("D:/qtpro/12-MainWindow/image/help.png");
    QIcon icon(":/img/image/zoom-in.png");   // 资源文件的路径":/前缀/资源文件路径"
    QAction *pa = new QAction(icon, "hahah", 0);
    pm->addAction(pa);
    connect(pa, SIGNAL(triggered()),
                  this, SLOT(close()));

    this->menuBar()->addMenu(pm);


    // 工具条
    ui->mainToolBar->addAction(pa);
    QToolBar *toolbar = new QToolBar("新的工具条", this);
    toolbar->addAction(pa);
    addToolBar(Qt::RightToolBarArea, toolbar);


    qDebug() << ui->statusBar;
    qDebug() << this->statusBar();

   // ui->statusBar->showMessage("我是哈哈哈哈哈", 5000);
    QLabel *label = new QLabel("我是label，我可以显示东西!");
    ui->statusBar->addWidget(label);


    // 中心窗口
    QLineEdit *lineEdit = new QLineEdit("aaaa");
    this->setCentralWidget(lineEdit);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    qDebug() << "Hi，我是菜单项 New";
}
