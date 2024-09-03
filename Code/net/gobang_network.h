#ifndef GOBANG_NETWORK_H
#define GOBANG_NETWORK_H

#include <iostream>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>

#define log(fmt,...)    qDebug("\e[42m[%s] %s:%d\e[0m--"#fmt"", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define err(fmt,...)    qDebug("\e[41m[%s] %s:%d\e[0m--"#fmt"", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

class Gobang_Network: public QThread
{
public:
    Gobang_Network();

private slots:
    void onReadMessage();   //处理服务端反馈的数据
    void onDisplayError(QAbstractSocket::SocketError e);    //打印错误信息
    void connected();
private:
    uint8_t linkSever();
public:
    uint8_t sendBuff(uint8_t *buff, int len);
    uint8_t sendString(QString str);
private:
    QString host = "192.168.88.1";
    quint16 post = 3304;
    QTcpSocket* tcpSocket;  //tcp客户端

protected:
    void run();
};





#endif // GOBANG_NETWORK_H
