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
    // ��ť��Ӧ����
    void on_pushButton_clicked();
    /* ��ʾѡ��������ɫ */
    void choose_color();

public:
    void mousePressEvent(QMouseEvent* event);   //��������Ӧ���������Ҽ�����˫����
    void mouseMoveEvent(QMouseEvent* event);    //����ƶ���Ӧ����
    void mouseReleaseEvent(QMouseEvent* event); //����ͷ���Ӧ���������Ҽ�����˫����

public:
    /*
    ��д��ͼ�¼����麯��
    ����ڻ�ͼ���ڻ�ͼ��������ڻ�ͼ�¼���ʵ��
    ��ͼ�¼��ڲ��Զ����ã�������Ҫ�ؽ���ʱ��״̬�����ı䣩
    */
    void paintEvent(QPaintEvent*); //Qt���еĻ��ƶ�ֻ���ڴ˺��������

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
