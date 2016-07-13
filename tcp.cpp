#include "tcp.h"
#include <QIODevice>

QString Tcp::path;

Tcp::Tcp(QObject *parent,int port)
    :QTcpServer(parent)
{
    this->port=port;
    listen(QHostAddress::Any,port);
}
void Tcp::incomingConnection(int socketDescriptor)
{
    TcpClientSocket *tcpClientSocket=new TcpClientSocket(this,port);
//    connect(tcpClientSocket,SIGNAL(updateClients(QString,int)),this,SLOT(updateClients(QString,int)));
    connect(tcpClientSocket,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));
    tcpClientSocket->setSocketDescriptor(socketDescriptor);
    tcpClientSocket->setwherequestion(path);
    tcpClientSocketList.append(tcpClientSocket);
    qDebug()<<"connected";
}
void Tcp::slotDisconnected(int descriptor)
{
    qDebug() << "tcp类发送信号 " <<descriptor;
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            tcpClientSocketList.removeAt(i);
//            return;
        }
    }
}
//void Tcp::updateClients(QString msg,int length)
//{
//    int x=length;
//    for(int i=0;i<tcpClientSocketList.count();i++)
//    {
//        QTcpSocket *item = tcpClientSocketList.at(i);
//        item->write(msg.toUtf8());
//    }
//}

void Tcp::setpath(QString a){
    Tcp::path=a;
}
