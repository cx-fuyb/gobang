#include "mainwindow.h"
#include <QApplication>

#include "Code/ui/scan_gobang.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* 创建网络 */
    Gobang_Network gn;

    /* 创建 */
    //Gobang gb(&gn);

    return a.exec();
}
