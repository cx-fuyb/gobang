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
    paint->drawEllipse((this->padding+x*WIDTH-WIDTH/4),(this->padding+y*WIDTH-WIDTH/4),WIDTH/2,WIDTH/2);
}
void scan_gobang::update_chess()
{
    for(int i=0;i<CHASS_NUM;i++) {
        for(int j=0;j<CHASS_NUM;j++) {
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
    for( int i = 0; i < CHASS_NUM; i++) {
        for(int j = i; j < CHASS_NUM; j++) {
            chess[i][j] = ChessNull;
        }
    }
}
void scan_gobang::paintEvent(QPaintEvent *)
{
    window_changed();
    paint->begin(this);//������
    draw_chessboard();
    update_chess();
    //draw_chess(2,2,Chesswhite);
    paint->end();
    qDebug("paintEvent width:%d", width());

    //update();
}
/*
* ���ڴ�С�ı���Ӧ����
*/
void scan_gobang::window_changed()
{
    int new_width = std::max(width(), width() / 2);

    if (new_width < MIN_WIDTH) {
        new_width = MIN_WIDTH;
    }
    int new_height = new_width / 1.5;

    resize(new_width, new_height);

    if (width() > height()) {
        WIDTH =(height()-padding*2) / SIZE;
    } else {
        WIDTH =(width()-padding*2) / SIZE;
    }
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
        paint->drawLine(padding,padding+WIDTH*i,padding+WIDTH*(SIZE),padding+WIDTH*i);
    }
    //��SIZE+1������
    for(int i=0;i<SIZE+1;i++)
    {
        paint->drawLine(padding+WIDTH*i,padding,padding+WIDTH*i,padding+WIDTH*(SIZE));
    }
}

void scan_gobang::mousePressEvent(QMouseEvent* event)
{

    /*
    * ��ȡ�����λ��
    * ת��Ϊ��������
    */
    int mouse_x = event->pos().x();
    int mouse_y = event->pos().y();
    int width = (padding*2)+(WIDTH*SIZE);

    qDebug("mouse_x:%d,mouse_y:%d",mouse_x, mouse_y);

    if(mouse_x < padding || mouse_x > width) return;
    if(mouse_y < padding || mouse_y > width) return;

    mouse_x = mouse_x - padding;
    mouse_y = mouse_y - padding;

    /*
    chess_x * WIDTH - padding < chess_x * WIDTH < chess_x * WIDTH + padding
    */
    log("%d", width);

    int chess_x = (mouse_x) / (width/(SIZE+1));
    int chess_y = (mouse_y) / (width/(SIZE+1));
//    if ((mouse_x) % (WIDTH) > WIDTH / 2) {
        
//    }

//    if (chess_x * WIDTH < mouse_x || chess_x * WIDTH + WIDTH < mouse_x)

    qDebug("x:%d,y:%d",chess_x, chess_y);

    chess[chess_x][chess_y] = Chessblack;
    update();
}
void scan_gobang::mouseReleaseEvent(QMouseEvent* event)
{
    qDebug("����ƶ���Ӧ����");
}

void scan_gobang::mouseMoveEvent(QMouseEvent* event)
{
    qDebug("����ƶ���Ӧ����");
}

scan_gobang::~scan_gobang()
{
    delete ui;
}
