#ifndef SCAN_GOBANG_H
#define SCAN_GOBANG_H

#include <iostream>
#include <stdio.h>
using namespace std;
#include <QWidget>
#include <QPainter>
#include "mainwindow.h"
/*
* ∂‡œﬂ≥Ã
*/
#include <QThread>

class scan_gobang : public QThread, public QWidget
{
public:
    scan_gobang(QWidget *parent = 0);
protected:
    void run();

private:
    void draw_chess();
    void paintEvent(QPaintEvent *event);
    const int SIZE=20;
    const int WIDTH=40;
    const int x=20,y=20;
    QPainter *paint;
};

#endif // SCAN_GOBANG_H
