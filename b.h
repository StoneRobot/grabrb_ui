/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef B_H
#define B_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

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
    QWidget *tab;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *restartButton;
    QComboBox *modeBOx;
    QComboBox *firstRoundBox;
    QPushButton *resumeButton;
    QGroupBox *mode_groupBox;
    QGroupBox *gobang_state_groupBox;
    QLabel *InitState;
    QLabel *RunState;
    QLabel *StopState;
    QLabel *ExitState;
    QLabel *ErrorState;
    QGroupBox *chessboard_groupBox;
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
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        startButton = new QPushButton(tab);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(50, 230, 91, 41));
        stopButton = new QPushButton(tab);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(50, 290, 91, 41));
        restartButton = new QPushButton(tab);
        restartButton->setObjectName(QString::fromUtf8("restartButton"));
        restartButton->setGeometry(QRect(50, 410, 91, 41));
        modeBOx = new QComboBox(tab);
        modeBOx->setObjectName(QString::fromUtf8("modeBOx"));
        modeBOx->setGeometry(QRect(50, 110, 91, 41));
        firstRoundBox = new QComboBox(tab);
        firstRoundBox->setObjectName(QString::fromUtf8("firstRoundBox"));
        firstRoundBox->setGeometry(QRect(50, 170, 91, 41));
        resumeButton = new QPushButton(tab);
        resumeButton->setObjectName(QString::fromUtf8("resumeButton"));
        resumeButton->setGeometry(QRect(50, 350, 91, 41));
        mode_groupBox = new QGroupBox(tab);
        mode_groupBox->setObjectName(QString::fromUtf8("mode_groupBox"));
        mode_groupBox->setGeometry(QRect(10, 80, 161, 391));
        mode_groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:yellow;\n"
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
        mode_groupBox->setFlat(false);
        gobang_state_groupBox = new QGroupBox(tab);
        gobang_state_groupBox->setObjectName(QString::fromUtf8("gobang_state_groupBox"));
        gobang_state_groupBox->setGeometry(QRect(280, 20, 481, 101));
        gobang_state_groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:blue;\n"
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
        InitState = new QLabel(gobang_state_groupBox);
        InitState->setObjectName(QString::fromUtf8("InitState"));
        InitState->setGeometry(QRect(40, 30, 67, 51));
        InitState->setStyleSheet(QString::fromUtf8("QLable{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:black;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}"));
        RunState = new QLabel(gobang_state_groupBox);
        RunState->setObjectName(QString::fromUtf8("RunState"));
        RunState->setGeometry(QRect(120, 30, 67, 51));
        StopState = new QLabel(gobang_state_groupBox);
        StopState->setObjectName(QString::fromUtf8("StopState"));
        StopState->setGeometry(QRect(200, 30, 67, 51));
        ExitState = new QLabel(gobang_state_groupBox);
        ExitState->setObjectName(QString::fromUtf8("ExitState"));
        ExitState->setGeometry(QRect(280, 30, 67, 51));
        ErrorState = new QLabel(gobang_state_groupBox);
        ErrorState->setObjectName(QString::fromUtf8("ErrorState"));
        ErrorState->setGeometry(QRect(370, 20, 71, 71));
        InitState->raise();
        RunState->raise();
        StopState->raise();
        ExitState->raise();
        ErrorState->raise();
        mode_groupBox->raise();
        chessboard_groupBox = new QGroupBox(tab);
        chessboard_groupBox->setObjectName(QString::fromUtf8("chessboard_groupBox"));
        chessboard_groupBox->setGeometry(QRect(270, 130, 501, 411));
        chessboard_groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:red;\n"
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
        tabWidget->addTab(tab, QString());
        chessboard_groupBox->raise();
        mode_groupBox->raise();
        startButton->raise();
        stopButton->raise();
        restartButton->raise();
        modeBOx->raise();
        firstRoundBox->raise();
        resumeButton->raise();
        gobang_state_groupBox->raise();

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_main_logo->setText(QString());
        label_main_title->setText(QApplication::translate("MainWindow", "\345\215\217\344\275\234\346\234\272\345\231\250\344\272\272\346\212\223\345\217\226\345\271\263\345\217\260", 0, QApplication::UnicodeUTF8));
        gBox_tabmain_status->setTitle(QApplication::translate("MainWindow", "\350\277\220\350\241\214\345\207\206\345\244\207\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_tabmain_motionBridge->setText(QApplication::translate("MainWindow", "\350\277\220\345\212\250\346\241\245\350\212\202\347\202\271", 0, QApplication::UnicodeUTF8));
        label_tabmain_perceptionBridge->setText(QApplication::translate("MainWindow", "\346\204\237\347\237\245\346\241\245\350\212\202\347\202\271", 0, QApplication::UnicodeUTF8));
        label_tabmain_rbConn->setText(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_tabmain_rbIsWell->setText(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8));
        label_tabmain_rbEnable->setText(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272\344\274\272\346\234\215", 0, QApplication::UnicodeUTF8));
        label_tabmain_plannerBridge->setText(QApplication::translate("MainWindow", "\350\247\204\345\210\222\346\241\245\350\212\202\347\202\271", 0, QApplication::UnicodeUTF8));
        label_tabmain_dmBridge->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\241\245\350\212\202\347\202\271", 0, QApplication::UnicodeUTF8));
        label_tabmain_gripperConn->setText(QApplication::translate("MainWindow", "\345\244\271\347\210\252\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_tabmain_voiceNode->setText(QApplication::translate("MainWindow", "\350\257\255\351\237\263\350\212\202\347\202\271", 0, QApplication::UnicodeUTF8));
        label_tabmain_d435iConn->setText(QApplication::translate("MainWindow", "d435i\347\233\270\346\234\272\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_tabmain_kinect2Conn->setText(QApplication::translate("MainWindow", "kinect2\347\233\270\346\234\272\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_tabmain_visionBridge->setText(QApplication::translate("MainWindow", "\350\247\206\350\247\211\346\241\245\350\212\202\347\202\271", 0, QApplication::UnicodeUTF8));
        label_tabmain_senceFinish->setText(QApplication::translate("MainWindow", "\345\234\272\346\231\257\345\212\240\350\275\275\345\256\214\346\257\225", 0, QApplication::UnicodeUTF8));
        label_tabmain_pickPlaceBridge->setText(QApplication::translate("MainWindow", "\346\212\223\345\217\226\346\241\245\350\212\202\347\202\271", 0, QApplication::UnicodeUTF8));
        label_tabmain_uiNode->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\234\272\350\212\202\347\202\271", 0, QApplication::UnicodeUTF8));
        gBox_tabmain_mode->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\274\217\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        cbox_tabmain_chooseMode->clear();
        cbox_tabmain_chooseMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\350\277\220\350\241\214\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\211\213\345\212\250\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8)
        );
        gBox_tabmain_func->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\212\237\350\203\275", 0, QApplication::UnicodeUTF8));
        btn_tabmain_devConn->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        btn_tabmain_runPrepare->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214\345\207\206\345\244\207", 0, QApplication::UnicodeUTF8));
        btn_tabmain_sysStop->setText(QApplication::translate("MainWindow", "\347\264\247\346\200\245\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        btn_tabmain_sysReset->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_main), QApplication::translate("MainWindow", "\344\270\273\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0, QApplication::UnicodeUTF8));
        restartButton->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        modeBOx->clear();
        modeBOx->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "PVP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "PVR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "RVP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "RVR", 0, QApplication::UnicodeUTF8)
        );
        firstRoundBox->clear();
        firstRoundBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\205\210\346\211\213\346\226\271", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WHITE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "BLACK", 0, QApplication::UnicodeUTF8)
        );
        resumeButton->setText(QApplication::translate("MainWindow", "\347\273\247\347\273\255", 0, QApplication::UnicodeUTF8));
        mode_groupBox->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\274\217\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        gobang_state_groupBox->setTitle(QApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213\347\212\266\346\200\201\346\234\272", 0, QApplication::UnicodeUTF8));
        InitState->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        RunState->setText(QApplication::translate("MainWindow", "\345\257\271\346\210\230\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        StopState->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        ExitState->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        ErrorState->setText(QApplication::translate("MainWindow", "\345\274\202\345\270\270\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        chessboard_groupBox->setTitle(QApplication::translate("MainWindow", "\346\243\213\347\233\230", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // B_H
