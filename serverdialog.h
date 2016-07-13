#ifndef DIALOG_H
#define DIALOG_H
#include "tcp.h"
#include <QDialog>
#include<QTcpSocket>
#include<QTcpServer>
#include <QStringList>
#include <QStandardItemModel>
#include <QMessageBox>

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
//    void solData(QString);

private:
    Ui::ServerDialog *ui;
    Tcp *tcp,*tcp1;
    fileop question;
    QString path;
    QStringList selres;
    QStringList member;
private slots:
    void on_send_clicked();
    void on_selpath_clicked();
    void on_exit_clicked();
};

#endif // DIALOG_H
