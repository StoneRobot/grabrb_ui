#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include <ros/ros.h>
#include <QDebug>
#include <thread>

#include "gobangwidget.h"
#include "cubewidget.h"
#include "dulgripperwidget.h"
#include "hirop_msgs/startTaskCmd.h"
#include "industrial_msgs/RobotStatus.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent, ros::NodeHandle *node);

    ~MainWindow();

private:
    void rosInit();

private slots:

    void on_btn_tabmain_loadFsm_clicked();

    void on_btn_tabmain_devConn_clicked();

    void on_btn_tabmain_runPrepare_clicked();

    void on_btn_tabmain_sysStop_clicked();

    void on_btn_tabmain_sysReset_clicked();

    void on_btn_tabmain_close_clicked();

private:
    void leftRobotStateSubCB(const industrial_msgs::RobotModeConstPtr& msg);
    void rightRobotStateSubCB(const industrial_msgs::RobotModeConstPtr& msg);

private:

    //ROS节点指针
    ros::NodeHandle *Node;

    ros::Subscriber left_robot_state_sub_;
    ros::Subscriber right_robot_state_sub_;


    ros::ServiceClient start_task_client_;

    //界面窗口指针
    Ui::MainWindow *ui;
    gobangWidget *gw;
    cubeWidget *cw;
    dulgripperWidget *dgw;



    
};

#endif // MAINWINDOW_H
