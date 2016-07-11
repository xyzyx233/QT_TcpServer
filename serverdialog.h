#ifndef DIALOG_H
#define DIALOG_H
#include "tcp.h"
#include <QDialog>
#include<QtNetwork/QTcpSocket>
#include<QtNetwork/QTcpServer>
#include <QTimer>
#include "fileop.h"

namespace Ui {
class ServerDialog;
}

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServerDialog(QWidget *parent = 0);
    ~ServerDialog();

private:
    Ui::ServerDialog *ui;
    Tcp *tcp,*tcp1;
    fileop question;
    QString path;
private slots:
    void solData(QString);
    void on_send_clicked();
    void showcontent(QStringList,int);
    void on_selpath_clicked();
};

#endif // DIALOG_H
