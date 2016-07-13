#ifndef QUEUEMANAGMENT_H
#define QUEUEMANAGMENT_H

#include <QFile>
#include <QObject>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include <QString>
#include "fileop.h"

class queuemanagment:QObject
{
    Q_OBJECT
private:
    QFile *grpres[3];   //各组选题记录
    QStringList grp[3]; //各班人员名单
    QStringList student[3]; //各班就绪队列
    QString questioncontent;    //题目内容
    char* stream;
    fileop op;
public:
    explicit queuemanagment(QObject *parent = 0);
    bool Iscontent(QString,int);    //判断是否存在该学生
    void readstudentlist(QStringList);  //将学生信息读入程序
    void addstudent(QString,int);   //将指定学生放入相应的队列中
    bool selectquestion(QString,int,int);   //选题操作，返回值为真则成功，参数为人员信息、班级号，题号
    QString avaqueue(int); //返回可选题序列
    void wherequestion(QString);    //打开题目文件
    QString getquestioncontent();   //获取题目内容
//signals:
//    void waitwmpty();
};

#endif // QUEUEMANAGMENT_H
