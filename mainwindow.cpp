#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, ros::NodeHandle *node) :
    QMainWindow(parent), Node(node),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //添加gobangwidget子类窗口
    gw = new gobangWidget(this, Node);
    ui->tabWidget->addTab(gw, QString("GobangWar"));


    //添加cubewidget子类窗口
    cw = new cubeWidget(this, Node);
    ui->tabWidget->addTab(cw, QString("Cube"));

    //添加dulgripperwidget子类窗口
    dgw = new dulgripperWidget(this, Node);
    ui->tabWidget->addTab(dgw, QString("DualGripper"));
    initMonitorLabel();
    rosInit();
    uiInit();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete gw;
    delete cw;
    delete dgw;
}

void MainWindow::uiInit()
{
    ui->label_main_logo->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/hsicon1.jpg); }");
    ui->gomoku_icon_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/gomoku_icon.jpg); }");
    ui->cube_icon_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/cube_icon1.jpg); }");
    ui->grab_icon_label->setStyleSheet("QLabel{ border-image: url(/home/fshs/grabrb_ui/photo/grab1.jpg); }");
}

void MainWindow::rosInit()
{
    start_task_client_ = Node->serviceClient<hirop_msgs::startTaskCmd>("/startTaskAggreServer");
    monitor_timer_ = Node->createTimer(ros::Duration(1.1), &MainWindow::monitorTimerCB, this);
    monitor_timer_.stop();
}

void MainWindow::monitorTimerCB(const ros::TimerEvent &event)
{

    std::string prefix = "/status";
    std::string param_name;
    bool status;
    for(auto i: node_list)
    {
        param_name = prefix + i;
        Node->getParam(param_name, status);
        setLabel(map_node_label_[i], status);
    }
    for(auto j: topic_list)
    {
        param_name = prefix + j;
        Node->getParam(param_name, status);
        setLabel(map_topic_label_[j], status);
    }
}

void MainWindow::setLabel(QLabel* label, bool status)
{
    QPalette palette;
    if(status)
    {
        palette.setColor(QPalette::Background, QColor(0, 255, 0));
//        label->setStyleSheet("QLabel{background-color:rgb(0,255,0);}");
    }
    else if(!status)
    {
        palette.setColor(QPalette::Background, QColor(255, 0, 0));
//        label->setStyleSheet("QLabel{background-color:rgb(255,0,0);}");
    }
    label->setAutoFillBackground(true);  //一定要这句，否则不行
    label->setPalette(palette);
}

void MainWindow::initMonitorLabel()
{
//    Node->getParam("/status/node_list", node_list);
    node_list = {"/UR51/gripper_bridge", "/UR52/gripper_bridge", "/UR51/vision_bridge", "/UR52/vision_bridge",
                 "/pickplace_bridge0", "/pickplace_bridge1", "/dm_bridge", "/hscfsm_bridge", "/cube_bridge",
                 "/motion_bridge", "/perception_bridge"};
    map_node_label_[node_list[0]] = ui->label_tabmain_gripper_node_left;
    map_node_label_[node_list[1]] = ui->label_tabmain_gripper_node_right;
    map_node_label_[node_list[2]] = ui->label_tabmain_vision_bridge_left;
    map_node_label_[node_list[3]] = ui->label_tabmain_vision_bridge_right;
    map_node_label_[node_list[4]] = ui->label_tabmain_pickPlaceBridge_left;
    map_node_label_[node_list[5]] = ui->label_tabmain_pickPlaceBridge_right;
    map_node_label_[node_list[6]] = ui->label_tabmain_dmBridge;
    map_node_label_[node_list[7]] = ui->label_tabmain_hscfsm;
    map_node_label_[node_list[8]] = ui->label_tabmain_cube_bridge;
    map_node_label_[node_list[9]] = ui->label_tabmain_motionBridge;
    map_node_label_[node_list[10]] = ui->label_tabmain_perceptionBridge;

//    Node->getParam("/status/topic_list", topic_list);
    topic_list = {"/camera_base_left/color/camera_info", "/camera_base_right/color/camera_info", "/left_robot_connet",
                  "/left_robot_error", "/left_robot_power", "/right_robot_connet", "/right_robot_error", "/right_robot_power"};
    map_topic_label_[topic_list[0]] = ui->label_tabmain_d435i_left;
    map_topic_label_[topic_list[1]] = ui->label_tabmain_d435i_right;
    map_topic_label_[topic_list[2]] = ui->label_tabmain_rbConn_left;
    map_topic_label_[topic_list[3]] = ui->label_tabmain_rbIsWell_left;
    map_topic_label_[topic_list[4]] = ui->label_tabmain_rbEnable_left;
    map_topic_label_[topic_list[5]] = ui->label_tabmain_rbConn_right;
    map_topic_label_[topic_list[6]] = ui->label_tabmain_rbIsWell_right;
    map_topic_label_[topic_list[7]] = ui->label_tabmain_rbEnable_rihgt;
}


void MainWindow::on_btn_tabmain_loadFsm_clicked()
{
    ui->btn_tabmain_loadFsm->setEnabled(false);
    hirop_msgs::startTaskCmd srv;
    srv.request.mode = false;
    std::string fsm = ui->cbox_tabmain_chooseMode->currentText().toUtf8().data();
    if(fsm == "五子棋")
    {
        srv.request.taskId = 3;
    }
    else if(fsm == "拧魔方")
    {
        srv.request.taskId = 4;
    }
    else if(fsm == "双臂抓取")
    {
        srv.request.taskId = 5;
    }
    else
    {
        ui->btn_tabmain_loadFsm->setEnabled(true);
        return;

    }
    if(start_task_client_.call(srv))
    {
        std::cout << "设置" << fsm << ((srv.response.ret) ? "成功" : "失败") << std::endl;
    }
    else
    {
        std::cout << "调用状态机服务失败" << std::endl;
    }
    std::thread t([&]{
        sleep(3);
        ui->btn_tabmain_loadFsm->setEnabled(true);
    });
    t.detach();
}

void MainWindow::on_btn_tabmain_devConn_clicked()
{
    ui->btn_tabmain_devConn->setEnabled(false);
    std::thread t([&]{
        system("rosrun hscfsm_bridge bring_up_1.sh");
        if(!monitor_timer_.hasStarted())
        {
            monitor_timer_.start();
        }
    });
    t.detach();
}

void MainWindow::on_btn_tabmain_runPrepare_clicked()
{
    ui->btn_tabmain_runPrepare->setEnabled(false);
    std::thread t([&]{
        system("rosrun hscfsm_bridge bring_up_3.sh");
        ui->btn_tabmain_runPrepare->setEnabled(true);
    });
    t.detach();
}

void MainWindow::on_btn_tabmain_sysStop_clicked()
{
    ui->btn_tabmain_sysStop->setEnabled(false);
    system("rosrun hscfsm_bridge set_robot_enable_false.sh");
    ui->btn_tabmain_sysStop->setEnabled(true);
}

void MainWindow::on_btn_tabmain_sysReset_clicked()
{
    ui->btn_tabmain_sysReset->setEnabled(false);
    std::thread t([&]{
       system("rosnode kill $(rosnode list | grep -v Gomoku_UI | grep -v status_monitor) &") ;
       sleep(5);
       system("rosrun hscfsm_bridge kill_all_node.sh");
       sleep(2);
       ui->btn_tabmain_sysReset->setEnabled(true);
       ui->btn_tabmain_devConn->setEnabled(true);
    });
    t.detach();

}

void MainWindow::on_btn_tabmain_close_clicked()
{
    ui->btn_tabmain_close->setEnabled(false);
    this->close();
    ui->btn_tabmain_close->setEnabled(true);
}
