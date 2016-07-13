#ifndef FILEOP_H
#define FILEOP_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QStringList>
#include <QString>

class fileop : public QObject
{
    Q_OBJECT
public:
    explicit fileop(QObject *parent = 0);
    QString readfile(QString);  //参数为路径和模式
    void writefile(QString,QString);    //参数为路径和内容
public slots:
private:
    QFile* file;
};

#endif // FILEOP_H
