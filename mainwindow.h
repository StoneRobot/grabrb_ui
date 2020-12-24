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
    void uiInit();
    void rosInit();
    void initMonitorLabel();
    void monitorTimerCB(const ros::TimerEvent& event);
    void setLabel(QLabel* label, bool status);

private slots:

    void on_btn_tabmain_loadFsm_clicked();

    void on_btn_tabmain_devConn_clicked();

    void on_btn_tabmain_runPrepare_clicked();

    void on_btn_tabmain_sysStop_clicked();

    void on_btn_tabmain_sysReset_clicked();

    void on_btn_tabmain_close_clicked();

private:

    //ROS节点指针
    ros::NodeHandle *Node;

    ros::ServiceClient start_task_client_;
    ros::Timer monitor_timer_;

    std::vector<std::string> node_list;
    std::vector<std::string> topic_list;
    std::map<std::string, QLabel*> map_node_label_;
    std::map<std::string, QLabel*> map_topic_label_;


    //界面窗口指针
    Ui::MainWindow *ui;
    gobangWidget *gw;
    cubeWidget *cw;
    dulgripperWidget *dgw;



    
};

#endif // MAINWINDOW_H
