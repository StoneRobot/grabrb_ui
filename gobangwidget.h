#ifndef GOBANGWIDGET_H
#define GOBANGWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QVariant>
#include <QDebug>
#include <QPainter>
#include <QImage>
#include <QString>
#include <QPixmap>
#include <QMovie>

#include <iostream>
#include <string>
#include <fstream>
#include <atomic>
#include <map>
#include <vector>

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <sensor_msgs/Image.h>
#include <hirop_msgs/taskInputCmd.h>
#include <hirop_msgs/taskCmdRet.h>

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

protected:
    void paintEvent(QPaintEvent *event);

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
     * @brief: 刷新模式照片显示
     */
    void refreshMode(std::string mode);

    /*
     * @brief: 刷新攻击方显示
     */
    void refreshAttackSide(int attacker);

    /*
     * @brief: 刷新状态显示
     */
    void refreshState(std::string state);

    /*
     * @brief: 设置QLabel状态
     */
    void setLabelShow(QLabel* label, std::string color);



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
     * @brief: 重新开始棋局按钮槽函数
     */
    void slot_RestartButton_clicked();

    /*
     * @brief: 重置按钮槽函数
     */
    void slot_ResetButton_clicker();

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
    ros::Subscriber state_sub;
    ros::Subscriber attacker_sub;
    ros::Subscriber ChessBoardImg_sub;
    ros::ServiceClient hscfsm_task_client;

private:

    Ui::gobangWidget *ui;

    //棋局设置参数
    std::string mode = "MODE";
    std::string firstRound = "RANDOW";

    //棋盘最新照片
    cv::Mat live;

    //状态机状态数组
    int fsm_state[5];
    std::vector<QLabel* > stateLabels;

private:

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
     * @brief: 状态机状态订阅回调函数
     */
    void stateSub_callback(const std_msgs::String::ConstPtr& msg);

    /*
     * @brief: 当前棋局攻击方订阅回调函数
     */
    void attackerSub_callback(const std_msgs::Int16::ConstPtr& msg);

    /*
     * @brief: 状态机切换状态行为函数
     */
    int taskServerCmd(const std::string& behavior, const std::string& next_state,
                      const std::vector<std::string>& params=std::vector<std::string>());

};

#endif // GOBANGWIDGET_H
