#include "dulgripperwidget.h"
#include "ui_dulgripperwidget.h"



dulgripperWidget::dulgripperWidget(QWidget *parent, ros::NodeHandle *node) :
    QWidget(parent), Node(node),
    ui(new Ui::dulgripperWidget)
{
    ui->setupUi(this);

    signalAndSlot();
    uiInit();
    rosInit();
}

dulgripperWidget::~dulgripperWidget()
{
    delete ui;
}

void dulgripperWidget::signalAndSlot()
{
    //绑定信号与槽
//    connect(ui->loadDulGripperFsm, SIGNAL(clicked(bool)), this, SLOT(on_loadDulGripperFsm_clicked()));
    connect(ui->prepareButton, SIGNAL(clicked(bool)), this, SLOT(slot_prepareButton_clicked()));
    connect(ui->gripButton, SIGNAL(clicked(bool)), this,SLOT(slot_gripButton_clicked()));
    connect(ui->stopButton, SIGNAL(clicked(bool)), this, SLOT(slot_stopButton_clicked()));
    connect(ui->resetButton, SIGNAL(clicked(bool)), this, SLOT(slot_resetButton_clicked()));
    connect(ui->robotBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_robotBox_currentIndexChanged(int)));
    connect(ui->pickModeBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_pickModeBox_currentIndexChanged(int)));
    connect(this, SIGNAL(displayPixmap()), this, SLOT(slot_RevPixmap()));
}


void dulgripperWidget::uiInit()
{
    ui->griprParam_groupBox->setStyleSheet("QGroupBox{ border-image: url(/home/fshs/photo/jjj.png); }");
    ui->init_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->prepare_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->detection_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->pick_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->place_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->error_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->exit_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
}


void dulgripperWidget::rosInit()
{
    detectImgSub = Node->subscribe<sensor_msgs::Image>("/PreImage", 1, &dulgripperWidget::detectImg_callback, this);
    hscfsm_task_client_ = Node->serviceClient<hirop_msgs::taskInputCmd>("/VoiceCtlRob_TaskServerCmd");
    stop_pick_client_ = Node->serviceClient<std_srvs::Trigger>("stop_pick");
    start_task_client_ = Node->serviceClient<hirop_msgs::startTaskCmd>("/startTaskAggreServer");
}


void dulgripperWidget::slot_prepareButton_clicked()
{
    ui->prepareButton->setEnabled(false);
    std::cout << "準備" << std::endl;
    taskServerCmd("prepare", "prepare");
    usleep(1000*10);
    ui->prepareButton->setEnabled(true);
}

void dulgripperWidget::slot_gripButton_clicked()
{
    ui->gripButton->setEnabled(false);
    std::cout << "開始抓取" << std::endl;
    std::vector<std::string> params = {robot_, pick_mode_};
    taskServerCmd("starting", "detection", params);
    usleep(1000*10);
    ui->gripButton->setEnabled(true);
}

void dulgripperWidget::slot_stopButton_clicked()
{
    ui->stopButton->setEnabled(false);
    std::cout << "暫停" << std::endl;
    std_srvs::Trigger srv;
    if(stop_pick_client_.call(srv))
    {
        if(srv.response.success)
        {
            std::cout <<"stop motion success" << std::endl;
        }
        else
        {
            std::cout << "stop motion failed" << std::endl;
        }
    }
    else
    {
        std::cout << "call stop server failed" << std:: endl;
    }
    ui->stopButton->setEnabled(true);
}

void dulgripperWidget::slot_resetButton_clicked()
{
    ui->resetButton->setEnabled(false);
    std::cout << "重置" << std::endl;
    taskServerCmd("restart", "init");
    ui->resetButton->setEnabled(true);
}

void dulgripperWidget::slot_robotBox_currentIndexChanged(const int &arg1)
{
    std::string robot = ui->robotBox->currentText().toUtf8().data();
    std::cout << "选取机器人: " << robot  << std::endl;
    if(robot == "右边机器人")
    {
        robot_ = "1";
    }
    else
    {
        robot_ = "0";
    }
}

void dulgripperWidget::slot_pickModeBox_currentIndexChanged(const int &arg1)
{
    std::string pick_mode = ui->pickModeBox->currentText().toUtf8().data();
    std::cout << "抓取模式: " << pick_mode << std::endl;
    if(pick_mode == "桌子到货架")
    {
        pick_mode_ = "1";
    }
    else
    {
        pick_mode_ = "0";
    }
}


void dulgripperWidget::detectImg_callback(const sensor_msgs::Image::ConstPtr &msg)
{
    std::cout << "进入回调函数成功" << std::endl;

    //触发自定义显示图片槽函数
    const cv_bridge::CvImageConstPtr &ptr = cv_bridge::toCvShare(msg, "bgr8");
    live = ptr->image;
    cv::cvtColor(live, live, CV_BGR2RGB);
    if(robot_ == "1")
    {
//        //isUpdate = true;

//        //触发自定义显示图片槽函数
//        emit displayPixmap();
    }
    else
    {

    }

}

int dulgripperWidget::taskServerCmd(const std::string& behavior, const std::string& next_state, const std::vector<std::string>& params)
{
    hirop_msgs::taskInputCmd srv;
    srv.request.behavior = behavior;
    srv.request.param = params;
    if(hscfsm_task_client_.call(srv))
    {
        if(srv.response.ret == 0)
        {
            std::cout << "进入" << next_state << "状态" << std::endl;
        }
        else
        {
            std::cout << "进入" << next_state << "状态失败" << std::endl;
        }
        return srv.response.ret;
        usleep(1000*50);
    }
    else
    {
        std::cout << "调用" << next_state << "状态失败" << std::endl;
    }
    return -1;
}

void dulgripperWidget::slot_RevPixmap()
{
//    while(!isUpdate)
//    {
//        std::cout << "Waiting for update..." << std::endl;
//        sleep(1);
//    }
//    isUpdate = false;
    QImage qimage((uchar*)live.data, live.cols, live.rows, QImage::Format_RGB888);
    QPixmap tmp_pixmap = QPixmap::fromImage(qimage);
    tmp_pixmap = tmp_pixmap.scaled(this->width() * 3/4, this->height() * 2/3, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    ui->detectImg_label->setPixmap(tmp_pixmap);
}

void dulgripperWidget::on_loadDulGripperFsm_clicked()
{
    hirop_msgs::startTaskCmd srv;
    //srv.request.
    srv.request.taskId = 5;
    start_task_client_.call(srv);
}
