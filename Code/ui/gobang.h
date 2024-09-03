#ifndef GOBANG_H
#define GOBANG_H
#include <QWidget>
#include <QPainter>
#include <stdio.h>

#include "Code/net/gobang_network.h"

class Gobang
{
private:
    Gobang_Network *g_network;
public:
    Gobang(Gobang_Network *gn);
private:

};

#endif // GOBANG_H
