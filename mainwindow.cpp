#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, ros::NodeHandle *node) :
    QMainWindow(parent), Node(node),
    ui(new Ui::MainWindow)
{
    system("killall status_monitor_node");
    sleep(2);

    ui->setupUi(this);

    //添加gobangwidget子类窗口
    gw = new gobangWidget(this, Node);
    ui->tabWidget->addTab(gw, QString("五子棋"));

    //添加cubewidget子类窗口
    cw = new cubeWidget(this, Node);
    ui->tabWidget->addTab(cw, QString("魔方"));

    //添加dulgripperwidget子类窗口
    dgw = new dulgripperWidget(this, Node);
    ui->tabWidget->addTab(dgw, QString("智能抓取"));

    system("rosrun status_monitor status_monitor_node &");
    sleep(2);
    setFsmState(false, false, false);
    initMonitorLabel();
    uiInit();
    rosInit();
}

MainWindow::~MainWindow()
{
    monitor_timer_.stop();
    system("killall status_monitor_node");
//    system("kill -9 $(ps -ef | grep status_monitor | awk '{print $2}')");
    system("rosnode kill $(rosnode list | grep -v rosout) &") ;
    sleep(5);
    system("killall hscfsm_bridge");
//    system("kill -9 $(ps -ef | grep hscfsm | awk '{print $2}')");
    system("kill -9 $(ps -ef | grep rviz | awk '{print $2}')");
    system("rosrun status_monitor cleanup.sh &");
    sleep(2);
    delete ui;
    delete gw;
    delete cw;
    delete dgw;
}

void MainWindow::uiInit()
{
    ui->gomoku_icon_label->setStyleSheet("QLabel{ border-image: url(:/photosource/photo/gomoku_icon.jpg); }");
    ui->cube_icon_label->setStyleSheet("QLabel{ border-image: url(:/photosource/photo/cube_icon1.jpg); }");
    ui->grab_icon_label->setStyleSheet("QLabel{ border-image: url(:/photosource/photo/grab1.jpg); }");
    ui->btn_tabmain_loadFsm->setEnabled(false);

    //状态栏显示时间控件初始化
    time_label = new QLabel;
    ui->statusBar->addPermanentWidget(time_label);
    QTimer *timer = new QTimer;
    //每隔1s发送timeout信号更新时间
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(time_update()));
}

void MainWindow::rosInit()
{
    start_task_client_ = Node->serviceClient<hirop_msgs::startTaskCmd>("/startTaskAggreServer");
    control_gobang_client_ = Node->serviceClient<std_srvs::SetBool>("/control_gobang");
    control_gobang_pub_ = Node->advertise<std_msgs::Bool>("/control_gobang", 10);
    monitor_timer_ = Node->createTimer(ros::Duration(2), &MainWindow::monitorTimerCB, this);
    monitor_timer_.stop();
}

void MainWindow::monitorTimerCB(const ros::TimerEvent &event)
{
    Q_UNUSED(event);

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
    bool robot_enable[2];
    Node->getParam("/status/left_robot_power", robot_enable[0]);
    Node->getParam("/status/right_robot_power", robot_enable[1]);
    if(!robot_enable[0] && !robot_enable[1])
    {
        ui->btn_tabmain_sysStop->setText("上使能");
    }
    else
    {
        ui->btn_tabmain_sysStop->setText("紧急停止");
    }
}

void MainWindow::setLabel(QLabel* label, bool status)
{
    QPalette palette;
    if(status)
    {
        palette.setColor(QPalette::Background, QColor(0, 255, 0));
    }
    else if(!status)
    {
        palette.setColor(QPalette::Background, QColor(255, 0, 0));
    }
    label->setAutoFillBackground(true);  //一定要这句，否则不行
    label->setPalette(palette);
}

void MainWindow::rosReset()
{
//    std::vector<bool> isReset;
//    bool reset[2];
//    isReset.resize(2);
//    Node->getParam("/status/right_robot_connet", reset[0]);
//    Node->getParam("/status/left_robot_connet", reset[1]);
//    if(reset[0] && reset[1])
//    {
        system("rosnode kill $(rosnode list | grep -v Gomoku_UI | grep -v status_monitor | grep -v rosout) &") ;
        sleep(5);
        system("rosrun status_monitor cleanup.sh &");
        sleep(2);
//    }
}

void MainWindow::initMonitorLabel()
{

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
    std::thread t([&]{

    ui->btn_tabmain_loadFsm->setEnabled(false);
    hirop_msgs::startTaskCmd srv;
    srv.request.mode = false;
    std::string fsm = ui->cbox_tabmain_chooseMode->currentText().toUtf8().data();
    bool gobang = false;
    bool cube = false;
    bool dul = false;
    monitor_timer_.stop();
    system("rosnode kill /hscfsm_bridge");
    system("killall hscfsm_bridge");
    sleep(1);
    system("rosrun hscfsm_bridge hscfsm_bridge &");
    sleep(2);
    monitor_timer_.start();
    if(fsm == "五子棋")
    {
        srv.request.taskId = 3;
        load_gobang_ = true;
        system("rosservice call /camera_on_off 'data: true'");
        gobang = true;
    }
    else if(fsm == "拧魔方")
    {
        srv.request.taskId = 4;
        cube = true;
    }
    else if(fsm == "双臂抓取")
    {
        system("rosservice call /camera_on_off 'data: true'");
        srv.request.taskId = 5;
        dul = true;
    }
    else
    {
        ui->btn_tabmain_loadFsm->setEnabled(true);
        return;
    }

    if(!start_task_client_.call(srv))
    {
        system("rosnode kill /hscfsm_bridge");
        system("killall hscfsm_bridge");
        sleep(1);
        system("rosrun hscfsm_bridge hscfsm_bridge &");
        sleep(2);
        setFsmState(gobang, cube, dul);
        start_task_client_.call(srv);
    }
    else
    {
        std::cout << "设置" << fsm << ((srv.response.ret) ? "成功" : "失败") << std::endl;
        if(srv.response.ret)
        {
            setFsmState(gobang, cube, dul);
        }
        else
        {
            setFsmState(false, false, false);
        }
        sleep(3);
    }
    controlGobang(gobang);
    ui->btn_tabmain_loadFsm->setEnabled(true);
    });
    t.detach();

}

void MainWindow::controlGobang(bool gobang)
{
    if(load_gobang_)
    {
//        std_srvs::SetBool sr;
//        if(!gobang)
//        {
//            load_gobang_ = false;
//            sr.request.data = false;
//        }
//        else
//            sr.request.data = true;
//        control_gobang_client_.call(sr);

        std_msgs::Bool msg;
        if (!gobang)
        {
            load_gobang_ = false;
            msg.data = false;
        }
        else
            msg.data = true;
//        sleep(0.5);
        control_gobang_pub_.publish(msg);
    }
}


void MainWindow::setFsmState(bool gobang, bool cube, bool dulgripper)
{
    gw->setFsmState(gobang);
    cw->setFsmState(cube);
    dgw->setFsmState(dulgripper);
    setLabel(ui->gomoku_icon_text_label, gobang);
    setLabel(ui->cube_icon_text_label, cube);
    setLabel(ui->grab_icon_text_label, dulgripper);
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
    std::string text = ui->btn_tabmain_sysStop->text().toUtf8().data();
    if(text == "紧急停止")
        system("rosrun hscfsm_bridge set_robot_enable_false.sh");
    else
        system("rosrun hscfsm_bridge set_robot_enable_true.sh");
    ui->btn_tabmain_sysStop->setEnabled(true);
}

void MainWindow::on_btn_tabmain_sysReset_clicked()
{
    ui->btn_tabmain_sysReset->setEnabled(false);
    std::thread t([&]{
        setFsmState(false, false, false);
        rosReset();
//       system("rosnode kill $(rosnode list | grep -v Gomoku_UI | grep -v status_monitor | grep -v rosout) &") ;
//       sleep(5);
//       system("rosrun status_monitor cleanup.sh ");
//       sleep(2);
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

void MainWindow::time_update()
{
    //获取时间
    QDateTime current_time = QDateTime::currentDateTime();
    //设置显示的时间
    QString timestr = current_time.toString("yyyy年MM月dd日 hh:mm:ss");
    time_label->setText(timestr);
}

void MainWindow::on_cbox_tabmain_chooseMode_activated(const QString &arg1)
{
    std::string fsm = ui->cbox_tabmain_chooseMode->currentText().toUtf8().data();
    if(fsm == "请选择运行状态机")
    {
        ui->btn_tabmain_loadFsm->setEnabled(false);
    }
    else
    {
        ui->btn_tabmain_loadFsm->setEnabled(true);
    }
}
