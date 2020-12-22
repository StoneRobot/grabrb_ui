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

    connect(this, SIGNAL(display(QString)), this, SLOT(slot_colorSerialDisay(QString)));
}

void cubeWidget::uiInit()
{
    ui->cubeModeBox->setStyleSheet("QGroupBox{ border-image: url(/home/fshs/photo/cube.jpg); }");
    ui->RightImg_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/photo/unknown.jpg); }");
    ui->UpImg_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/photo/unknown.jpg); }");
    ui->DownImg_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/photo/unknown.jpg); }");
    ui->LeftImg_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/photo/unknown.jpg); }");
    ui->FrontImg_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/photo/unknown.jpg); }");
    ui->BackImg_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/photo/unknown.jpg); }");
}

void cubeWidget::rosInit()
{
    color_serial_sub = Node->subscribe <std_msgs::String>("/changeColor", 1, &cubeWidget::ColorSerial_callback, this);
    hscfsm_task_client_ = Node->serviceClient<hirop_msgs::taskInputCmd>("/VoiceCtlRob_TaskServerCmd");
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

void cubeWidget::ColorSerial_callback(const std_msgs::String::ConstPtr &msg)
{
    std::string result = msg->data.c_str();
    std::cout << "接收到的数据为: " << result << std::endl;

    //进行数据装换
    color_serial =QString::fromStdString(result);
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

void cubeWidget::slot_prepareButton_clicked()
{
    std::cout << "prepare" << std::endl;
    taskServerCmd("toHome", "prepare");
}

void cubeWidget::slot_placeCubeButton_clicked()
{
    std::cout << "place cube" << std::endl;
    std::cout << "place cube" << std::endl;
    taskServerCmd("place", "place cube");
}

void cubeWidget::slot_resetButton_clicked()
{
    std::cout << "reset button" << std::endl;
    taskServerCmd("reset", "reset");
}


