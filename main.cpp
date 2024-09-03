#include "mainwindow.h"
#include <QApplication>

#include "Code/ui/scan_gobang.h"

MainWindow *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* ´´½¨ÍøÂç */
    Gobang_Network gn;

    Gobang gb(&gn);

//    w = new MainWindow();
//    w->show();
//    scan_gobang w1;
//    w1.show();

    return a.exec();
}
