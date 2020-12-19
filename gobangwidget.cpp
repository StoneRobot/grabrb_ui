#include "gobangwidget.h"
#include "ui_gobangwidget.h"

gobangWidget::gobangWidget(QWidget *parent, ros::NodeHandle *node) :
    QWidget(parent), Node(node),
    ui(new Ui::gobangWidget)
{
    ui->setupUi(this);
    signalAndSlot();
    uiInit();
    RosInit();
}

gobangWidget::~gobangWidget()
{
    delete ui;
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
    connect(ui->FirstRoundBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_FirstRoundBox_currentIndexChanged(int)));
    connect(ui->ModeBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_ModeBox_currentIndexChanged(int)));
    connect(this, SIGNAL(displayPixmap()), this, SLOT(slot_RevPixmap()));

}

void gobangWidget::uiInit()
{
    //设定&初始化状态机各状态框
    ui->ModegroupBox->setStyleSheet("QGroupBox{ border-image: url(/home/fszb/photo/hhh.jpg); }");
    ui->State_Init->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->State_Run->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->State_Stop->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->State_Error->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");
    ui->State_Exit->setStyleSheet("QLabel{ background-color: rgb(192, 192, 192); }");

    move = new QMovie("/home/fszb/photo/work.gif");
    //ui->whiteBox->setMovie(move);
}


void gobangWidget::RosInit()
{
    control_pub = Node -> advertise<std_msgs::String>("/GobangGame/ControlSignal", 100);
    ChessBoardImg_sub = Node -> subscribe<sensor_msgs::Image>("/GobangVision/ChessBoardDetection", 1, &gobangWidget::ChessBoardImg_callback, this);

    isUpdate = false;
}


void gobangWidget::slot_RevPixmap()
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

    //开始后不能继续选择先手方，先手方只能在棋局开始之前设置
    ui->FirstRoundBox->setEnabled(false);
}


void gobangWidget::slot_StopButton_clicked()
{
    //发送暂停信号
    pub_control_signal("stop");

    //播放gif图
    ui->State_Stop->setMovie(move);
    move->start();
}

void gobangWidget::slot_ResumeButton_clicked()
{
    //发送继续信号
    pub_control_signal("resume");
}

void gobangWidget::slot_RestartButton_clicked()
{
    //发送重置信号
    pub_control_signal("end");

    //棋局重置后重新使能先手方选项
    ui->FirstRoundBox->setEnabled(true);
}

void gobangWidget::slot_ConfirmButtton_clicked()
{
    //发送确认信号
    pub_control_signal("confirm");

    move->stop();
}


void gobangWidget::slot_FirstRoundBox_currentIndexChanged(const int &arg1)
{
    //接收设置棋局先手方
    firstRound = ui->FirstRoundBox->currentText().toStdString().data();
    std::cout << "先手方设置为: " << firstRound << std::endl;

}

void gobangWidget::slot_ModeBox_currentIndexChanged(const int &arg1)
{
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
    std::cout << "模式转换为: " << mode << std::endl;
}






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
    //std::cout << "进入回调函数成功" << std::endl;
    const cv_bridge::CvImageConstPtr &ptr = cv_bridge::toCvShare(msg, "bgr8");
    live = ptr->image;
    cv::cvtColor(live, live, CV_BGR2RGB);
    //isUpdate = true;

    //触发自定义显示图片槽函数
    emit displayPixmap();

}



