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

    rosInit();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete gw;
    delete cw;
    delete dgw;
}

void MainWindow::rosInit()
{
    start_task_client_ = Node->serviceClient<hirop_msgs::startTaskCmd>("/startTaskAggreServer");
    left_robot_state_sub_ = Node->subscribe("/UR51/robot_status", 10, &MainWindow::leftRobotStateSubCB, this);
    right_robot_state_sub_ = Node->subscribe("/UR51/robot_status", 10, &MainWindow::rightRobotStateSubCB, this);
}

void MainWindow::leftRobotStateSubCB(const industrial_msgs::RobotModeConstPtr& msg)
{
//    if (msg->in_error.val == 0)
//    {

//    }
//    else
//    {

//    }
//    if (msg->drives_powered.val == 1)
//    {

//    }
//    else
//    {

//    }
}

void MainWindow::rightRobotStateSubCB(const industrial_msgs::RobotModeConstPtr& msg)
{
//    if (msg->in_error.val == 0)
//    {

//    }
//    else
//    {

//    }
//    if (msg->drives_powered.val == 1)
//    {

//    }
//    else
//    {

//    }
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
        sleep(3);
        ui->btn_tabmain_devConn->setEnabled(true);
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
       system("rosnode kill $(rosnode list | grep -v Gomoku_UI) &") ;
       sleep(5);
       system("rosrun hscfsm_bridge kill_all_node.sh");
       sleep(2);
       ui->btn_tabmain_sysReset->setEnabled(true);
    });
    t.detach();

}

void MainWindow::on_btn_tabmain_close_clicked()
{
    ui->btn_tabmain_close->setEnabled(false);
    this->close();
    ui->btn_tabmain_close->setEnabled(true);
}
