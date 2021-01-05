#include "dulgripperwidget.h"
#include "ui_dulgripperwidget.h"



dulgripperWidget::dulgripperWidget(QWidget *parent, ros::NodeHandle *node) :
    QWidget(parent), Node(node),
    ui(new Ui::dulgripperWidget)
{
    ui->setupUi(this);
    connetTaskLabel();
    signalAndSlot();
    uiInit();
    rosInit();
}

dulgripperWidget::~dulgripperWidget()
{
    delete ui;
}

void dulgripperWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    //刷新显示检测图片label的尺寸
    ui->detectImg_label->resize(ui->detectImg_widget->size());
    ui->detectImg_label->setScaledContents(true);
}


void dulgripperWidget::signalAndSlot()
{
    //绑定信号与槽
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
   // ui->griprParam_groupBox->setStyleSheet("QGroupBox{ border-image: url(/home/fshs/grabrb_ui/photo/robots.jpg); }");
    ui->init_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->prepare_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->detection_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->pick_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->place_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->error_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->exit_label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");

    //live = cv::imread("/home/fshs/grabrb_ui/photo/grab.jpg", 1);
    //emit displayPixmap();
}


void dulgripperWidget::rosInit()
{
    detectImgSub_I = Node->subscribe<sensor_msgs::Image>("/UR51/preview_image", 1, &dulgripperWidget::detectImg_callback, this);
    detectImgSub_II = Node->subscribe<sensor_msgs::Image>("/UR52/preview_image", 1, &dulgripperWidget::detectImg_callback, this);
    hscfsm_task_client_ = Node->serviceClient<hirop_msgs::taskInputCmd>("/VoiceCtlRob_TaskServerCmd");
    stop_pick_client_ = Node->serviceClient<std_srvs::Trigger>("stop_pick");
    start_task_client_ = Node->serviceClient<hirop_msgs::startTaskCmd>("/startTaskAggreServer");
    fsm_task_sub_ = Node->subscribe("/fsm_state", 10, &dulgripperWidget::fsmTaskSubCB, this);
}

void dulgripperWidget::fsmTaskSubCB(const std_msgs::StringConstPtr& msg)
{
    for(auto i: fsm_task_)
    {
        setLabelShowdual(dul_label_[i], "grey");
    }
    std::cout << "status: >>>>>" << msg->data << std::endl;
    setLabelShowdual(dul_label_[msg->data], "yellow");
}

void dulgripperWidget::setFsmState(bool isOpen)
{
    fsm_open_ = isOpen;
    if(fsm_open_)
    {
        ui->prepareButton->setEnabled(true);
    }
    else
    {
        ui->prepareButton->setEnabled(false);
        for(auto i: fsm_task_)
        {
            setLabelShowdual(dul_label_[i], "grey");
        }
    }
}

void dulgripperWidget::connetTaskLabel()
{
    fsm_task_={"init", "prepare", "detection", "pick", "place", "error", "exit"};
    dul_label_[fsm_task_[0]] = ui->init_label;
    dul_label_[fsm_task_[1]] = ui->prepare_label;
    dul_label_[fsm_task_[2]] = ui->detection_label;
    dul_label_[fsm_task_[3]] = ui->pick_label;
    dul_label_[fsm_task_[4]] = ui->place_label;
    dul_label_[fsm_task_[5]] = ui->error_label;
    dul_label_[fsm_task_[6]] = ui->exit_label;
}

void dulgripperWidget::setLabelShowdual(QLabel *label, std::string color)
{
    if (color == "red")
    {
        label->setStyleSheet("QLabel{ background-color: rgb(255, 0, 0); }");
        return;
    }

    else if (color == "yellow")
    {
        label->setStyleSheet("QLabel{ background-color: rgb(255, 255, 0); }");
        return;
    }

    else if (color == "grey")
    {
        label->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
        return;
    }
}


void dulgripperWidget::slot_prepareButton_clicked()
{
    ui->prepareButton->setEnabled(false);
    std::cout << "準備" << std::endl;
    taskServerCmd("prepare", "prepare");
    ui->prepareButton->setEnabled(true);
}

void dulgripperWidget::slot_gripButton_clicked()
{
    ui->gripButton->setEnabled(false);
    std::cout << "開始抓取" << std::endl;
    std::vector<std::string> params = {robot_, pick_mode_};
    taskServerCmd("starting", "detection", params);
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
    taskServerCmd("reset", "init");
    ui->resetButton->setEnabled(true);
}

void dulgripperWidget::slot_robotBox_currentIndexChanged(const int &arg1)
{
    Q_UNUSED(arg1);

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
    Q_UNUSED(arg1);

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

void dulgripperWidget::slot_RevPixmap()
{
    //cv::Mat转QImage
    QImage qimage((const uchar*)live.data, live.cols, live.rows, live.step, QImage::Format_RGB888);
    QPixmap tmp_pixmap;
    tmp_pixmap = QPixmap::fromImage(qimage);
    ui->detectImg_label->setPixmap(tmp_pixmap);
}

void dulgripperWidget::detectImg_callback(const sensor_msgs::Image::ConstPtr &msg)
{
    //触发自定义显示图片槽函数
    const cv_bridge::CvImageConstPtr &ptr = cv_bridge::toCvShare(msg, "bgr8");
    ptr->image.copyTo(live);
    cv::cvtColor(live, live, CV_BGR2RGB);

    //触发显示图片信号
    emit displayPixmap();
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
