#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    /*
//    * 画制棋盘
//    */
//    scan_gobang sg;
//    sg.show();
//    sg.update();
//    /*
//    * 线程启动
//    */
//    sg.start();

    /* 创建网络 */
    Gobang_Network gn;

    for (;;) {
        QThread::sleep(1);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
