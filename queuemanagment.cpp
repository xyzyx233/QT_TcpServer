#include "queuemanagment.h"

queuemanagment::queuemanagment(QObject *parent) : QObject(parent)
{
    grpres[0]=new QFile("./result/class1.txt");
    grpres[1]=new QFile("./result/class2.txt");
    grpres[2]=new QFile("./result/class3.txt");
    QStringList path;
    path << "./student/class1.txt" << "./student/class2.txt" << "./student/class3.txt";
    readstudentlist(path);
}
bool queuemanagment::Iscontent(QString a,int b){
    return grp[b].contains(a);
}
void queuemanagment::readstudentlist(QStringList path){
    for(int i=0;i<3;i++){
        QString tmp=op.readfile(path[i]);
        QStringList contentlist=tmp.split("\n");
        for(int j=0;j<contentlist.length();j++){
            grp[i]<< contentlist[j].split("|")[0];
        }
    }
}
void queuemanagment::addstudent(QString a,int b){
    student[b]<<a;
}

bool queuemanagment::selectquestion(QString a, int b, int c){
    qDebug() << b;
//    if(!grpres[b]->open(QFile::ReadOnly|QFile::Text)){
//        qDebug()<< "选题信息读取失败\n";
//        return false;
//    }
//    qDebug() << "streamnoOK";
//    QTextStream in(grpres[b]);
    grpres[b]->open(QFile::ReadOnly|QFile::Text);
    QString tmp=grpres[b]->readAll();
    grpres[b]->close();
    qDebug() << "selOK " << tmp;
    QStringList contentlist=tmp.split("\n");
    QStringList result;
    for(int i=0;i<contentlist.length();i++){
        result<< contentlist[i].split("|")[0];
    }
    if(result.contains(QString::number(c))){
        qDebug()<< "题目被选\n";
        return false;
    }
    if(!grpres[b]->open(QFile::WriteOnly|QFile::Append)){
        qDebug()<< "选题信息写入失败\n";
        return false;
    }
//    QTextStream out(grpres[b]);
    grpres[b]->write((QString::number(c)+"|"+a+"\n").toUtf8());
//    out << c << '|' << a << "\n";
//    out.flush();
    grpres[b]->close();
//    if(student[0].isEmpty()&&student[1].isEmpty()&&student[2].isEmpty()){
//        emit waitwmpty();
//    }
    return true;
}

QString queuemanagment::avaqueue(int a){
    if(!grpres[a]->open(QFile::ReadOnly|QFile::Text)){
        qDebug()<< "选题信息读取失败\n";
        return "";
    }
    QTextStream in(grpres[a]);
    QString tmp=in.readAll();
    grpres[a]->close();
    if(tmp.isEmpty()){
        return QString(QByteArray (stream));
    }
    QStringList contentlist=tmp.split("\n");
    for(int i=0;i<contentlist.length();i++){
        stream[contentlist[i].split("|")[0].toInt()]='1';
    }
    return QString(QByteArray (stream));
}

void queuemanagment::wherequestion(QString a){
    questioncontent=op.readfile(a);
    QStringList tmp1=questioncontent.split("\n");
    stream= new char(tmp1.length()+1);
    stream[1]=' ';
    stream[0]='1';
    for(int i=2;i<tmp1.length()+1;i++){
        stream[i]='0';
    }
}
QString queuemanagment::getquestioncontent(){
    return questioncontent;
}
