#include "tcp.h"

using namespace std;

tcp::tcp()
{
    log("I am tcp");
    this->tcpSocket = new QTcpSocket(this);

    //socket添加信号槽函数
    connect(tcpSocket,&QTcpSocket::readyRead,
            this,&tcp::onReadMessage);

    connect(tcpSocket, &QTcpSocket::connected, this, &tcp::connected);
}

uint8_t tcp::linkSever()
{
    //清除所有连接
    tcpSocket->abort();

    //连接服务端
    tcpSocket->connectToHost(host, post);
}

uint8_t tcp::sendBuff(uint8_t *buff, int len)
{
//    log("%s---%d", buff, len);

    tcpSocket->flush();//清空缓冲区
    tcpSocket->write((const char *)buff, len);

    return 1;
}

uint8_t tcp::sendString(QString str)
{

    QByteArray ba = str.toLatin1(); // must
    char *u8 = ba.data();

    return this->sendBuff((uint8_t *)u8, ba.length());
}

void tcp::connected()
{
    qDebug() << "连接成功";
    //tcpSocket->write("Hello from TCP Client!");
}

void tcp::onReadMessage()
{
    QByteArray bt;
    bt.resize(tcpSocket->bytesAvailable());
    tcpSocket->read(bt.data(),bt.size());

    log("收到数据");

    //打印出数据
    qDebug()<<bt;
}
