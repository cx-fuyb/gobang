#ifndef SCAN_GOBANG_H
#define SCAN_GOBANG_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

using namespace std;

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
    explicit scan_gobang(QWidget *parent = nullptr);
    ~scan_gobang();

public:
    void draw_chess(char x,char y, char color);
    void draw_chessboard();
    void clearchess();
    void update_chess();
public:
    void mousePressEvent(QMouseEvent* event); //��������Ӧ���������Ҽ�����˫����
    // void mouseMoveEvent(QMouseEvent* event); //����ƶ���Ӧ����
    // void mouseReleaseEvent(QMouseEvent* event); //����ͷ���Ӧ���������Ҽ�����˫����

public:
    /*
    ��д��ͼ�¼����麯��
    ����ڻ�ͼ���ڻ�ͼ��������ڻ�ͼ�¼���ʵ��
    ��ͼ�¼��ڲ��Զ����ã�������Ҫ�ؽ���ʱ��״̬�����ı䣩
    */
    void paintEvent(QPaintEvent*); //Qt���еĻ��ƶ�ֻ���ڴ˺��������

private:
    Ui::scan_gobang *ui;
    #define SIZE 10
    #define MAXWidget 500
    #define MAXheight 500
    ChessType Chess_Type;
    char chess[SIZE][SIZE];
    int WIDTH=40;
    int x=20,y=20;
    QPainter *paint;
};



#endif // SCAN_GOBANG_H
