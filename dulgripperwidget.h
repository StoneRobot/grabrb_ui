#ifndef DULGRIPPERWIDGET_H
#define DULGRIPPERWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QLatin1String>


#include <iostream>

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

#include <std_srvs/Trigger.h>

#include "hirop_msgs/taskInputCmd.h"
#include "hirop_msgs/startTaskCmd.h"


namespace Ui {
class dulgripperWidget;
}


class dulgripperWidget : public QWidget
{
    Q_OBJECT

public:

    explicit dulgripperWidget(QWidget *parent, ros::NodeHandle *node);

    ~dulgripperWidget();

private:

    //ros节点指针
    ros::NodeHandle *Node;

    ros::Subscriber detectImgSub;

    ros::ServiceClient hscfsm_task_client_;
    ros::ServiceClient stop_pick_client_;
    ros::ServiceClient start_task_client_;

    //抓取设置参数
    std::string robot_ = "0";
    std::string pick_mode_ = "0";

    //界面窗口指针
    Ui::dulgripperWidget *ui;

    cv::Mat live;

signals:

    //自定义显示图片信号
    void displayPixmap();

private:

    /*
     * @brief: 绑定信号与槽函数
     */
    void signalAndSlot();

    /*
     * @brief: 控件初始化
     */
    void uiInit();

    /*
     * @brief: ros初始化
     */
    void rosInit();

    /*
     * @brief: 识别照片订阅回调函数
     */
    void detectImg_callback(const sensor_msgs::Image::ConstPtr &msg);

    int taskServerCmd(const std::string& behavior, const std::string& next_state, const std::vector<std::string>& params=std::vector<std::string>());


private slots:

    /*
     * @brief: 显示detection
     *
     * 照片槽函数
     */
    void slot_RevPixmap();

    /*
     * @brief: 准备按钮槽函数
     */
    void slot_prepareButton_clicked();

    /*
     * @brief: 抓取按钮槽函数
     */
    void slot_gripButton_clicked();

    /*
     * @brief: 停止按钮槽函数
     */
    void slot_stopButton_clicked();

    /*
     * @brief: 重置按钮槽函数
     */
    void slot_resetButton_clicked();

    /*
     * @brief: 机器人选择框槽函数
     */
    void slot_robotBox_currentIndexChanged(const int &arg1);

    /*
     * @brief: 抓取模式选择框槽函数
     */
    void slot_pickModeBox_currentIndexChanged(const int &arg1);

    void on_loadDulGripperFsm_clicked();
};

#endif // DULGRIPPERWIDGET_H
