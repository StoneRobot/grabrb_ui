#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "Gomoku_UI");
    ros::NodeHandle nh;
    ros::AsyncSpinner spinner(2);
    spinner.start();

    QApplication a(argc, argv);
    MainWindow w(NULL, &nh);
    w.show();


    return a.exec();
}
