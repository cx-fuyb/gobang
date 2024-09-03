#ifndef GOBANG_H
#define GOBANG_H
#include "qwidget.h"
#include <QPainter>
#include <stdio.h>

#include "Code/ui/scan_gobang.h"
#include "Code/net/gobang_network.h"

namespace Ui {
class MainWindow;
}
class Gobang
{
private:
    Gobang_Network *g_network;
public:
    scan_gobang *sg;
public:
    Gobang(Gobang_Network *gn);
private:

};

#endif // GOBANG_H
