#include "gobangwidget.h"
#include "ui_gobangwidget.h"

gobangWidget::gobangWidget(QWidget *parent, ros::NodeHandle *node) :
    QWidget(parent), Node(node),
    ui(new Ui::gobangWidget)
{
    ui->setupUi(this);
    RosInit();
    signalAndSlot();
    uiInit();

}

gobangWidget::~gobangWidget()
{
    delete ui;
}

void gobangWidget::setFsmState(bool isOpen)
{
    fsm_open_ = isOpen;
    if(fsm_open_)
    {
        ui->StartButton->setEnabled(true);
    }
    else
    {
        ui->StartButton->setEnabled(false);
        for (size_t i = 0; i < stateLabels.size(); i++)
        {
            setLabelShow(stateLabels[i], "grey");
        }
    }
}

void gobangWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    //刷新棋局图片的大小
    ui->ChessBoardLabel->resize(ui->chessBoard_widget->size());
    ui->ChessBoardLabel->setScaledContents(true);
}


void gobangWidget::signalAndSlot()
{
    //绑定信号与槽
    connect(ui->StartButton, SIGNAL(clicked(bool)), this, SLOT(slot_StartButton_clicked()));
    connect(ui->StopButton, SIGNAL(clicked(bool)), this, SLOT(slot_StopButton_clicked()));
    connect(ui->ResumeButton, SIGNAL(clicked(bool)), this, SLOT(slot_ResumeButton_clicked()));
    connect(ui->RestartButton, SIGNAL(clicked(bool)), this, SLOT(slot_RestartButton_clicked()));
    connect(ui->ConfirmButton, SIGNAL(clicked(bool)), this, SLOT(slot_ConfirmButtton_clicked()));
    connect(ui->ChangeModeButton, SIGNAL(clicked(bool)), this, SLOT(slot_ChangeModeButton_clicked()));
    connect(ui->ResetButton, SIGNAL(clicked(bool)), this, SLOT(slot_ResetButton_clicker()));
    connect(ui->FirstRoundBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_FirstRoundBox_currentIndexChanged(int)));
    connect(ui->ModeBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_ModeBox_currentIndexChanged(int)));
    connect(this, SIGNAL(displayPixmap()), this, SLOT(slot_RevPixmap()));
}

void gobangWidget::uiInit()
{
    //设定&初始化状态机各状态框
    ui->ModegroupBox->setStyleSheet("QGroupBox{ border-image: url(/home/fshs/grabrb_ui/photo/hhh.jpg); }");
    ui->ChessBoardLabel->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/ChessDemo.png); }");

    ui->white_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/question.jpg); }");
    ui->black_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/question.jpg); }");

    //状态机向量&字典初始化
    std::vector<QLabel* >().swap(stateLabels);
    stateLabels.push_back(ui->State_Init);
    stateLabels.push_back(ui->State_Run);
    stateLabels.push_back(ui->State_Stop);
    stateLabels.push_back(ui->State_Error);
    stateLabels.push_back(ui->State_Exit);

    //设置状态颜色
    for (size_t i = 0; i < stateLabels.size(); i++)
    {
        setLabelShow(stateLabels[i], "grey");
    }
}


void gobangWidget::RosInit()
{
    control_pub = Node->advertise <std_msgs::String>("/GobangGame/ControlSignal", 100);
    state_sub = Node->subscribe <std_msgs::String>("/GobangGame/GameState", 1, &gobangWidget::stateSub_callback, this);
    attacker_sub = Node->subscribe <std_msgs::Int16>("/GobangGame/GameAttack", 1, &gobangWidget::attackerSub_callback, this);
    log_sub = Node->subscribe <std_msgs::String>("/GobangGame/GameLog", 1, &gobangWidget::logSub_callback, this);
    ChessBoardImg_sub = Node->subscribe <sensor_msgs::Image>("/GobangVision/ChessBoardDetection", 1, &gobangWidget::ChessBoardImg_callback, this);
    hscfsm_task_client = Node->serviceClient <hirop_msgs::taskInputCmd>("/VoiceCtlRob_TaskServerCmd");
}

/*----------------------------------------------------------------------------------------*/

void gobangWidget::slot_RevPixmap()
{
    //cv::Mat转QImage
    QImage qimage((uchar*)live.data, live.cols, live.rows, QImage::Format_RGB888);
    QPixmap tmp_pixmap = QPixmap::fromImage(qimage);
    //设置在对应label中显示
    ui->ChessBoardLabel->setPixmap(tmp_pixmap);

}


void gobangWidget::slot_StartButton_clicked()
{
    //如果没有选择模式则不开始棋局
    if (mode == "MODE")
    {
        QMessageBox::information(this, "Warn", QString::fromLocal8Bit("请先选择棋局模式"));
        return;
    }

    //打印出所选参数让玩家确认
    std::string param = "模式: " + mode + "; 先手方: " + firstRound;
    const char *p = param.c_str();
    QMessageBox::StandardButton result = QMessageBox::information(this, "Confirm", QString::fromLocal8Bit(p), QMessageBox::Yes|QMessageBox::No);
    switch (result)
    {
        case QMessageBox::Yes:
            qDebug()<<"Yes";
            break;
        case QMessageBox::No:
            qDebug()<<"No";
            return;
        default:
            break;
    }

    //更新模式显示
    refreshMode(mode);

    //设置五子棋状态机到run状态，开始对局
    std::vector<std::string> params = {mode, firstRound};
    if (taskServerCmd("start", "init", params) == -1)
    {
        QMessageBox::information(this, "Warn", QString::fromLocal8Bit("状态机开启失败，请检查是否正常开启"));
        return;
    }

    //开始后不能继续选择先手方，先手方只能在棋局开始之前设置
    //开始后需要进入暂停才能进行模式切换
    ui->FirstRoundBox->setEnabled(false);
    ui->ChangeModeButton->setEnabled(false);

    //防止多次点击开始，重置后才能再次点击开始
    ui->StartButton->setEnabled(false);
}


void gobangWidget::slot_StopButton_clicked()
{
    //发送暂停信号
    pub_control_signal("stop");

}

void gobangWidget::slot_ResumeButton_clicked()
{
    //发送继续信号
    pub_control_signal("resume");
}

void gobangWidget::slot_RestartButton_clicked()
{
    //发送结束棋局信号
    pub_control_signal("end");
}

void gobangWidget::slot_ConfirmButtton_clicked()
{
    //发送确认信号
    pub_control_signal("confirm");
}

void gobangWidget::slot_ResetButton_clicker()
{
    //重置状态机状态，exit to run，并重新置位棋局运行标志为
    taskServerCmd("restart", "exit");
    pub_control_signal("reset");

    //重新使能界面按钮
    ui->StartButton->setEnabled(true);
    ui->FirstRoundBox->setEnabled(true);
    ui->ChangeModeButton->setEnabled(true);

    setLabelShow(ui->whiteAttack_label, "grey");
    setLabelShow(ui->blackAttack_label, "grey");
}

void gobangWidget::slot_FirstRoundBox_currentIndexChanged(const int &arg1)
{
    Q_UNUSED(arg1);

    //接收设置棋局先手方
    firstRound = ui->FirstRoundBox->currentText().toStdString().data();
    std::cout << "先手方设置为: " << firstRound << std::endl;

}

void gobangWidget::slot_ModeBox_currentIndexChanged(const int &arg1)
{
    Q_UNUSED(arg1);

    //接收设置棋局模式
    mode = ui->ModeBox->currentText().toStdString().data();
    if (mode == "MODE")
    {
        QMessageBox::information(this, "Warn", QString::fromLocal8Bit("请正确选择模式"));
        return;
    }
    std::cout << "模式设置为: " << mode << std::endl;
}


void gobangWidget::slot_ChangeModeButton_clicked()
{
    if (mode == "MODE")
    {
        QMessageBox::information(this, "Warn", QString::fromLocal8Bit("请正确选择模式，重新切换"));
        return;
    }

    pub_control_signal(mode);
    refreshMode(mode);
    std::cout << "模式转换为: " << mode << std::endl;
}

void gobangWidget::refreshMode(std::string mode)
{
    if (mode == "MODE")
    {
        ui->white_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/question.jpg); }");
        ui->black_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/question.jpg); }");
        return;
    }

    else if (mode == "PVP")
    {
        ui->white_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/people.jpg); }");
        ui->black_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/people.jpg); }");
        return;
    }

    else if (mode == "RVR")
    {
        ui->white_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/robot.jpg); }");
        ui->black_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/robot.jpg); }");
        return;
    }

    else if (mode == "PVR")
    {
        ui->white_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/people.jpg); }");
        ui->black_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/robot.jpg); }");
        return;
    }

    else if (mode == "RVP")
    {
        ui->white_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/robot.jpg); }");
        ui->black_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/people.jpg); }");
        return;
    }
}

void gobangWidget::refreshState(std::string state)
{
    //清空状态数组
    std::memset(fsm_state, 0, sizeof(fsm_state));

    std::vector<std::string> s = {"init", "run", "stop", "error", "exit"};

    for (int i = 0; i < 5; i++)
    {
        if (state == s[i])
        {
            fsm_state[i] = 1;
            break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (fsm_state[i] == 1)
            setLabelShow(stateLabels[i], "yellow");
        else
            setLabelShow(stateLabels[i], "grey");
    }

    if (state == "stop")
    {
        //开启切换模式按钮
        ui->ChangeModeButton->setEnabled(true);
    }
}

void gobangWidget::refreshAttackSide(int attacker)
{
    if (attacker == 1)
    {
        setLabelShow(ui->whiteAttack_label, "red");
        setLabelShow(ui->blackAttack_label, "grey");
    }
    else if (attacker == -1)
    {
        setLabelShow(ui->whiteAttack_label, "grey");
        setLabelShow(ui->blackAttack_label, "red");
    }
}

void gobangWidget::showLog(std::string log)
{
    if (log == "humanA" || log == "humanB" || log == "robotA" || log == "robotB")
    {
        std::string word = log + "取得胜利";
        const char *p = word.c_str();
        QMessageBox::information(this, "Warn", QString::fromLocal8Bit(p));
        return;
    }

    else
    {
        const char *p = log.c_str();
        QMessageBox::information(this, "Warn", QString::fromLocal8Bit(p));
        return;
    }
}

void gobangWidget::setLabelShow(QLabel *label, std::string color)
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



/*----------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------*/


void gobangWidget::pub_control_signal(std::string order)
{
    std_msgs::String msg;
    std::stringstream ss;
    ss << order;
    msg.data = ss.str();
    control_pub.publish(msg);
}

void gobangWidget::ChessBoardImg_callback(const sensor_msgs::Image::ConstPtr &msg)
{
    std::cout << "进入回调函数成功" << std::endl;
    const cv_bridge::CvImageConstPtr &ptr = cv_bridge::toCvShare(msg, "bgr8");
    ptr->image.copyTo(live);
    cv::cvtColor(live, live, CV_BGR2RGB);

    //触发自定义显示图片槽函数
    emit displayPixmap();
}

void gobangWidget::stateSub_callback(const std_msgs::String::ConstPtr& msg)
{
    std::string result = msg->data.c_str();
    refreshState(result);
}

void gobangWidget::attackerSub_callback(const std_msgs::Int16::ConstPtr &msg)
{
    int result = msg->data;
    refreshAttackSide(result);
}

void gobangWidget::logSub_callback(const std_msgs::String::ConstPtr& msg)
{
    std::string result = msg->data.c_str();
    showLog(result);
}

int gobangWidget::taskServerCmd(const std::string &behavior, const std::string &next_state, const std::vector<std::string> &params)
{
    hirop_msgs::taskInputCmd task_srv;
    task_srv.request.behavior = behavior;
    task_srv.request.param = params;
    if(hscfsm_task_client.call(task_srv))
    {
        usleep(10000);
        if(task_srv.response.ret == 0)
        {
            std::cout << "进入" << next_state << "状态" << std::endl;
        }
        else
        {
            std::cout << "进入" << next_state << "状态失败" << std::endl;
        }
        return task_srv.response.ret;
    }
    else
    {
        std::cout << "调用" << next_state << "状态失败" << std::endl;
    }
    return -1;
}


/*----------------------------------------------------------------------------------------*/
