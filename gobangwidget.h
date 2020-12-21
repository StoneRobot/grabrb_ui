#ifndef GOBANGWIDGET_H
#define GOBANGWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QVariant>
#include <QDebug>
#include <QImage>
#include <QString>
#include <QPixmap>
#include <QMovie>

#include <iostream>
#include <string>
#include <fstream>
#include <atomic>

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Image.h>
#include <hirop_msgs/taskInputCmd.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

namespace Ui {
class gobangWidget;
}

class gobangWidget : public QWidget
{
    Q_OBJECT

public:
    explicit gobangWidget(QWidget *parent, ros::NodeHandle *node);

    ~gobangWidget();

private:

    //绑定信号与槽函数
    void signalAndSlot();

    //控件初始化
    void uiInit();

signals:

    //自定义显示图片信号
    void displayPixmap();


private slots:

    /*
     * @brief: 显示棋盘照片槽函数
     */
    void slot_RevPixmap();

    /*
     * @brief: 开始按钮槽函数
     */
    void slot_StartButton_clicked();

    /*
     * @brief: 暂停按钮槽函数
     */
    void slot_StopButton_clicked();

    /*
     * @brief: 继续按钮槽函数
     */
    void slot_ResumeButton_clicked();

    /*
     * @brief: 重置按钮槽函数
     */
    void slot_RestartButton_clicked();

    /*
     * @brief: 先手方组合框槽函数
     */
    void slot_FirstRoundBox_currentIndexChanged(const int &arg1);

    /*
     * @brief: 模式选择框槽函数
     */
    void slot_ModeBox_currentIndexChanged(const int &arg1);

    /*
     * @brief: 切换模式按钮槽函数
     */
    void slot_ChangeModeButton_clicked();

    /*
     * @brief: 确认模式按钮槽函数
     */
    void slot_ConfirmButtton_clicked();

private:

    //ros节点指针
    ros::NodeHandle *Node;

    //ros发布端、订阅端、服务客户端
    ros::Publisher control_pub;
    ros::Subscriber ChessBoardImg_sub;
    ros::ServiceClient hscfsm_task_client;

private:

    Ui::gobangWidget *ui;

    //棋局设置参数
    std::string mode = "MODE";
    std::string firstRound = "RANDOW";

    //棋盘最新照片
    cv::Mat live;

    //状态运行效果图
    QMovie *move;

    /*
     * @brief: ROS端初始化
     */
    void RosInit();

    /*
     * @brief: 发送棋局控制信号
     */
    void pub_control_signal(std::string order);

    /*
     * @brief: 棋盘最新识别照片话题回调函数
     */
    void ChessBoardImg_callback(const sensor_msgs::Image::ConstPtr &msg);

    /*
     * @brief: 状态机切换状态行为函数
     */
    int taskServerCmd(const std::string& behavior, const std::string& next_state,
                      const std::vector<std::string>& params=std::vector<std::string>());

};

#endif // GOBANGWIDGET_H
