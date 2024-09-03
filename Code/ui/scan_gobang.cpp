#include "scan_gobang.h"
#include "ui_scan_gobang.h"

scan_gobang::scan_gobang(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scan_gobang)
{
    ui->setupUi(this);
    paint=new QPainter;

    this->clearchess();
}

void scan_gobang::draw_chess(char x,char y, char color)
{
    if(color == Chessblack) {
        paint->setBrush(QBrush(Qt::black,Qt::SolidPattern));//ëˢ����ɫ��ʵͼ��
    }
    else if (color == Chesswhite) {
        paint->setBrush(QBrush(Qt::white,Qt::SolidPattern));//ëˢ����ɫ��ʵͼ��
    }

    //����Բ�����ĵ�X,Y,��ȣ��߶�
    paint->drawEllipse((this->x+x*WIDTH-WIDTH/4),(this->y+y*WIDTH-WIDTH/4),WIDTH/2,WIDTH/2);
}
void scan_gobang::update_chess()
{
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            if(chess[i][j] == Chessblack) {
                draw_chess(i,j,Chessblack);
            }
            else if(chess[i][j] == Chesswhite) {
                draw_chess(i,j,Chesswhite);
            }
        }
    }
}

void scan_gobang::clearchess() {
    for( int i = 0; i < SIZE; i++) {
        for(int j = i; j < SIZE; j++) {
            chess[i][j] = ChessNull;
        }
    }
}
void scan_gobang::paintEvent(QPaintEvent *)
{

    resize(width(), width()/2);

    if (width() < 300) {
        resize(300, height());
    }
    if (width() > height()) {
        WIDTH =(height()-x*2) / SIZE;
    } else {
        WIDTH =(width()-x*2) / SIZE;
    }
    paint->begin(this);//������
    draw_chessboard();
    update_chess();
    //draw_chess(2,2,Chesswhite);
    paint->end();
    qDebug("paintEvent width:%d", width());

    //update();
}

/*
* ������
*/
void scan_gobang::draw_chessboard()
{
    /*
    * �ֱʹ��ߣ���ɫ���ߺţ�ʵ��
    */
    paint->setPen(QPen(Qt::darkGreen,2,Qt::SolidLine));

    for(int i=0;i<SIZE+1;i++) {
        /*
        * ���ߺ�����x1,y1,x2,y2:����(x1,y1)��(x2,y2)����
        */
        paint->drawLine(x,y+WIDTH*i,x+WIDTH*(SIZE),y+WIDTH*i);
    }
    //��SIZE+1������
    for(int i=0;i<SIZE+1;i++)
    {
        paint->drawLine(x+WIDTH*i,y,x+WIDTH*i,y+WIDTH*(SIZE));
    }
}

void scan_gobang::mousePressEvent(QMouseEvent* event)
{
    /*
    * ��ȡ�����λ��
    */
    QPoint pt;
    int x = (event->pos().x()) / ((WIDTH+40) /SIZE);
    int y = event->pos().y() / ((WIDTH+40) /SIZE);
    qDebug("x:%d,y:%d",x,y);
    qDebug("mousePressEvent");
    chess[x][y] = Chessblack;
    update();
}

scan_gobang::~scan_gobang()
{
    delete ui;
}
