#ifndef GOBANG_NETWORK_H
#define GOBANG_NETWORK_H

#include <iostream>
#include <QThread>

#define log(fmt,...)    qDebug("\e[42m[%s] %s:%d\e[0m--"#fmt"", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define err(fmt,...)    qDebug("\e[41m[%s] %s:%d\e[0m--"#fmt"", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

class Gobang_Network: public QThread
{
public:
    Gobang_Network();

protected:
    void run();
};

#endif // GOBANG_NETWORK_H
