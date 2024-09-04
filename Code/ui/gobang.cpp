#include "gobang.h"

Gobang::Gobang(Gobang_Network *gn)
{
    this->g_network = gn;
    printf("mdf");

    sg = new scan_gobang();
}
