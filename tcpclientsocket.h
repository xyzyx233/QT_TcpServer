#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include "queuemanagment.h"

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpClientSocket(QObject *parent = 0,int port=0);
    void sendtoal(QString);
    void setwherequestion(QString);
signals:
    void updateClients(QString,int);
    void disconnected(int);
    void sendtoall(QString);
protected slots:
    void dataReceived();
    void dataReceived(QString);
    void slotDisconnected();
private:
    queuemanagment q;
    int isfirst;
    int classname;
};

#endif // TCPCLIENTSOCKET_H
