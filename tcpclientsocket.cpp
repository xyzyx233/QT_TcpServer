#include "tcpclientsocket.h"

TcpClientSocket::TcpClientSocket(QObject *parent,int port)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
//    connect(this,SIGNAL(sendtoall(QString)),this,SLOT(dataReceived(QString)));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
    isfirst=port;
}

void TcpClientSocket::dataReceived(QString msg)
{
//        emit updateClients(msg,msg.length());
}
void TcpClientSocket::dataReceived(){
    QString name=this->readAll();
    if(isfirst==6666){
        qDebug()<<name;
        QStringList tmp=name.split(" ");
        if(q.Iscontent(tmp[0],tmp[2].toInt())){
            classname=tmp[2].toInt();
            if(classname>=3){
                return;
            }
            this->write("yes\n");
            this->write(q.getquestioncontent().toUtf8());
            this->flush();
            this->write(q.avaqueue(classname).toLatin1());
            this->flush();
            this->write("\nmdzz");
            this->flush();
        }else{
            this->write("no");
        }
        qDebug()<< "登陆 ";
    }else{
        qDebug() << "选题内容 " <<name;
        QStringList tmp=name.split("|");
        classname=tmp[2].toInt();
        qDebug() << classname;
        qDebug()<< tmp;
        if(q.selectquestion(tmp[0],classname,tmp[1].toInt())){
            this->write("OK");
            emit disconnected(this->socketDescriptor());
        }else{
            qDebug() << "error\n";
            this->write("error");
            this->write(q.avaqueue(classname).toLatin1());
            this->flush();
        }
        qDebug()<< "选题 ";
    }
}

void TcpClientSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
    qDebug()<< "tcpclient类发送信号 " <<this->socketDescriptor() ;
}

void TcpClientSocket::sendtoal(QString a){
    emit sendtoall(a);
}
void TcpClientSocket::setwherequestion(QString a){
    q.wherequestion(a);
}
