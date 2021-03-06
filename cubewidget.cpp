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
//    connect(ui->solveButton, SIGNAL(clicked(bool)), this, SLOT(slot_solveButton_clicked()));
//    connect(ui->excuteButton, SIGNAL(clicked(bool)), this, SLOT(slot_excuteButton_clicked()));
    connect(ui->automaticButton, SIGNAL(clicked(bool)), this, SLOT(slot_automaticButton_clicked()));
    connect(ui->prepareButton, SIGNAL(clicked(bool)), this, SLOT(slot_prepareButton_clicked()));
    connect(ui->placeCubeButton, SIGNAL(clicked(bool)), this, SLOT(slot_placeCubeButton_clicked()));
    connect(ui->resetButton, SIGNAL(clicked(bool)), this, SLOT(slot_resetButton_clicked()));

    connect(this, SIGNAL(displayCubeStr()), this, SLOT(slot_colorSerialDisay()));
    connect(this, SIGNAL(displayCubeImg()), this, SLOT(slot_cubeImgDisplay()));
    connect(this, SIGNAL(displayProgress()), this, SLOT(slot_solveProgressDisplay()));
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
        ImgLabels[i]->setStyleSheet("QLabel{ border-image: url(:/photosource/photo/unknown.jpg); }");
        ImgLabels[i]->setScaledContents(true);
    }

    std::vector<QLineEdit *>().swap(Qline_list);
    Qline_list.push_back(ui->RightlineEdit);
    Qline_list.push_back(ui->UplineEdit);
    Qline_list.push_back(ui->DownlineEdit);
    Qline_list.push_back(ui->LeftlineEdit);
    Qline_list.push_back(ui->FrontlineEdit);
    Qline_list.push_back(ui->BacklineEdit);

    setAllpushButtonOff();

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    ui->cubeModeBox->setStyleSheet("QGroupBox{ border-image: url(:/photosource/photo/cube.jpg); }");
}

void cubeWidget::rosInit()
{
    color_serial_sub = Node->subscribe <std_msgs::String>("/changeColor", 1, &cubeWidget::colorSerial_callback, this);
    solve_result_sub = Node->subscribe <std_msgs::Bool>("/solution_situation", 1, &cubeWidget::solveResult_callback, this);
    cube_image_sub = Node->subscribe <cube_bridge::rbImageList>("/cube_image", 1, &cubeWidget::cubeImg_callback, this);
    hscfsm_task_client_ = Node->serviceClient<hirop_msgs::taskInputCmd>("/VoiceCtlRob_TaskServerCmd");
    cube_correct_client = Node->serviceClient<cube_bridge::rb_string>("/cube_correct");
    camera_manager_client = Node->serviceClient<std_srvs::SetBool>("/camera_on_off");
    stop_move_pub_ = Node->advertise<std_msgs::Bool>("/stop_move", 10);
    cube_fsm_states_sub_ = Node->subscribe("/rubik_fsm_state", 10, &cubeWidget::cubeFsmStateSubCB, this);
    progress_rb_solve_magic_ = Node->subscribe("/progress_rbSolveMagic", 10, &cubeWidget::progressRbSolveMagicCB, this);
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
    std::string text = ui->collectButton->text().toUtf8().data();
    if(text == "采集魔方数据")
    {
        std::cout << "采集魔方数据中..." <<std::endl;
        taskServerCmd("photo", "take_photo");
    }
    else if(text == "魔方解算")
    {
        std::cout << "解算魔方中..." << std::endl;
        taskServerCmd("request_data", "solve_data");
    }
    else if(text == "执行解算")
    {
        std::cout << "还原魔方中..." << std::endl;
        taskServerCmd("solve", "execute");
    }

}

void cubeWidget::slot_automaticButton_clicked()
{
    std::cout << "还原魔方中..." << std::endl;
    std::vector<std::string> parma={"1"};
    taskServerCmd("photo", "auto", parma);
}

void cubeWidget::slot_colorSerialDisay()
{
    for (int i = 0; i < 6; i++)
    {
        Qline_list[i]->setText(color_serial.mid(i * 9, 9));
    }
}

void cubeWidget::slot_cubeImgDisplay()
{
    for (size_t i = 0; i < Imgsvec.size(); i++)
    {
       QImage qimage((const uchar*)Imgsvec[i].data, Imgsvec[i].cols, Imgsvec[i].rows, Imgsvec[i].step, QImage::Format_RGB888);
       QPixmap tem_pixmap = QPixmap::fromImage(qimage.rgbSwapped());
       ImgLabels[i]->setPixmap(tem_pixmap);
    }
}

void cubeWidget::slot_solveProgressDisplay()
{
    if(progress_data[2] != progress_data[0])
    {
        ui->progressBar->setMaximum(progress_data[0]);
        progress_data[2] = progress_data[0];
    }
    ui->progressBar->setValue(progress_data[1]);
}

void cubeWidget::solveResultQM(bool arg)
{
    QMessageBox* box = new QMessageBox;
    box->setAttribute(Qt::WA_DeleteOnClose);
    if(arg)
        QMessageBox::information(this, "Bingo", QString::fromLocal8Bit("魔方解算成功！"));
    else
        QMessageBox::information(this, "Error", QString::fromLocal8Bit("魔方解算失败，请修正魔方颜色序列！"));
    QTimer::singleShot(1, box, SLOT());
    box->exec();
}

void cubeWidget::slot_prepareButton_clicked()
{
    system("rosrun rubik_cube_solve set_robot_enable_true.sh");
    std::cout << "prepare" << std::endl;
    taskServerCmd("toHome", "prepare");
}

void cubeWidget::slot_placeCubeButton_clicked()
{
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
    color_serial = QString::fromStdString(result);
    emit displayCubeStr();
}

void cubeWidget::cubeImg_callback(const cube_bridge::rbImageList::ConstPtr &msg)
{
    //接收最新的魔方检测照片
    std::vector<cv::Mat>().swap(Imgsvec);
    for (int i = 0; i < 6; i++)
    {
        const cv_bridge::CvImagePtr &ptr = cv_bridge::toCvCopy(msg->imagelist[i], "bgr8");
        cv::Mat mat = ptr->image;
        Imgsvec.push_back(mat);
    }

    //触发ui更新显示信号
    emit displayCubeImg();
}

void cubeWidget::solveResult_callback(const std_msgs::BoolConstPtr &msg)
{

}


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

void cubeWidget::on_comboBox_cubeface_activated(const QString &arg1)
{
    std::string text = ui->comboBox_cubeface->currentText().toUtf8().data();
    std::string text2 = ui->comboBox_rotatoAngle->currentText().toUtf8().data();
    if(text == "选择魔方面" || text2 == "选择角度")
    {
        ui->pushButton_step->setEnabled(false);
    }
    else
    {
        ui->pushButton_step->setEnabled(true);
    }
}

void cubeWidget::cubeFsmStateSubCB(const std_msgs::StringConstPtr& msg)
{
    cube_fsm_state_ = msg->data;
    emit setFsmPushButton();
}

void cubeWidget::setFsmPushButton()
{
    setAllpushButtonOff();
    std::vector<QPushButton*> pb;
    if(cube_fsm_state_ == "init")
    {
        pb={ui->prepareButton};
    }
    if(cube_fsm_state_ == "home")
    {
        pb = {ui->collectButton, ui->automaticButton, ui->pushButton_intoStep};
        ui->collectButton->setText("采集魔方数据");
    }
    else if(cube_fsm_state_ == "photo")
    {
        std_srvs::SetBool srv;
        srv.request.data = true;
        camera_manager_client.call(srv);
        pb = {ui->collectButton, ui->placeCubeButton, ui->stopMovePushButton};
        ui->collectButton->setText("魔方解算");
    }
    else if(cube_fsm_state_ == "request_data")
    {
        std_srvs::SetBool srv;
        srv.request.data = false;
        camera_manager_client.call(srv);
        pb = {ui->collectButton, ui->placeCubeButton, ui->stopMovePushButton};
        ui->collectButton->setText("执行解算");
    }
    else if(cube_fsm_state_ =="solve")
    {
        pb = {ui->placeCubeButton, ui->stopMovePushButton};
    }
    else if(cube_fsm_state_ == "place")
    {
        pb = {ui->stopMovePushButton, ui->prepareButton};
    }
    else if(cube_fsm_state_ == "exit")
    {
        pb = {ui->resetButton};
    }
    else if(cube_fsm_state_ == "step")
    {
        pb = {ui->pushButton_exitStep, ui->pushButton_step};
    }
    for(auto i:pb)
    {
        i->setEnabled(true);
    }
}

void cubeWidget::progressRbSolveMagicCB(const std_msgs::Int8MultiArrayConstPtr& msg)
{
    if(msg->data.size()!=2)
        return;

    //清空数据并赋值
//    std::memset(progress_data, 0, sizeof(progress_data));

    for(int i =0; i<2; i++)
    {
        progress_data[i] = msg->data[i];
    }

    //触发更新显示进度信号
    emit displayProgress();
}

void cubeWidget::setAllpushButtonOff()
{
    std::vector<QPushButton*> pushButton_label={ui->prepareButton, ui->collectButton, ui->stopMovePushButton,
                                          ui->placeCubeButton, ui->automaticButton, ui->resetButton, ui->pushButton_intoStep,
                                          ui->pushButton_step, ui->pushButton_exitStep};
    for(auto i: pushButton_label)
    {
        i->setEnabled(false);
    }
}

void cubeWidget::on_comboBox_rotatoAngle_activated(const QString &arg1)
{
    std::string text = ui->comboBox_cubeface->currentText().toUtf8().data();
    std::string text2 = ui->comboBox_rotatoAngle->currentText().toUtf8().data();
    if(text == "选择魔方面" || text2 == "选择角度")
    {
        ui->pushButton_step->setEnabled(false);
    }
    else
    {
        ui->pushButton_step->setEnabled(true);
    }
}

void cubeWidget::on_pushButton_intoStep_clicked()
{
    std::cout << "toStep button" << std::endl;
    taskServerCmd("toStep", "Step");
}

void cubeWidget::on_pushButton_step_clicked()
{
    std::cout << "next button" << std::endl;
    std::vector<std::string> params;
    params.resize(2);
    int index = ui->comboBox_cubeface->currentIndex();
    std::stringstream ss;
    ss << index;
    ss >> params[0];
    params[1] = ui->comboBox_rotatoAngle->currentText().toUtf8().data();
    taskServerCmd("next", "next", params);
}

void cubeWidget::on_pushButton_exitStep_clicked()
{
    std::cout << "toHome button" << std::endl;
    taskServerCmd("toHome", "toHome");
}


void cubeWidget::on_resolveButton_clicked()
{
    //进行魔方重新结算
    std::string s = "";
    for (auto i : Qline_list)
        s += i->text().toUtf8().data();
    std::cout << "修改后的颜色序列为: " << s << std::endl;
    cube_bridge::rb_string correct_srv;
    correct_srv.request.a = s;
    if (!cube_correct_client.call(correct_srv))
        std::cout << "Failed to call service /cube_correct" << std::endl;
}
