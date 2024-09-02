#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* 创建网络 */
    Gobang_Network gn;

    for (;;) {
        err("下棋");
        QThread::sleep(1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
