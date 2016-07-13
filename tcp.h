#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpServer>
#include <QObject>
#include <QDataStream>
#include "tcpclientsocket.h"

class Tcp : public QTcpServer
{
    Q_OBJECT
signals:
    void already(QString);
private:
    int port;
    TcpClientSocket tmp;
    static QString path;
public:
    Tcp(QObject *parent = 0,int port=0);
    QList<TcpClientSocket*> tcpClientSocketList;
    static void setpath(QString);
//    void sendtoa(QString);
//    void updateClients(QString,int);
public slots:
    void slotDisconnected(int);
protected:
    void incomingConnection(int socketDescriptor);
};

#endif // TCPSOCKET_H
