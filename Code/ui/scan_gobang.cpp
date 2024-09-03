#include "scan_gobang.h"

scan_gobang::scan_gobang(QWidget *parent)
    : QWidget(parent)
{

}

/*
* 画棋盘
*/
void scan_gobang::draw_chess()
{
    /*
    * 钢笔工具：颜色，线号，实线
    */
    paint->setPen(QPen(Qt::darkGreen,2,Qt::SolidLine));

    for(int i=0;i<SIZE+1;i++) {
        /*
        * 画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线
        */
        paint->drawLine(x,y+WIDTH*i,x+WIDTH*(SIZE),y+WIDTH*i);
    }
    //画SIZE+1条竖线
    for(int i=0;i<SIZE+1;i++)
    {
        paint->drawLine(x+WIDTH*i,y,x+WIDTH*i,y+WIDTH*(SIZE));
    }
    paint->end();
}
void scan_gobang::paintEvent(QPaintEvent *)
{
    qDebug("paintEvent");
    paint = new QPainter;
    extern MainWindow *w;
    paint->begin(w);
    this->draw_chess();
}

void scan_gobang::run() {
    while (1) {
        this->update();
        //this->draw_chess();
        qDebug("hello");
        QThread::msleep(500);
    }
}
