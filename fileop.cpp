#include "fileop.h"

fileop::fileop(QObject *parent) : QObject(parent)
{

}
QString fileop::readfile(QString filepath){
    file=new QFile(filepath);
    if(!file->open(QFile::ReadOnly|QFile::Text)){
        qDebug()<< "读取失败\n";
        return "";
    }
    QTextStream in(file);
    QString tmp=in.readAll();
    QStringList contentlist=tmp.split("\n");
    QStringList result;
    for(int i=0;i<contentlist.length();i++){
        result<< contentlist[i].split("|")[0];
    }
    file->close();
    return tmp;
}

void fileop::writefile(QString filepath,QString a){
    file=new QFile(filepath);
    if(!file->open(QFile::WriteOnly|QFile::Truncate)){
        qDebug()<< "写入失败\n";
        return;
    }
    QTextStream out(file);
    out << a;
    file->close();
}
