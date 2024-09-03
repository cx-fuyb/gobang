#ifndef TCP_H
#define TCP_H

#include <QThread>

#include <QTcpServer>
#include <QTcpSocket>

#include <iostream>
#include <QGridLayout>

#define log(fmt,...)    qDebug("\033[42m[%s] %s:%d\033[0m--"#fmt"", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define err(fmt,...)    qDebug("\033[41m[%s] %s:%d\033[0m--"#fmt"", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

class tcp: public QThread
{
private slots:
    void onReadMessage();   //处理服务端反馈的数据
    void connected();
public:
    uint8_t linkSever();
    uint8_t sendBuff(uint8_t *buff, int len);
    uint8_t sendString(QString str);
private:
    QString host = "192.168.199.1";
    //QString host = "124.71.7.74";
    quint16 post = 1234;
    QTcpSocket* tcpSocket;  //tcp客户端
public:
    tcp();
};

#endif // TCP_H
