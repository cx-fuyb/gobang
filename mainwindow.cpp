#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Gobang_Network *gn, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->gb = new Gobang(gn);

    listview = new QListView(this);       //创建QListView对象
    //listview->setGeometry(0, 0, this->width(), this->height());         //设置位置和大小

    QStringList list;                                //创建数据显示列表
    list.append("莫德飞的棋盘");
    list.append("傅业丙的必赢局");
    list.append("开什么玩笑");

    //使用数据列表创建数据显示模型
    QStringListModel *listmodel = new QStringListModel(list);
    listview->setModel(listmodel);                   //设置模型到listview上

    listview->setMovement(QListView::Free);          //设置数据可以自由拖动
    listview->setSpacing(2);                         //设置数据的间距

    connect(listview, SIGNAL(clicked(const QModelIndex)),
                this, SLOT(slotClicked(const QModelIndex)));
    this->update_window();
}

void MainWindow::update_window()
{
    listview->setGeometry(0, 0, this->width(), this->height());         //设置位置和大小
}

void MainWindow::slotClicked(const QModelIndex &index)
{
    qDebug() << "选择的水果是:" << index.data().toString();
    this->close();
    this->gb->sg->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
