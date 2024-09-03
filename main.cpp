#include "mainwindow.h"
#include <QApplication>

#include "Code/ui/scan_gobang.h"

MainWindow *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new MainWindow();
    w->show();

    return a.exec();
}
