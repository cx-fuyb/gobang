#include "scan_gobang.h"

scan_gobang::scan_gobang()
{
    this->start();
//    //在棋盘正中做一个黑棋子
//    /*
//    * 毛刷：颜色，实图案
//    */
//    paint->setBrush(QBrush(Qt::black,Qt::SolidPattern));
//    /*
//    * 画椭圆：中心点X,Y,宽度，高度
//    */
//    paint->drawEllipse((SIZE+0.5)*WIDTH/2,(SIZE+0.5)*WIDTH/2,WIDTH/2,WIDTH/2);
//    paint->end();
}
void scan_gobang::draw_chess()
{
    /*
    * 钢笔工具：颜色，线号，实线
    *
    */
    paint->setPen(QPen(Qt::darkGreen,2,Qt::SolidLine));

    for(int i=0;i<SIZE+1;i++) {
        //画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线
        paint->drawLine(x,y+WIDTH*i,x+WIDTH*(SIZE),y+WIDTH*i);
    }
    //画SIZE+1条竖线
    for(int i=0;i<SIZE+1;i++)
    {
    paint->drawLine(x+WIDTH*i,y,x+WIDTH*i,y+WIDTH*(SIZE));
    }
}

void scan_gobang::run() {
    paint=new QPainter;

    extern MainWindow *w;
    paint->begin(w);//主窗口
    while (1) {
        //this->draw_chess();
        qDebug("hello %d");
        QThread::msleep(500);
    }
}

void scan_gobang::down_pawn(char x, char y, char color) {

}
