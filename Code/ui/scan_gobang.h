#ifndef SCAN_GOBANG_H
#define SCAN_GOBANG_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

#include "Code/net/gobang_network.h"

using namespace std;

#define SIZE                15
#define CHASS_NUM        (SIZE+1)
#define MIN_WIDTH   1000

enum ChessType
{
    ChessNull = 0,
    Chessblack = 1,
    Chesswhite = -1,
};

namespace Ui {
class scan_gobang;
}

class scan_gobang : public QMainWindow
{
    Q_OBJECT

public:
    explicit scan_gobang(Gobang_Network *g_network,QWidget *parent = nullptr);
    ~scan_gobang();

public:
    void setChessStatus(char color);

public:
    void draw_chess(char x,char y, char color);
    void window_changed();
    void draw_chessboard();
    void clear_chess();
    void update_chess();
    void win_or_lose();
    // 按钮响应函数
    void on_pushButton_clicked();
    /* 提示选择棋子颜色 */
    void choose_color();

public:
    void mousePressEvent(QMouseEvent* event);   //鼠标击发响应函数（左右键，单双击）
    void mouseMoveEvent(QMouseEvent* event);    //鼠标移动响应函数
    void mouseReleaseEvent(QMouseEvent* event); //鼠标释放响应函数（左右键，单双击）

public:
    /*
    重写绘图事件，虚函数
    如果在绘图窗口绘图，必须放在绘图事件里实现
    绘图事件内部自动调用，窗口需要重建的时候（状态发生改变）
    */
    void paintEvent(QPaintEvent*); //Qt所有的绘制都只能在此函数中完成

private:
    Ui::scan_gobang *ui;
    Gobang_Network *g_network;
    char ChessStatus = ChessNull;
    char chess[CHASS_NUM][CHASS_NUM];
    int WIDTH=40;
    int padding = 20;
    QPainter *paint;
};



#endif // SCAN_GOBANG_H
