#ifndef CUBEWIDGET_H
#define CUBEWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QLineEdit>
#include <QString>
#include <QPaintEvent>
#include <QLatin1String>

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8MultiArray.h>
#include <sensor_msgs/Image.h>

#include <iostream>
#include <string.h>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

#include "hirop_msgs/taskInputCmd.h"

namespace Ui {
class cubeWidget;
}

class cubeWidget : public QWidget
{
    Q_OBJECT

public:

    explicit cubeWidget(QWidget *parent, ros::NodeHandle *node);

    ~cubeWidget();

protected:

     void paintEvent(QPaintEvent *event);

private:

    //ros节点指针
    ros::NodeHandle *Node;

    //ros发布端、订阅端、服务客户端
    ros::Subscriber color_serial_sub;
    ros::Subscriber cube_image_sub;
    ros::Publisher update_color_serial_pub;
    ros::ServiceClient hscfsm_task_client_;

    //界面窗口指针
    Ui::cubeWidget *ui;

    //显示图片label矢量
    std::vector<QLabel*> ImgLabels;

    //接收到的颜色序列
    QString color_serial;

    //接收到的颜色序列
    //std::vector<cv::Mat> Imgsvec;

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
    //void cubeImg_callback(const sensor_msgs::Image::ConstPtr& msg);

    /*
     * @brief: 切换状态机状态行为函数
     */
    int taskServerCmd(const std::string& behavior, const std::string& next_state, const std::vector<std::string>& params=std::vector<std::string>());

signals:

    /*
     * @brief: 显示颜色序列自定义信号
     */
    void displayCubeStr(QString);

    /*
     * @brief: 显示魔方图片自定义信号
     */
    void displayCubeImg();

private slots:

    /*
     * @brief: 采集魔方数据按钮槽函数
     */
    void slot_collectButton_clicked();

    /*
     * @brief: 魔方解算按钮槽函数
     */
    void slot_solveButton_clicked();

    /*
     * @brief: 执行解算按钮槽函数
     */
    void slot_excuteButton_clicked();

    /*
     * @brief: 全自动按钮槽函数
     */
    void slot_automaticButton_clicked();

    /*
     * @brief: 显示所识别颜色序列槽函数
     */
    void slot_colorSerialDisay(QString arg);

    /*
     * @brief: 显示所识别魔方图片槽函数
     */
    void slot_cubeImgDisay();

    void slot_prepareButton_clicked();

    void slot_placeCubeButton_clicked();

    void slot_resetButton_clicked();

};

#endif // CUBEWIDGET_H
