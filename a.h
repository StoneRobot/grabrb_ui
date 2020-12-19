/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef A_H
#define A_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *vLayout_main;
    QHBoxLayout *hLayout_main_11;
    QLabel *label_main_logo;
    QLabel *label_main_title;
    QHBoxLayout *hLayout_main_12;
    QTabWidget *tabWidget;
    QWidget *tab_main;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *vLayout_tabmain_1;
    QHBoxLayout *hLayout_tabmain_11;
    QGroupBox *gBox_tabmain_status;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gLayout_tabmain_status;
    QLabel *label_tabmain_motionBridge;
    QLabel *label_tabmain_perceptionBridge;
    QLabel *label_tabmain_rbConn;
    QLabel *label_tabmain_rbIsWell;
    QLabel *label_tabmain_rbEnable;
    QLabel *label_tabmain_plannerBridge;
    QLabel *label_tabmain_dmBridge;
    QLabel *label_tabmain_gripperConn;
    QLabel *label_tabmain_voiceNode;
    QLabel *label_tabmain_d435iConn;
    QLabel *label_tabmain_kinect2Conn;
    QLabel *label_tabmain_visionBridge;
    QLabel *label_tabmain_senceFinish;
    QLabel *label_tabmain_pickPlaceBridge;
    QLabel *label_tabmain_uiNode;
    QHBoxLayout *hLayout_tabmain_21;
    QGroupBox *gBox_tabmain_mode;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *cbox_tabmain_chooseMode;
    QHBoxLayout *hLayout_tabmain_31;
    QGroupBox *gBox_tabmain_func;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btn_tabmain_devConn;
    QPushButton *btn_tabmain_runPrepare;
    QPushButton *btn_tabmain_sysStop;
    QPushButton *btn_tabmain_sysReset;
    QWidget *tab_autoMode;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *hLayout_tab_autoMode_1;
    QVBoxLayout *vLayout_tab_autoMode_11;
    QGroupBox *gBox_tab_autoMode_img;
    QHBoxLayout *horizontalLayout_15;
    QLabel *labeltab_autoMode_image;
    QVBoxLayout *vLayout_tab_autoMode_12;
    QGroupBox *gBox_tab_autoMode_fsm;
    QHBoxLayout *horizontalLayout_17;
    QGridLayout *gLayout_tab_autoMode_fsm;
    QLabel *label_tab_autoMode_grab;
    QLabel *label_tab_autoMode_updatePCL;
    QLabel *label_tab_autoMode_detect;
    QLabel *label_tab_autoMode_prepare;
    QLabel *label_tab_autoMode_init;
    QLabel *label_tab_autoMode_exit;
    QLabel *label_tab_autoMode_err;
    QLabel *label_tab_autoMode_place;
    QGroupBox *gBox_tab_autoMode_mode;
    QVBoxLayout *verticalLayout;
    QComboBox *cBox_tab_autoMode_mode;
    QComboBox *cBox_tab_autoMode_boxmodel;
    QGroupBox *gBox_tab_autoMode_operate;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *hLayout_tab_autoMode_123;
    QPushButton *btn_tab_autoMode_run;
    QPushButton *btn_tab_autoMode_normalstop;
    QPushButton *btn_tab_autoMode_quickstop;
    QWidget *tab_stepMode;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *hLayout_tab_stepMode_1;
    QVBoxLayout *vLayout_tab_stepMode_12;
    QGroupBox *gBox_tab_stepMode_showImg;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_tab_stepMode_showImg;
    QVBoxLayout *vLayout_tab_stepMode_11;
    QGroupBox *gBox_tab_stepMode_status;
    QHBoxLayout *horizontalLayout_11;
    QGridLayout *gLayout_tab_stepMode;
    QLabel *label_tab_stepMode_pickPlaceBridge;
    QLabel *label_tab_stepMode_senceFinish;
    QLabel *label_tab_stepMode_rd435iConn;
    QLabel *label_tab_stepMode_rbIsWell;
    QLabel *label_tab_stepMode_rbEnable;
    QLabel *label_tab_stepMode_gripperConn;
    QLabel *label_tab_stepMode_plannerBridge;
    QLabel *label_tab_stepMode_motionBridge;
    QLabel *label_tab_stepMode_perceptionBridge;
    QLabel *label_tab_stepMode_dmBridge;
    QGroupBox *gBox_tab_stepMode_operate;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *btn_tab_stepMode_goPhotoPose;
    QPushButton *btn_tab_stepMode_detectAndGrab;
    QPushButton *btn_tab_stepMode_goHomePose;
    QPushButton *btn_tab_stepMode_Estop;
    QWidget *tab_debug;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_tabdebug_1;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *btn_rbSetEnable;
    QPushButton *btn_rbReset;
    QGroupBox *groupBox_tabdebug_2;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *btn_gripper_open;
    QPushButton *btn_gripper_close;
    QGroupBox *groupBox_tabdebug_3;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *btn_rbGoHomePose;
    QWidget *tab_recorder;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *vLayout_tab_recorder_1;
    QVBoxLayout *vLayout_tab_recorder_11;
    QPlainTextEdit *plainText_tabrecorder;
    QVBoxLayout *vLayout_tab_recorder_2;
    QPushButton *btn_tab_recoder_ouputRecorder;
    QPushButton *btn_tab_recoder_clearRecorder;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(877, 699);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        vLayout_main = new QVBoxLayout();
        vLayout_main->setSpacing(6);
        vLayout_main->setObjectName(QString::fromUtf8("vLayout_main"));
        hLayout_main_11 = new QHBoxLayout();
        hLayout_main_11->setSpacing(6);
        hLayout_main_11->setObjectName(QString::fromUtf8("hLayout_main_11"));
        label_main_logo = new QLabel(centralWidget);
        label_main_logo->setObjectName(QString::fromUtf8("label_main_logo"));
        label_main_logo->setPixmap(QPixmap(QString::fromUtf8("../../../../../catkin_ws/src/HS_HandGrasp/handrb_ui/photo/logo.png")));

        hLayout_main_11->addWidget(label_main_logo);

        label_main_title = new QLabel(centralWidget);
        label_main_title->setObjectName(QString::fromUtf8("label_main_title"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label_main_title->setFont(font);
        label_main_title->setAlignment(Qt::AlignCenter);

        hLayout_main_11->addWidget(label_main_title);

        hLayout_main_11->setStretch(1, 6);

        vLayout_main->addLayout(hLayout_main_11);

        hLayout_main_12 = new QHBoxLayout();
        hLayout_main_12->setSpacing(6);
        hLayout_main_12->setObjectName(QString::fromUtf8("hLayout_main_12"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_main = new QWidget();
        tab_main->setObjectName(QString::fromUtf8("tab_main"));
        verticalLayout_2 = new QVBoxLayout(tab_main);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        vLayout_tabmain_1 = new QVBoxLayout();
        vLayout_tabmain_1->setSpacing(6);
        vLayout_tabmain_1->setObjectName(QString::fromUtf8("vLayout_tabmain_1"));
        hLayout_tabmain_11 = new QHBoxLayout();
        hLayout_tabmain_11->setSpacing(6);
        hLayout_tabmain_11->setObjectName(QString::fromUtf8("hLayout_tabmain_11"));
        gBox_tabmain_status = new QGroupBox(tab_main);
        gBox_tabmain_status->setObjectName(QString::fromUtf8("gBox_tabmain_status"));
        gBox_tabmain_status->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(gBox_tabmain_status);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gLayout_tabmain_status = new QGridLayout();
        gLayout_tabmain_status->setSpacing(6);
        gLayout_tabmain_status->setObjectName(QString::fromUtf8("gLayout_tabmain_status"));
        label_tabmain_motionBridge = new QLabel(gBox_tabmain_status);
        label_tabmain_motionBridge->setObjectName(QString::fromUtf8("label_tabmain_motionBridge"));

        gLayout_tabmain_status->addWidget(label_tabmain_motionBridge, 3, 3, 1, 1);

        label_tabmain_perceptionBridge = new QLabel(gBox_tabmain_status);
        label_tabmain_perceptionBridge->setObjectName(QString::fromUtf8("label_tabmain_perceptionBridge"));

        gLayout_tabmain_status->addWidget(label_tabmain_perceptionBridge, 3, 4, 1, 1);

        label_tabmain_rbConn = new QLabel(gBox_tabmain_status);
        label_tabmain_rbConn->setObjectName(QString::fromUtf8("label_tabmain_rbConn"));

        gLayout_tabmain_status->addWidget(label_tabmain_rbConn, 0, 0, 1, 1);

        label_tabmain_rbIsWell = new QLabel(gBox_tabmain_status);
        label_tabmain_rbIsWell->setObjectName(QString::fromUtf8("label_tabmain_rbIsWell"));

        gLayout_tabmain_status->addWidget(label_tabmain_rbIsWell, 0, 1, 1, 1);

        label_tabmain_rbEnable = new QLabel(gBox_tabmain_status);
        label_tabmain_rbEnable->setObjectName(QString::fromUtf8("label_tabmain_rbEnable"));

        gLayout_tabmain_status->addWidget(label_tabmain_rbEnable, 0, 2, 1, 1);

        label_tabmain_plannerBridge = new QLabel(gBox_tabmain_status);
        label_tabmain_plannerBridge->setObjectName(QString::fromUtf8("label_tabmain_plannerBridge"));

        gLayout_tabmain_status->addWidget(label_tabmain_plannerBridge, 3, 2, 1, 1);

        label_tabmain_dmBridge = new QLabel(gBox_tabmain_status);
        label_tabmain_dmBridge->setObjectName(QString::fromUtf8("label_tabmain_dmBridge"));

        gLayout_tabmain_status->addWidget(label_tabmain_dmBridge, 3, 1, 1, 1);

        label_tabmain_gripperConn = new QLabel(gBox_tabmain_status);
        label_tabmain_gripperConn->setObjectName(QString::fromUtf8("label_tabmain_gripperConn"));

        gLayout_tabmain_status->addWidget(label_tabmain_gripperConn, 0, 3, 1, 1);

        label_tabmain_voiceNode = new QLabel(gBox_tabmain_status);
        label_tabmain_voiceNode->setObjectName(QString::fromUtf8("label_tabmain_voiceNode"));

        gLayout_tabmain_status->addWidget(label_tabmain_voiceNode, 0, 4, 1, 1);

        label_tabmain_d435iConn = new QLabel(gBox_tabmain_status);
        label_tabmain_d435iConn->setObjectName(QString::fromUtf8("label_tabmain_d435iConn"));

        gLayout_tabmain_status->addWidget(label_tabmain_d435iConn, 1, 0, 1, 1);

        label_tabmain_kinect2Conn = new QLabel(gBox_tabmain_status);
        label_tabmain_kinect2Conn->setObjectName(QString::fromUtf8("label_tabmain_kinect2Conn"));

        gLayout_tabmain_status->addWidget(label_tabmain_kinect2Conn, 1, 1, 1, 1);

        label_tabmain_visionBridge = new QLabel(gBox_tabmain_status);
        label_tabmain_visionBridge->setObjectName(QString::fromUtf8("label_tabmain_visionBridge"));

        gLayout_tabmain_status->addWidget(label_tabmain_visionBridge, 3, 0, 1, 1);

        label_tabmain_senceFinish = new QLabel(gBox_tabmain_status);
        label_tabmain_senceFinish->setObjectName(QString::fromUtf8("label_tabmain_senceFinish"));

        gLayout_tabmain_status->addWidget(label_tabmain_senceFinish, 1, 2, 1, 1);

        label_tabmain_pickPlaceBridge = new QLabel(gBox_tabmain_status);
        label_tabmain_pickPlaceBridge->setObjectName(QString::fromUtf8("label_tabmain_pickPlaceBridge"));

        gLayout_tabmain_status->addWidget(label_tabmain_pickPlaceBridge, 1, 3, 1, 1);

        label_tabmain_uiNode = new QLabel(gBox_tabmain_status);
        label_tabmain_uiNode->setObjectName(QString::fromUtf8("label_tabmain_uiNode"));

        gLayout_tabmain_status->addWidget(label_tabmain_uiNode, 1, 4, 1, 1);


        horizontalLayout_5->addLayout(gLayout_tabmain_status);


        hLayout_tabmain_11->addWidget(gBox_tabmain_status);


        vLayout_tabmain_1->addLayout(hLayout_tabmain_11);

        hLayout_tabmain_21 = new QHBoxLayout();
        hLayout_tabmain_21->setSpacing(6);
        hLayout_tabmain_21->setObjectName(QString::fromUtf8("hLayout_tabmain_21"));
        gBox_tabmain_mode = new QGroupBox(tab_main);
        gBox_tabmain_mode->setObjectName(QString::fromUtf8("gBox_tabmain_mode"));
        gBox_tabmain_mode->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(gBox_tabmain_mode);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        cbox_tabmain_chooseMode = new QComboBox(gBox_tabmain_mode);
        cbox_tabmain_chooseMode->addItem(QString());
        cbox_tabmain_chooseMode->addItem(QString());
        cbox_tabmain_chooseMode->addItem(QString());
        cbox_tabmain_chooseMode->setObjectName(QString::fromUtf8("cbox_tabmain_chooseMode"));
        cbox_tabmain_chooseMode->setMaximumSize(QSize(200, 50));
        cbox_tabmain_chooseMode->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_6->addWidget(cbox_tabmain_chooseMode);


        hLayout_tabmain_21->addWidget(gBox_tabmain_mode);


        vLayout_tabmain_1->addLayout(hLayout_tabmain_21);

        hLayout_tabmain_31 = new QHBoxLayout();
        hLayout_tabmain_31->setSpacing(6);
        hLayout_tabmain_31->setObjectName(QString::fromUtf8("hLayout_tabmain_31"));
        gBox_tabmain_func = new QGroupBox(tab_main);
        gBox_tabmain_func->setObjectName(QString::fromUtf8("gBox_tabmain_func"));
        gBox_tabmain_func->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(gBox_tabmain_func);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        btn_tabmain_devConn = new QPushButton(gBox_tabmain_func);
        btn_tabmain_devConn->setObjectName(QString::fromUtf8("btn_tabmain_devConn"));
        btn_tabmain_devConn->setMaximumSize(QSize(150, 50));

        horizontalLayout_7->addWidget(btn_tabmain_devConn);

        btn_tabmain_runPrepare = new QPushButton(gBox_tabmain_func);
        btn_tabmain_runPrepare->setObjectName(QString::fromUtf8("btn_tabmain_runPrepare"));
        btn_tabmain_runPrepare->setMaximumSize(QSize(150, 50));

        horizontalLayout_7->addWidget(btn_tabmain_runPrepare);

        btn_tabmain_sysStop = new QPushButton(gBox_tabmain_func);
        btn_tabmain_sysStop->setObjectName(QString::fromUtf8("btn_tabmain_sysStop"));
        btn_tabmain_sysStop->setMaximumSize(QSize(150, 50));

        horizontalLayout_7->addWidget(btn_tabmain_sysStop);

        btn_tabmain_sysReset = new QPushButton(gBox_tabmain_func);
        btn_tabmain_sysReset->setObjectName(QString::fromUtf8("btn_tabmain_sysReset"));
        btn_tabmain_sysReset->setMaximumSize(QSize(150, 50));

        horizontalLayout_7->addWidget(btn_tabmain_sysReset);


        hLayout_tabmain_31->addWidget(gBox_tabmain_func);


        vLayout_tabmain_1->addLayout(hLayout_tabmain_31);

        vLayout_tabmain_1->setStretch(0, 2);
        vLayout_tabmain_1->setStretch(1, 1);
        vLayout_tabmain_1->setStretch(2, 2);

        verticalLayout_2->addLayout(vLayout_tabmain_1);

        tabWidget->addTab(tab_main, QString());
        tab_autoMode = new QWidget();
        tab_autoMode->setObjectName(QString::fromUtf8("tab_autoMode"));
        horizontalLayout = new QHBoxLayout(tab_autoMode);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hLayout_tab_autoMode_1 = new QHBoxLayout();
        hLayout_tab_autoMode_1->setSpacing(6);
        hLayout_tab_autoMode_1->setObjectName(QString::fromUtf8("hLayout_tab_autoMode_1"));
        vLayout_tab_autoMode_11 = new QVBoxLayout();
        vLayout_tab_autoMode_11->setSpacing(6);
        vLayout_tab_autoMode_11->setObjectName(QString::fromUtf8("vLayout_tab_autoMode_11"));
        gBox_tab_autoMode_img = new QGroupBox(tab_autoMode);
        gBox_tab_autoMode_img->setObjectName(QString::fromUtf8("gBox_tab_autoMode_img"));
        gBox_tab_autoMode_img->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        horizontalLayout_15 = new QHBoxLayout(gBox_tab_autoMode_img);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        labeltab_autoMode_image = new QLabel(gBox_tab_autoMode_img);
        labeltab_autoMode_image->setObjectName(QString::fromUtf8("labeltab_autoMode_image"));
        labeltab_autoMode_image->setMaximumSize(QSize(300, 300));
        labeltab_autoMode_image->setPixmap(QPixmap(QString::fromUtf8("../../../../../demo_project/p7/catkin_ws/src/HsDualAppBridge/rb_ui/photo/question.jpg")));

        horizontalLayout_15->addWidget(labeltab_autoMode_image);


        vLayout_tab_autoMode_11->addWidget(gBox_tab_autoMode_img);


        hLayout_tab_autoMode_1->addLayout(vLayout_tab_autoMode_11);

        vLayout_tab_autoMode_12 = new QVBoxLayout();
        vLayout_tab_autoMode_12->setSpacing(6);
        vLayout_tab_autoMode_12->setObjectName(QString::fromUtf8("vLayout_tab_autoMode_12"));
        gBox_tab_autoMode_fsm = new QGroupBox(tab_autoMode);
        gBox_tab_autoMode_fsm->setObjectName(QString::fromUtf8("gBox_tab_autoMode_fsm"));
        gBox_tab_autoMode_fsm->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        horizontalLayout_17 = new QHBoxLayout(gBox_tab_autoMode_fsm);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        gLayout_tab_autoMode_fsm = new QGridLayout();
        gLayout_tab_autoMode_fsm->setSpacing(6);
        gLayout_tab_autoMode_fsm->setObjectName(QString::fromUtf8("gLayout_tab_autoMode_fsm"));
        label_tab_autoMode_grab = new QLabel(gBox_tab_autoMode_fsm);
        label_tab_autoMode_grab->setObjectName(QString::fromUtf8("label_tab_autoMode_grab"));

        gLayout_tab_autoMode_fsm->addWidget(label_tab_autoMode_grab, 1, 0, 1, 1);

        label_tab_autoMode_updatePCL = new QLabel(gBox_tab_autoMode_fsm);
        label_tab_autoMode_updatePCL->setObjectName(QString::fromUtf8("label_tab_autoMode_updatePCL"));

        gLayout_tab_autoMode_fsm->addWidget(label_tab_autoMode_updatePCL, 0, 2, 1, 1);

        label_tab_autoMode_detect = new QLabel(gBox_tab_autoMode_fsm);
        label_tab_autoMode_detect->setObjectName(QString::fromUtf8("label_tab_autoMode_detect"));

        gLayout_tab_autoMode_fsm->addWidget(label_tab_autoMode_detect, 0, 3, 1, 1);

        label_tab_autoMode_prepare = new QLabel(gBox_tab_autoMode_fsm);
        label_tab_autoMode_prepare->setObjectName(QString::fromUtf8("label_tab_autoMode_prepare"));

        gLayout_tab_autoMode_fsm->addWidget(label_tab_autoMode_prepare, 0, 1, 1, 1);

        label_tab_autoMode_init = new QLabel(gBox_tab_autoMode_fsm);
        label_tab_autoMode_init->setObjectName(QString::fromUtf8("label_tab_autoMode_init"));

        gLayout_tab_autoMode_fsm->addWidget(label_tab_autoMode_init, 0, 0, 1, 1);

        label_tab_autoMode_exit = new QLabel(gBox_tab_autoMode_fsm);
        label_tab_autoMode_exit->setObjectName(QString::fromUtf8("label_tab_autoMode_exit"));

        gLayout_tab_autoMode_fsm->addWidget(label_tab_autoMode_exit, 1, 3, 1, 1);

        label_tab_autoMode_err = new QLabel(gBox_tab_autoMode_fsm);
        label_tab_autoMode_err->setObjectName(QString::fromUtf8("label_tab_autoMode_err"));

        gLayout_tab_autoMode_fsm->addWidget(label_tab_autoMode_err, 1, 2, 1, 1);

        label_tab_autoMode_place = new QLabel(gBox_tab_autoMode_fsm);
        label_tab_autoMode_place->setObjectName(QString::fromUtf8("label_tab_autoMode_place"));

        gLayout_tab_autoMode_fsm->addWidget(label_tab_autoMode_place, 1, 1, 1, 1);


        horizontalLayout_17->addLayout(gLayout_tab_autoMode_fsm);


        vLayout_tab_autoMode_12->addWidget(gBox_tab_autoMode_fsm);

        gBox_tab_autoMode_mode = new QGroupBox(tab_autoMode);
        gBox_tab_autoMode_mode->setObjectName(QString::fromUtf8("gBox_tab_autoMode_mode"));
        gBox_tab_autoMode_mode->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        verticalLayout = new QVBoxLayout(gBox_tab_autoMode_mode);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cBox_tab_autoMode_mode = new QComboBox(gBox_tab_autoMode_mode);
        cBox_tab_autoMode_mode->addItem(QString());
        cBox_tab_autoMode_mode->addItem(QString());
        cBox_tab_autoMode_mode->setObjectName(QString::fromUtf8("cBox_tab_autoMode_mode"));

        verticalLayout->addWidget(cBox_tab_autoMode_mode);

        cBox_tab_autoMode_boxmodel = new QComboBox(gBox_tab_autoMode_mode);
        cBox_tab_autoMode_boxmodel->addItem(QString());
        cBox_tab_autoMode_boxmodel->addItem(QString());
        cBox_tab_autoMode_boxmodel->setObjectName(QString::fromUtf8("cBox_tab_autoMode_boxmodel"));

        verticalLayout->addWidget(cBox_tab_autoMode_boxmodel);


        vLayout_tab_autoMode_12->addWidget(gBox_tab_autoMode_mode);

        gBox_tab_autoMode_operate = new QGroupBox(tab_autoMode);
        gBox_tab_autoMode_operate->setObjectName(QString::fromUtf8("gBox_tab_autoMode_operate"));
        gBox_tab_autoMode_operate->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        verticalLayout_10 = new QVBoxLayout(gBox_tab_autoMode_operate);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        hLayout_tab_autoMode_123 = new QHBoxLayout();
        hLayout_tab_autoMode_123->setSpacing(6);
        hLayout_tab_autoMode_123->setObjectName(QString::fromUtf8("hLayout_tab_autoMode_123"));
        btn_tab_autoMode_run = new QPushButton(gBox_tab_autoMode_operate);
        btn_tab_autoMode_run->setObjectName(QString::fromUtf8("btn_tab_autoMode_run"));
        btn_tab_autoMode_run->setMaximumSize(QSize(150, 50));

        hLayout_tab_autoMode_123->addWidget(btn_tab_autoMode_run);

        btn_tab_autoMode_normalstop = new QPushButton(gBox_tab_autoMode_operate);
        btn_tab_autoMode_normalstop->setObjectName(QString::fromUtf8("btn_tab_autoMode_normalstop"));
        btn_tab_autoMode_normalstop->setMaximumSize(QSize(150, 50));

        hLayout_tab_autoMode_123->addWidget(btn_tab_autoMode_normalstop);

        btn_tab_autoMode_quickstop = new QPushButton(gBox_tab_autoMode_operate);
        btn_tab_autoMode_quickstop->setObjectName(QString::fromUtf8("btn_tab_autoMode_quickstop"));
        btn_tab_autoMode_quickstop->setMaximumSize(QSize(150, 50));

        hLayout_tab_autoMode_123->addWidget(btn_tab_autoMode_quickstop);


        verticalLayout_10->addLayout(hLayout_tab_autoMode_123);


        vLayout_tab_autoMode_12->addWidget(gBox_tab_autoMode_operate);


        hLayout_tab_autoMode_1->addLayout(vLayout_tab_autoMode_12);


        horizontalLayout->addLayout(hLayout_tab_autoMode_1);

        tabWidget->addTab(tab_autoMode, QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_autoMode), QString::fromUtf8("\350\207\252\345\212\250\346\250\241\345\274\217\347\225\214\351\235\242"));
        tab_stepMode = new QWidget();
        tab_stepMode->setObjectName(QString::fromUtf8("tab_stepMode"));
        horizontalLayout_4 = new QHBoxLayout(tab_stepMode);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        hLayout_tab_stepMode_1 = new QHBoxLayout();
        hLayout_tab_stepMode_1->setSpacing(6);
        hLayout_tab_stepMode_1->setObjectName(QString::fromUtf8("hLayout_tab_stepMode_1"));
        vLayout_tab_stepMode_12 = new QVBoxLayout();
        vLayout_tab_stepMode_12->setSpacing(6);
        vLayout_tab_stepMode_12->setObjectName(QString::fromUtf8("vLayout_tab_stepMode_12"));
        gBox_tab_stepMode_showImg = new QGroupBox(tab_stepMode);
        gBox_tab_stepMode_showImg->setObjectName(QString::fromUtf8("gBox_tab_stepMode_showImg"));
        gBox_tab_stepMode_showImg->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        horizontalLayout_10 = new QHBoxLayout(gBox_tab_stepMode_showImg);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_tab_stepMode_showImg = new QLabel(gBox_tab_stepMode_showImg);
        label_tab_stepMode_showImg->setObjectName(QString::fromUtf8("label_tab_stepMode_showImg"));

        horizontalLayout_10->addWidget(label_tab_stepMode_showImg);


        vLayout_tab_stepMode_12->addWidget(gBox_tab_stepMode_showImg);


        hLayout_tab_stepMode_1->addLayout(vLayout_tab_stepMode_12);

        vLayout_tab_stepMode_11 = new QVBoxLayout();
        vLayout_tab_stepMode_11->setSpacing(6);
        vLayout_tab_stepMode_11->setObjectName(QString::fromUtf8("vLayout_tab_stepMode_11"));
        gBox_tab_stepMode_status = new QGroupBox(tab_stepMode);
        gBox_tab_stepMode_status->setObjectName(QString::fromUtf8("gBox_tab_stepMode_status"));
        gBox_tab_stepMode_status->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        horizontalLayout_11 = new QHBoxLayout(gBox_tab_stepMode_status);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        gLayout_tab_stepMode = new QGridLayout();
        gLayout_tab_stepMode->setSpacing(6);
        gLayout_tab_stepMode->setObjectName(QString::fromUtf8("gLayout_tab_stepMode"));
        label_tab_stepMode_pickPlaceBridge = new QLabel(gBox_tab_stepMode_status);
        label_tab_stepMode_pickPlaceBridge->setObjectName(QString::fromUtf8("label_tab_stepMode_pickPlaceBridge"));

        gLayout_tab_stepMode->addWidget(label_tab_stepMode_pickPlaceBridge, 1, 0, 1, 1);

        label_tab_stepMode_senceFinish = new QLabel(gBox_tab_stepMode_status);
        label_tab_stepMode_senceFinish->setObjectName(QString::fromUtf8("label_tab_stepMode_senceFinish"));

        gLayout_tab_stepMode->addWidget(label_tab_stepMode_senceFinish, 1, 4, 1, 1);

        label_tab_stepMode_rd435iConn = new QLabel(gBox_tab_stepMode_status);
        label_tab_stepMode_rd435iConn->setObjectName(QString::fromUtf8("label_tab_stepMode_rd435iConn"));

        gLayout_tab_stepMode->addWidget(label_tab_stepMode_rd435iConn, 0, 3, 1, 1);

        label_tab_stepMode_rbIsWell = new QLabel(gBox_tab_stepMode_status);
        label_tab_stepMode_rbIsWell->setObjectName(QString::fromUtf8("label_tab_stepMode_rbIsWell"));

        gLayout_tab_stepMode->addWidget(label_tab_stepMode_rbIsWell, 0, 0, 1, 1);

        label_tab_stepMode_rbEnable = new QLabel(gBox_tab_stepMode_status);
        label_tab_stepMode_rbEnable->setObjectName(QString::fromUtf8("label_tab_stepMode_rbEnable"));

        gLayout_tab_stepMode->addWidget(label_tab_stepMode_rbEnable, 0, 1, 1, 1);

        label_tab_stepMode_gripperConn = new QLabel(gBox_tab_stepMode_status);
        label_tab_stepMode_gripperConn->setObjectName(QString::fromUtf8("label_tab_stepMode_gripperConn"));

        gLayout_tab_stepMode->addWidget(label_tab_stepMode_gripperConn, 0, 2, 1, 1);

        label_tab_stepMode_plannerBridge = new QLabel(gBox_tab_stepMode_status);
        label_tab_stepMode_plannerBridge->setObjectName(QString::fromUtf8("label_tab_stepMode_plannerBridge"));

        gLayout_tab_stepMode->addWidget(label_tab_stepMode_plannerBridge, 1, 1, 1, 1);

        label_tab_stepMode_motionBridge = new QLabel(gBox_tab_stepMode_status);
        label_tab_stepMode_motionBridge->setObjectName(QString::fromUtf8("label_tab_stepMode_motionBridge"));

        gLayout_tab_stepMode->addWidget(label_tab_stepMode_motionBridge, 1, 2, 1, 1);

        label_tab_stepMode_perceptionBridge = new QLabel(gBox_tab_stepMode_status);
        label_tab_stepMode_perceptionBridge->setObjectName(QString::fromUtf8("label_tab_stepMode_perceptionBridge"));

        gLayout_tab_stepMode->addWidget(label_tab_stepMode_perceptionBridge, 1, 3, 1, 1);

        label_tab_stepMode_dmBridge = new QLabel(gBox_tab_stepMode_status);
        label_tab_stepMode_dmBridge->setObjectName(QString::fromUtf8("label_tab_stepMode_dmBridge"));

        gLayout_tab_stepMode->addWidget(label_tab_stepMode_dmBridge, 0, 4, 1, 1);


        horizontalLayout_11->addLayout(gLayout_tab_stepMode);


        vLayout_tab_stepMode_11->addWidget(gBox_tab_stepMode_status);

        gBox_tab_stepMode_operate = new QGroupBox(tab_stepMode);
        gBox_tab_stepMode_operate->setObjectName(QString::fromUtf8("gBox_tab_stepMode_operate"));
        gBox_tab_stepMode_operate->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        horizontalLayout_12 = new QHBoxLayout(gBox_tab_stepMode_operate);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        btn_tab_stepMode_goPhotoPose = new QPushButton(gBox_tab_stepMode_operate);
        btn_tab_stepMode_goPhotoPose->setObjectName(QString::fromUtf8("btn_tab_stepMode_goPhotoPose"));
        btn_tab_stepMode_goPhotoPose->setMaximumSize(QSize(150, 50));

        horizontalLayout_12->addWidget(btn_tab_stepMode_goPhotoPose);

        btn_tab_stepMode_detectAndGrab = new QPushButton(gBox_tab_stepMode_operate);
        btn_tab_stepMode_detectAndGrab->setObjectName(QString::fromUtf8("btn_tab_stepMode_detectAndGrab"));
        btn_tab_stepMode_detectAndGrab->setMaximumSize(QSize(150, 50));

        horizontalLayout_12->addWidget(btn_tab_stepMode_detectAndGrab);

        btn_tab_stepMode_goHomePose = new QPushButton(gBox_tab_stepMode_operate);
        btn_tab_stepMode_goHomePose->setObjectName(QString::fromUtf8("btn_tab_stepMode_goHomePose"));
        btn_tab_stepMode_goHomePose->setMaximumSize(QSize(150, 50));

        horizontalLayout_12->addWidget(btn_tab_stepMode_goHomePose);

        btn_tab_stepMode_Estop = new QPushButton(gBox_tab_stepMode_operate);
        btn_tab_stepMode_Estop->setObjectName(QString::fromUtf8("btn_tab_stepMode_Estop"));
        btn_tab_stepMode_Estop->setMaximumSize(QSize(150, 50));

        horizontalLayout_12->addWidget(btn_tab_stepMode_Estop);


        vLayout_tab_stepMode_11->addWidget(gBox_tab_stepMode_operate);


        hLayout_tab_stepMode_1->addLayout(vLayout_tab_stepMode_11);

        hLayout_tab_stepMode_1->setStretch(0, 1);
        hLayout_tab_stepMode_1->setStretch(1, 1);

        horizontalLayout_4->addLayout(hLayout_tab_stepMode_1);

        tabWidget->addTab(tab_stepMode, QString());
        tab_debug = new QWidget();
        tab_debug->setObjectName(QString::fromUtf8("tab_debug"));
        verticalLayout_5 = new QVBoxLayout(tab_debug);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_tabdebug_1 = new QGroupBox(tab_debug);
        groupBox_tabdebug_1->setObjectName(QString::fromUtf8("groupBox_tabdebug_1"));
        groupBox_tabdebug_1->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        horizontalLayout_14 = new QHBoxLayout(groupBox_tabdebug_1);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        btn_rbSetEnable = new QPushButton(groupBox_tabdebug_1);
        btn_rbSetEnable->setObjectName(QString::fromUtf8("btn_rbSetEnable"));
        btn_rbSetEnable->setMaximumSize(QSize(150, 50));

        horizontalLayout_14->addWidget(btn_rbSetEnable);

        btn_rbReset = new QPushButton(groupBox_tabdebug_1);
        btn_rbReset->setObjectName(QString::fromUtf8("btn_rbReset"));
        btn_rbReset->setMaximumSize(QSize(150, 50));

        horizontalLayout_14->addWidget(btn_rbReset);


        verticalLayout_5->addWidget(groupBox_tabdebug_1);

        groupBox_tabdebug_2 = new QGroupBox(tab_debug);
        groupBox_tabdebug_2->setObjectName(QString::fromUtf8("groupBox_tabdebug_2"));
        groupBox_tabdebug_2->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        horizontalLayout_19 = new QHBoxLayout(groupBox_tabdebug_2);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        btn_gripper_open = new QPushButton(groupBox_tabdebug_2);
        btn_gripper_open->setObjectName(QString::fromUtf8("btn_gripper_open"));
        btn_gripper_open->setMaximumSize(QSize(150, 50));

        horizontalLayout_19->addWidget(btn_gripper_open);

        btn_gripper_close = new QPushButton(groupBox_tabdebug_2);
        btn_gripper_close->setObjectName(QString::fromUtf8("btn_gripper_close"));
        btn_gripper_close->setMaximumSize(QSize(150, 50));

        horizontalLayout_19->addWidget(btn_gripper_close);


        verticalLayout_5->addWidget(groupBox_tabdebug_2);

        groupBox_tabdebug_3 = new QGroupBox(tab_debug);
        groupBox_tabdebug_3->setObjectName(QString::fromUtf8("groupBox_tabdebug_3"));
        groupBox_tabdebug_3->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        horizontalLayout_20 = new QHBoxLayout(groupBox_tabdebug_3);
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        btn_rbGoHomePose = new QPushButton(groupBox_tabdebug_3);
        btn_rbGoHomePose->setObjectName(QString::fromUtf8("btn_rbGoHomePose"));
        btn_rbGoHomePose->setMaximumSize(QSize(150, 50));

        horizontalLayout_20->addWidget(btn_rbGoHomePose);


        verticalLayout_5->addWidget(groupBox_tabdebug_3);

        tabWidget->addTab(tab_debug, QString());
        tab_recorder = new QWidget();
        tab_recorder->setObjectName(QString::fromUtf8("tab_recorder"));
        horizontalLayout_3 = new QHBoxLayout(tab_recorder);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        vLayout_tab_recorder_1 = new QVBoxLayout();
        vLayout_tab_recorder_1->setSpacing(6);
        vLayout_tab_recorder_1->setObjectName(QString::fromUtf8("vLayout_tab_recorder_1"));
        vLayout_tab_recorder_11 = new QVBoxLayout();
        vLayout_tab_recorder_11->setSpacing(6);
        vLayout_tab_recorder_11->setObjectName(QString::fromUtf8("vLayout_tab_recorder_11"));
        plainText_tabrecorder = new QPlainTextEdit(tab_recorder);
        plainText_tabrecorder->setObjectName(QString::fromUtf8("plainText_tabrecorder"));

        vLayout_tab_recorder_11->addWidget(plainText_tabrecorder);


        vLayout_tab_recorder_1->addLayout(vLayout_tab_recorder_11);


        horizontalLayout_3->addLayout(vLayout_tab_recorder_1);

        vLayout_tab_recorder_2 = new QVBoxLayout();
        vLayout_tab_recorder_2->setSpacing(6);
        vLayout_tab_recorder_2->setObjectName(QString::fromUtf8("vLayout_tab_recorder_2"));
        btn_tab_recoder_ouputRecorder = new QPushButton(tab_recorder);
        btn_tab_recoder_ouputRecorder->setObjectName(QString::fromUtf8("btn_tab_recoder_ouputRecorder"));
        btn_tab_recoder_ouputRecorder->setMaximumSize(QSize(150, 50));

        vLayout_tab_recorder_2->addWidget(btn_tab_recoder_ouputRecorder);

        btn_tab_recoder_clearRecorder = new QPushButton(tab_recorder);
        btn_tab_recoder_clearRecorder->setObjectName(QString::fromUtf8("btn_tab_recoder_clearRecorder"));
        btn_tab_recoder_clearRecorder->setMaximumSize(QSize(150, 50));

        vLayout_tab_recorder_2->addWidget(btn_tab_recoder_clearRecorder);


        horizontalLayout_3->addLayout(vLayout_tab_recorder_2);

        tabWidget->addTab(tab_recorder, QString());

        hLayout_main_12->addWidget(tabWidget);


        vLayout_main->addLayout(hLayout_main_12);

        vLayout_main->setStretch(0, 1);
        vLayout_main->setStretch(1, 9);

        horizontalLayout_2->addLayout(vLayout_main);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_main_logo->setText(QString());
        label_main_title->setText(QApplication::translate("MainWindow", "\345\215\217\344\275\234\346\234\272\345\231\250\344\272\272\346\212\223\345\217\226\345\271\263\345\217\260", nullptr));
        gBox_tabmain_status->setTitle(QApplication::translate("MainWindow", "\350\277\220\350\241\214\345\207\206\345\244\207\347\212\266\346\200\201", nullptr));
        label_tabmain_motionBridge->setText(QApplication::translate("MainWindow", "\350\277\220\345\212\250\346\241\245\350\212\202\347\202\271", nullptr));
        label_tabmain_perceptionBridge->setText(QApplication::translate("MainWindow", "\346\204\237\347\237\245\346\241\245\350\212\202\347\202\271", nullptr));
        label_tabmain_rbConn->setText(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\350\277\236\346\216\245", nullptr));
        label_tabmain_rbIsWell->setText(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\346\255\243\345\270\270", nullptr));
        label_tabmain_rbEnable->setText(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\344\274\272\346\234\215", nullptr));
        label_tabmain_plannerBridge->setText(QApplication::translate("MainWindow", "\350\247\204\345\210\222\346\241\245\350\212\202\347\202\271", nullptr));
        label_tabmain_dmBridge->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\241\245\350\212\202\347\202\271", nullptr));
        label_tabmain_gripperConn->setText(QApplication::translate("MainWindow", "\345\244\271\347\210\252\350\277\236\346\216\245", nullptr));
        label_tabmain_voiceNode->setText(QApplication::translate("MainWindow", "\350\257\255\351\237\263\350\212\202\347\202\271", nullptr));
        label_tabmain_d435iConn->setText(QApplication::translate("MainWindow", "d435i\347\233\270\346\234\272\350\277\236\346\216\245", nullptr));
        label_tabmain_kinect2Conn->setText(QApplication::translate("MainWindow", "kinect2\347\233\270\346\234\272\350\277\236\346\216\245", nullptr));
        label_tabmain_visionBridge->setText(QApplication::translate("MainWindow", "\350\247\206\350\247\211\346\241\245\350\212\202\347\202\271", nullptr));
        label_tabmain_senceFinish->setText(QApplication::translate("MainWindow", "\345\234\272\346\231\257\345\212\240\350\275\275\345\256\214\346\257\225", nullptr));
        label_tabmain_pickPlaceBridge->setText(QApplication::translate("MainWindow", "\346\212\223\345\217\226\346\241\245\350\212\202\347\202\271", nullptr));
        label_tabmain_uiNode->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\234\272\350\212\202\347\202\271", nullptr));
        gBox_tabmain_mode->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
        cbox_tabmain_chooseMode->setItemText(0, QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\350\277\220\350\241\214\346\250\241\345\274\217", nullptr));
        cbox_tabmain_chooseMode->setItemText(1, QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\250\241\345\274\217", nullptr));
        cbox_tabmain_chooseMode->setItemText(2, QApplication::translate("MainWindow", "\346\211\213\345\212\250\346\250\241\345\274\217", nullptr));

        gBox_tabmain_func->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\212\237\350\203\275", nullptr));
        btn_tabmain_devConn->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\350\277\236\346\216\245", nullptr));
        btn_tabmain_runPrepare->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214\345\207\206\345\244\207", nullptr));
        btn_tabmain_sysStop->setText(QApplication::translate("MainWindow", "\347\264\247\346\200\245\345\201\234\346\255\242", nullptr));
        btn_tabmain_sysReset->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\244\215\344\275\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_main), QApplication::translate("MainWindow", "\344\270\273\347\225\214\351\235\242", nullptr));
        gBox_tab_autoMode_img->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217\346\230\276\347\244\272", nullptr));
        labeltab_autoMode_image->setText(QString());
        gBox_tab_autoMode_fsm->setTitle(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\234\272\347\233\221\346\216\247", nullptr));
        label_tab_autoMode_grab->setText(QApplication::translate("MainWindow", "\346\212\223\345\217\226\347\233\256\346\240\207", nullptr));
        label_tab_autoMode_updatePCL->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260\347\202\271\344\272\221", nullptr));
        label_tab_autoMode_detect->setText(QApplication::translate("MainWindow", "\346\243\200\346\265\213\347\233\256\346\240\207", nullptr));
        label_tab_autoMode_prepare->setText(QApplication::translate("MainWindow", "\345\207\206\345\244\207\347\212\266\346\200\201", nullptr));
        label_tab_autoMode_init->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\347\212\266\346\200\201", nullptr));
        label_tab_autoMode_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\212\266\346\200\201", nullptr));
        label_tab_autoMode_err->setText(QApplication::translate("MainWindow", "\346\225\205\351\232\234\347\212\266\346\200\201", nullptr));
        label_tab_autoMode_place->setText(QApplication::translate("MainWindow", "\346\224\276\347\275\256\347\233\256\346\240\207", nullptr));
        gBox_tab_autoMode_mode->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\274\217\350\256\276\347\275\256", nullptr));
        cBox_tab_autoMode_mode->setItemText(0, QApplication::translate("MainWindow", "\345\243\260\346\216\247\346\250\241\345\274\217", nullptr));
        cBox_tab_autoMode_mode->setItemText(1, QApplication::translate("MainWindow", "\351\235\236\345\243\260\346\216\247\346\250\241\345\274\217", nullptr));

        cBox_tab_autoMode_boxmodel->setItemText(0, QApplication::translate("MainWindow", "\346\212\223\346\227\272\344\273\224\347\211\233\345\245\266", nullptr));
        cBox_tab_autoMode_boxmodel->setItemText(1, QApplication::translate("MainWindow", "\346\212\223\347\273\264\344\273\226\345\245\266", nullptr));

        gBox_tab_autoMode_operate->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234\346\240\217", nullptr));
        btn_tab_autoMode_run->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250", nullptr));
        btn_tab_autoMode_normalstop->setText(QApplication::translate("MainWindow", "\345\276\252\347\216\257\345\201\234\346\255\242", nullptr));
        btn_tab_autoMode_quickstop->setText(QApplication::translate("MainWindow", "\346\200\245\345\201\234", nullptr));
        gBox_tab_stepMode_showImg->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217\346\230\276\347\244\272", nullptr));
        label_tab_stepMode_showImg->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        gBox_tab_stepMode_status->setTitle(QApplication::translate("MainWindow", "\345\207\206\345\244\207\347\212\266\346\200\201", nullptr));
        label_tab_stepMode_pickPlaceBridge->setText(QApplication::translate("MainWindow", "\346\212\223\345\217\226\346\241\245\350\212\202\347\202\271", nullptr));
        label_tab_stepMode_senceFinish->setText(QApplication::translate("MainWindow", "\345\234\272\346\231\257\345\212\240\350\275\275\345\256\214\346\257\225", nullptr));
        label_tab_stepMode_rd435iConn->setText(QApplication::translate("MainWindow", "d435i\347\233\270\346\234\272\350\277\236\346\216\245", nullptr));
        label_tab_stepMode_rbIsWell->setText(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\346\255\243\345\270\270", nullptr));
        label_tab_stepMode_rbEnable->setText(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\344\274\272\346\234\215", nullptr));
        label_tab_stepMode_gripperConn->setText(QApplication::translate("MainWindow", "\345\244\271\347\210\252\350\277\236\346\216\245", nullptr));
        label_tab_stepMode_plannerBridge->setText(QApplication::translate("MainWindow", "\350\247\204\345\210\222\346\241\245\350\212\202\347\202\271", nullptr));
        label_tab_stepMode_motionBridge->setText(QApplication::translate("MainWindow", "\350\277\220\345\212\250\346\241\245", nullptr));
        label_tab_stepMode_perceptionBridge->setText(QApplication::translate("MainWindow", "\346\204\237\347\237\245\346\241\245", nullptr));
        label_tab_stepMode_dmBridge->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\241\245\350\212\202\347\202\271", nullptr));
        gBox_tab_stepMode_operate->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234\346\240\217", nullptr));
        btn_tab_stepMode_goPhotoPose->setText(QApplication::translate("MainWindow", "\345\216\273\345\210\260\346\213\215\347\205\247\347\202\271", nullptr));
        btn_tab_stepMode_detectAndGrab->setText(QApplication::translate("MainWindow", "\350\257\206\345\210\253\346\212\223\345\217\226", nullptr));
        btn_tab_stepMode_goHomePose->setText(QApplication::translate("MainWindow", "\345\233\236\345\216\237\347\202\271", nullptr));
        btn_tab_stepMode_Estop->setText(QApplication::translate("MainWindow", "\346\200\245\345\201\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_stepMode), QApplication::translate("MainWindow", "\346\211\213\345\212\250\346\250\241\345\274\217\347\225\214\351\235\242", nullptr));
        groupBox_tabdebug_1->setTitle(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\350\260\203\350\257\225", nullptr));
        btn_rbSetEnable->setText(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\344\270\212\344\275\277\350\203\275", nullptr));
        btn_rbReset->setText(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\345\244\215\344\275\215", nullptr));
        groupBox_tabdebug_2->setTitle(QApplication::translate("MainWindow", "\345\244\271\347\210\252\350\260\203\350\257\225", nullptr));
        btn_gripper_open->setText(QApplication::translate("MainWindow", "\345\274\240\345\274\200", nullptr));
        btn_gripper_close->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        groupBox_tabdebug_3->setTitle(QApplication::translate("MainWindow", "\345\205\266\344\273\226\350\260\203\350\257\225", nullptr));
        btn_rbGoHomePose->setText(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\345\233\236\345\216\237\347\202\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_debug), QApplication::translate("MainWindow", "\350\260\203\350\257\225\347\225\214\351\235\242", nullptr));
        btn_tab_recoder_ouputRecorder->setText(QApplication::translate("MainWindow", "\346\227\245\345\277\227\345\257\274\345\207\272", nullptr));
        btn_tab_recoder_clearRecorder->setText(QApplication::translate("MainWindow", "\346\227\245\345\277\227\346\270\205\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_recorder), QApplication::translate("MainWindow", "\346\227\245\345\277\227\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // A_H
