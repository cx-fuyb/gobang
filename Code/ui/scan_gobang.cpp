#include "scan_gobang.h"

scan_gobang::scan_gobang()
{
    this->start();
//    //������������һ��������
//    /*
//    * ëˢ����ɫ��ʵͼ��
//    */
//    paint->setBrush(QBrush(Qt::black,Qt::SolidPattern));
//    /*
//    * ����Բ�����ĵ�X,Y,��ȣ��߶�
//    */
//    paint->drawEllipse((SIZE+0.5)*WIDTH/2,(SIZE+0.5)*WIDTH/2,WIDTH/2,WIDTH/2);
//    paint->end();
}
void scan_gobang::draw_chess()
{
    /*
    * �ֱʹ��ߣ���ɫ���ߺţ�ʵ��
    *
    */
    paint->setPen(QPen(Qt::darkGreen,2,Qt::SolidLine));

    for(int i=0;i<SIZE+1;i++) {
        //���ߺ�����x1,y1,x2,y2:����(x1,y1)��(x2,y2)����
        paint->drawLine(x,y+WIDTH*i,x+WIDTH*(SIZE),y+WIDTH*i);
    }
    //��SIZE+1������
    for(int i=0;i<SIZE+1;i++)
    {
    paint->drawLine(x+WIDTH*i,y,x+WIDTH*i,y+WIDTH*(SIZE));
    }
}

void scan_gobang::run() {
    paint=new QPainter;

    extern MainWindow *w;
    paint->begin(w);//������
    while (1) {
        //this->draw_chess();
        qDebug("hello %d");
        QThread::msleep(500);
    }
}

void scan_gobang::down_pawn(char x, char y, char color) {

}
