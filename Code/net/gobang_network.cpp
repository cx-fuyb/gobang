#include "gobang_network.h"

using namespace std;

Gobang_Network::Gobang_Network()
{
    cout << "link network" << endl;

    log("start network thread");

    this->tcpSocket = new QTcpSocket(this);

    //socket添加信号槽函数
    connect(tcpSocket,&QTcpSocket::readyRead,
            this,&Gobang_Network::onReadMessage);

    connect(tcpSocket, &QTcpSocket::connected, this, &Gobang_Network::connected);

    this->linkSever();

    //测试线程
    //this->start();
}

void Gobang_Network::run(){

    for (;;) {
<<<<<<< HEAD

        //log("i am network thread");
        sendString("i am network thread");
        msleep(1000);
=======
        //log("%d", width());
        msleep(100);
>>>>>>> modefei
    }
}

void Gobang_Network::onReadMessage()
{
    QByteArray bt;
    bt.resize(tcpSocket->bytesAvailable());
    tcpSocket->read(bt.data(),bt.size());

    log("收到数据");

    //打印出数据
    qDebug()<<bt;

}

void Gobang_Network::onDisplayError(QAbstractSocket::SocketError e)
{
    //err();
    qDebug()<<"SocketError:"<<e<<endl
               <<tcpSocket->errorString();
}

uint8_t Gobang_Network::linkSever()
{
    //清除所有连接
    tcpSocket->abort();

    //连接服务端
    tcpSocket->connectToHost(host, post);
}

uint8_t Gobang_Network::sendBuff(uint8_t *buff, int len)
{
    log("%s---%d", buff, len);

    //tcpSocket->flush();//清空缓冲区
    tcpSocket->write((const char *)buff, len);

    return 1;
}

uint8_t Gobang_Network::sendString(QString str)
{

    QByteArray ba = str.toLatin1(); // must
    char *u8 = ba.data();

    return this->sendBuff((uint8_t *)u8, ba.length());
}

void Gobang_Network::connected()
{
    qDebug() << "连接成功";
    tcpSocket->write("Hello from TCP Client!");
}
