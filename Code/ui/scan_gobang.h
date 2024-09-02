#ifndef SCAN_GOBANG_H
#define SCAN_GOBANG_H

#include <iostream>
#include <stdio.h>
using namespace std;
#include <QPainter>

#include "mainwindow.h"

/*
* ∂‡œﬂ≥Ã
*/
#include <QThread>

class scan_gobang : public QThread
{
private:
    void draw_chess();

    const int SIZE=20;
    const int WIDTH=40;
    const int x=20,y=20;
public:
    scan_gobang();

    void down_pawn(char x, char y, char color);

protected:
    void run();

private:
    QPainter *paint;
};

#endif // SCAN_GOBANG_H
