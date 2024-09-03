#include "gobang_network.h"

using namespace std;

Gobang_Network::Gobang_Network()
{
    cout << "link network" << endl;

    log("start network thread");

    this->start();
}

void Gobang_Network::run(){

    for (;;) {
        log("i am network thread");
        msleep(100);
    }
}
