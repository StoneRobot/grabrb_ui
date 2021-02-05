#ifndef CUBEWIDGET_H
#define CUBEWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QLineEdit>
#include <QString>
#include <QPaintEvent>
#include <QTimer>
#include <QLatin1String>

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8MultiArray.h>
#include <std_msgs/Int8MultiArray.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/Bool.h>
#include <std_srvs/SetBool.h>

#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

#include "hirop_msgs/taskInputCmd.h"
#include "cube_bridge/rbImageList.h"
#include "cube_bridge/rb_string.h"

namespace Ui {
class cubeWidget;
}

class cubeWidget : public QWidget
{
    Q_OBJECT

public:

    explicit cubeWidget(QWidget *parent, ros::NodeHandle *node);

    ~cubeWidget();

    void setFsmState(bool isOpen);
protected:

     void paintEvent(QPaintEvent *event);

private:

    //ros节点指针
    ros::NodeHandle *Node;

    //ros发布端、订阅端、服务客户端
    ros::Subscriber color_serial_sub;
    ros::Subscriber cube_image_sub;
    ros::Subscriber cube_fsm_states_sub_;
    ros::Subscriber progress_rb_solve_magic_;
    ros::Subscriber solve_result_sub;
    ros::Publisher update_color_serial_pub;
    ros::Publisher stop_move_pub_;
    ros::ServiceClient hscfsm_task_client_;
    ros::ServiceClient cube_correct_client;

    ros::ServiceClient camera_manager_client;

    //魔方状态机开启状态标志位
    bool fsm_open_;

    //界面窗口指针
    Ui::cubeWidget *ui;

    //显示图片label矢量
    std::vector<QLabel*> ImgLabels;

    //显示颜色序列QlineEdit矢量
    std::vector<QLineEdit *> Qline_list;

    //接收到的颜色序列
    QString color_serial;

    //接收到的识别图片序列
    std::vector<cv::Mat> Imgsvec;

    //解魔方进度数据
    int progress_data[3];

    std::string cube_fsm_state_;

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
     * @brief: 接收魔方识别颜色序列话题回调函数
     */
    void colorSerial_callback(const std_msgs::String::ConstPtr& msg);

    /*
     * @brief: 接收魔方识别图片话题回调函数
     */
    void cubeImg_callback(const cube_bridge::rbImageList::ConstPtr& msg);

    /*
     * @brief: 接收魔方解算是否成功话题回调函数
     */
    void solveResult_callback(const std_msgs::BoolConstPtr& msg);

    /*
     * @brief: 切换状态机状态行为函数
     */
    int taskServerCmd(const std::string& behavior, const std::string& next_state, const std::vector<std::string>& params=std::vector<std::string>());

    /*
     * @brief: 魔方状态机状态订阅回调函数
     */
    void cubeFsmStateSubCB(const std_msgs::StringConstPtr& msg);

    /*
     * @brief: 解魔方进度回调函数
     */
    void progressRbSolveMagicCB(const std_msgs::Int8MultiArrayConstPtr& msg);

    /*
     * @brief: 封锁所有按钮函数
     */
    void setAllpushButtonOff();

    /*
     * @brief: UI提示魔方解算是否成功函数
     */
    void solveResultQM(bool arg);

    void setFsmPushButton();

signals:

    /*
     * @brief: 显示颜色序列自定义信号
     */
    void displayCubeStr();

    /*
     * @brief: 显示魔方图片自定义信号
     */
    void displayCubeImg();

    /*
     * @brief: 显示进度自定义信号
     */
    void displayProgress();


private slots:

    /*
     * @brief: 采集魔方数据按钮槽函数
     */
    void slot_collectButton_clicked();

    /*
     * @brief: 魔方解算按钮槽函数
     */
//    void slot_solveButton_clicked();

    /*
     * @brief: 执行解算按钮槽函数
     */
//    void slot_excuteButton_clicked();

    /*
     * @brief: 全自动按钮槽函数
     */
    void slot_automaticButton_clicked();

    /*
     * @brief: 显示所识别颜色序列槽函数
     */
    void slot_colorSerialDisay();

    /*
     * @brief: 显示所识别魔方图片槽函数
     */
    void slot_cubeImgDisplay();

    /*
     * @brief: 显示解魔方进度槽函数
     */
    void slot_solveProgressDisplay();

    /*
     * @brief: 准备按钮槽函数
     */
    void slot_prepareButton_clicked();

    /*
     * @brief: 放下魔方按钮按钮槽函数
     */
    void slot_placeCubeButton_clicked();

    /*
     * @brief: 重置按钮槽函数
     */
    void slot_resetButton_clicked();

    /*
     * @brief: 停止按钮槽函数
     */
    void on_stopMovePushButton_clicked();

    /*
     * @brief: 选择魔方面组合框槽函数
     */
    void on_comboBox_cubeface_activated(const QString &arg1);

    /*
     * @brief: 选择角度组合框槽函数
     */
    void on_comboBox_rotatoAngle_activated(const QString &arg1);

    /*
     * @brief: 进入单步动作按钮槽函数
     */
    void on_pushButton_intoStep_clicked();


    void on_pushButton_step_clicked();

    /*
     * @brief: 退出单步状态按钮槽函数
     */
    void on_pushButton_exitStep_clicked();

    /*
     * @brief: step按钮槽函数
     */
    void on_resolveButton_clicked();
};

#endif // CUBEWIDGET_H
