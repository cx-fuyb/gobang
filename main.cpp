#include "mainwindow.h"
#include <QApplication>

#include "Code/ui/scan_gobang.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* �������� */
    Gobang_Network gn;

    /* ���� */
    //Gobang gb(&gn);

    return a.exec();
}
