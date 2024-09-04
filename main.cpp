#include "mainwindow.h"
#include <QApplication>

#include "Code/ui/scan_gobang.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* ´´½¨ÍøÂç */
    Gobang_Network gn;

    MainWindow *mwin = new MainWindow(&gn);
    mwin->show();

    return a.exec();
}
