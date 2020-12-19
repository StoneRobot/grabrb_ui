#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include <ros/ros.h>

#include "gobangwidget.h"
#include "cubewidget.h"
#include "dulgripperwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent, ros::NodeHandle *node);

    ~MainWindow();

private slots:

private:

    //ROS节点指针
    ros::NodeHandle *Node;

    //界面窗口指针
    Ui::MainWindow *ui;
    gobangWidget *gw;
    cubeWidget *cw;
    dulgripperWidget *dgw;


    
};

#endif // MAINWINDOW_H
