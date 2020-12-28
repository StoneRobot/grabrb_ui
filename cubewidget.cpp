#include "cubewidget.h"
#include "ui_cubewidget.h"

cubeWidget::cubeWidget(QWidget *parent, ros::NodeHandle *node) :
    QWidget(parent), Node(node),
    ui(new Ui::cubeWidget)
{
    ui->setupUi(this);

    signalAndSlot();
    uiInit();
    rosInit();
}

cubeWidget::~cubeWidget()
{
    delete ui;
}

void cubeWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    //刷新魔方显示图片label规格
    ui->RightImg_label->resize(ui->RightImg_widget->size());
    ui->UpImg_label->resize(ui->UpImg_widget->size());
    ui->DownImg_label->resize(ui->DownImg_widget->size());
    ui->LeftImg_label->resize(ui->LeftImg_widget->size());
    ui->FrontImg_label->resize(ui->FrontImg_widget->size());
    ui->BackImg_label->resize(ui->BackImg_widget->size());
}


void cubeWidget::signalAndSlot()
{
    //绑定信号与槽
    connect(ui->collectButton, SIGNAL(clicked(bool)), this, SLOT(slot_collectButton_clicked()));
    connect(ui->solveButton, SIGNAL(clicked(bool)), this, SLOT(slot_solveButton_clicked()));
    connect(ui->excuteButton, SIGNAL(clicked(bool)), this, SLOT(slot_excuteButton_clicked()));
    connect(ui->automaticButton, SIGNAL(clicked(bool)), this, SLOT(slot_automaticButton_clicked()));
    connect(ui->prepareButton, SIGNAL(clicked(bool)), this, SLOT(slot_prepareButton_clicked()));
    connect(ui->placeCubeButton, SIGNAL(clicked(bool)), this, SLOT(slot_placeCubeButton_clicked()));
    connect(ui->resetButton, SIGNAL(clicked(bool)), this, SLOT(slot_resetButton_clicked()));

    connect(this, SIGNAL(displayCubeStr(QString)), this, SLOT(slot_colorSerialDisay(QString)));
    connect(this, SIGNAL(displayCubeImg()), this, SLOT(slot_cubeImgDisay()));
}

void cubeWidget::uiInit()
{
    //魔方显示图片label初始化
    std::vector<QLabel*>().swap(ImgLabels);
    ImgLabels.push_back(ui->RightImg_label);
    ImgLabels.push_back(ui->UpImg_label);
    ImgLabels.push_back(ui->DownImg_label);
    ImgLabels.push_back(ui->LeftImg_label);
    ImgLabels.push_back(ui->FrontImg_label);
    ImgLabels.push_back(ui->BackImg_label);

    for (size_t i = 0; i < ImgLabels.size(); ++i)
    {
        ImgLabels[i]->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/unknown.jpg); }");
        ImgLabels[i]->setScaledContents(true);
    }

    ui->cubeModeBox->setStyleSheet("QGroupBox{ border-image: url(/home/fshs/grabrb_ui/photo/cube.jpg); }");
}



void cubeWidget::rosInit()
{
    color_serial_sub = Node->subscribe <std_msgs::String>("/changeColor", 1, &cubeWidget::colorSerial_callback, this);
//    cube_image_sub = Node->subscribe <sensor_msgs::Image>("/cube_image", 1, &cubeWidget::cubeImg_callback, this);
    hscfsm_task_client_ = Node->serviceClient<hirop_msgs::taskInputCmd>("/VoiceCtlRob_TaskServerCmd");
    stop_move_pub_ = Node->advertise<std_msgs::Bool>("/stop_move", 10);
}


void cubeWidget::setFsmState(bool isOpen)
{
    fsm_open_ = isOpen;
    if(fsm_open_)
    {
        ui->prepareButton->setEnabled(true);
    }
    else
    {
        ui->prepareButton->setEnabled(false);
    }
}

void cubeWidget::slot_collectButton_clicked()
{
    std::cout << "采集魔方数据中..." <<std::endl;
    taskServerCmd("photo", "take_photo");
}

void cubeWidget::slot_solveButton_clicked()
{
    std::cout << "解算魔方中..." << std::endl;
    taskServerCmd("request_data", "solve_data");
}

void cubeWidget::slot_excuteButton_clicked()
{
    std::cout << "还原魔方中..." << std::endl;
    taskServerCmd("solve", "execute");
}

void cubeWidget::slot_automaticButton_clicked()
{
    std::cout << "还原魔方中..." << std::endl;
    std::vector<std::string> parma={"1"};
    taskServerCmd("photo", "auto", parma);
}


void cubeWidget::slot_colorSerialDisay(QString arg)
{
    Q_UNUSED(arg);

    std::vector<QLineEdit *> Qline_list;
    std::vector<QLineEdit *>().swap(Qline_list);

    Qline_list.push_back(ui->RightlineEdit);
    Qline_list.push_back(ui->UplineEdit);
    Qline_list.push_back(ui->DownlineEdit);
    Qline_list.push_back(ui->LeftlineEdit);
    Qline_list.push_back(ui->FrontlineEdit);
    Qline_list.push_back(ui->BacklineEdit);

    for (int i = 0; i < 6; i++)
    {
        Qline_list[i]->setText(color_serial.mid(i * 9, 9));
    }

}

void cubeWidget::slot_cubeImgDisay()
{
//    for (size_t i = 0; i < Imgsvec.size(); i++)
//    {
//       QImage qimage((uchar*)Imgsvec[i].data, liImgsvec[i].cols, Imgsvec[i].rows, QImage::Format_RGB888);
//       QPixmap tem_pixmap = QPixmap::fromImage(qimage);
//       ImgLabels[i]->setPixmap(tem_pixmap);
//    }
}


void cubeWidget::slot_prepareButton_clicked()
{
    system("rosrun rubik_cube_solve set_robot_enable_true.sh");
    std::cout << "prepare" << std::endl;
    taskServerCmd("toHome", "prepare");
}

void cubeWidget::slot_placeCubeButton_clicked()
{
    ui->placeCubeButton->setEnabled(false);
    std::cout << "place cube" << std::endl;
    std::cout << "place cube" << std::endl;
    taskServerCmd("place", "place cube");
}

void cubeWidget::slot_resetButton_clicked()
{
    std::cout << "reset button" << std::endl;
    taskServerCmd("reset", "reset");
}





void cubeWidget::colorSerial_callback(const std_msgs::String::ConstPtr &msg)
{
    std::string result = msg->data.c_str();
    std::cout << "接收到的数据为: " << result << std::endl;

    //进行数据装换
    color_serial =QString::fromStdString(result);
}

//void cubeWidget::cubeImg_callback(const sensor_msgs::Image_::ConstPtr &msg)
//{
//    //接收最新的魔方检测照片
//    std::vector<cv::Mat>().swap(Imgsvec);
//    for (int i = 0; i < 6; i++)
//    {
//        const cv_bridge::CvImagePtr &ptr = cv_bridge::toCvCopy(msg.imagelist[i], "bgr8");
//        cv::Mat mat = ptr->image;
//        Imgsvec.push_back(mat);
//    }

//    //触发ui跟新显示信号
//    emit displayCubeImg();
//}


int cubeWidget::taskServerCmd(const std::string& behavior, const std::string& next_state, const std::vector<std::string>& params)
{
    hirop_msgs::taskInputCmd srv;
    srv.request.behavior = behavior;
    srv.request.param = params;
    if(hscfsm_task_client_.call(srv))
    {
        usleep(10000);
        if(srv.response.ret == 0)
        {
            std::cout << "进入" << next_state << "状态" << std::endl;
        }
        else
        {
            std::cout << "进入" << next_state << "状态失败" << std::endl;
        }
        return srv.response.ret;
    }
    else
    {
        std::cout << "调用" << next_state << "状态失败" << std::endl;
    }
    return -1;
}



void cubeWidget::on_stopMovePushButton_clicked()
{
    ui->stopMovePushButton->setEnabled(false);
    std_msgs::Bool msg;
    msg.data = true;
    stop_move_pub_.publish(msg);
    ui->stopMovePushButton->setEnabled(true);
}
