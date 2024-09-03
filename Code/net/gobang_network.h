#ifndef GOBANG_NETWORK_H
#define GOBANG_NETWORK_H

#include "Code/net/tcp.h"

class Gobang_Network
{
public:
    enum {
        pos = 0x01U,
    };

public:
    Gobang_Network();

public:
    void tellOpponent_chassxy(uint8_t x, uint8_t y, char color);
    void tellOpponent_data(uint8_t fun, uint8_t *data, uint8_t datalen);
private:
    tcp t;
};



#endif // GOBANG_NETWORK_H
