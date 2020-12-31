#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QString>
#include <QLabel>
#include <QDateTime>


#include <ros/ros.h>
#include <QDebug>
#include <thread>
#include <std_srvs/SetBool.h>
#include <std_msgs/Bool.h>

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
    void setFsmState(bool gobang, bool cube, bool dulgripper);
    void controlGobang(bool gobang);
    void rosReset();

private slots:

    void on_btn_tabmain_loadFsm_clicked();

    void on_btn_tabmain_devConn_clicked();

    void on_btn_tabmain_runPrepare_clicked();

    void on_btn_tabmain_sysStop_clicked();

    void on_btn_tabmain_sysReset_clicked();

    void on_btn_tabmain_close_clicked();

    void time_update();
    void on_cbox_tabmain_chooseMode_activated(const QString &arg1);

private:

    //ROS节点指针
    ros::NodeHandle *Node;

    ros::ServiceClient start_task_client_;
    ros::ServiceClient control_gobang_client_;
    ros::Publisher control_gobang_pub_;
    ros::Timer monitor_timer_;

    bool load_gobang_ = false;

    std::vector<std::string> node_list;
    std::vector<std::string> topic_list;
    std::map<std::string, QLabel*> map_node_label_;
    std::map<std::string, QLabel*> map_topic_label_;


    //界面窗口指针
    Ui::MainWindow *ui;
    gobangWidget *gw;
    cubeWidget *cw;
    dulgripperWidget *dgw;

    QLabel *time_label;



    
};

#endif // MAINWINDOW_H
