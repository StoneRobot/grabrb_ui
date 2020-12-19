#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, ros::NodeHandle *node) :
    QMainWindow(parent), Node(node),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //添加gobangwidget子类窗口
    gw = new gobangWidget(this, Node);
    ui->tabWidget->addTab(gw, QString("GobangWar"));


    //添加cubewidget子类窗口
    cw = new cubeWidget(this, Node);
    ui->tabWidget->addTab(cw, QString("Cube"));

    //添加dulgripperwidget子类窗口
    dgw = new dulgripperWidget(this, Node);
    ui->tabWidget->addTab(dgw, QString("DualGripper"));

}


MainWindow::~MainWindow()
{
    delete ui;
    delete gw;
    delete cw;
    delete dgw;
}
