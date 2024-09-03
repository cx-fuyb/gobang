#include "gobang_network.h"

using namespace std;

Gobang_Network::Gobang_Network()
{
    cout << "link network" << endl;

    log("start network thread");

    /* 连接服务器 */
    t.linkSever();

    tellOpponent_chassxy(1,1,-1);
    //测试线程
    //this->start();
}

/*
 * 作用:告诉对方下棋的位置
 * @x:x坐标
 * @y:y坐标
 * @color:颜色数据-1，0，1
*/
void Gobang_Network::tellOpponent_chassxy(uint8_t x, uint8_t y, char color)
{
    uint8_t *data = new uint8_t(3);

    data[0] = x;
    data[1] = y;
    data[2] = (uint8_t)color;

    tellOpponent_data(pos, data, 3);

    delete data;
}

void Gobang_Network::tellOpponent_data(uint8_t fun, uint8_t *data, uint8_t datalen)
{
    uint8_t txdata[50];

    /* 帧头 */
    txdata[0] = 0xf0;
    txdata[1] = 0x0f;

    /* 功能 */
    txdata[2] = fun;

    /* 数据 */
    for (uint8_t i=0; i<datalen; i++) {
        txdata[3+i] = data[i];
    }

    /* 发送数据 */
    t.sendBuff(txdata, datalen+3);
}
