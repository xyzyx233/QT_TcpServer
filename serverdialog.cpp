#include "serverdialog.h"
#include "ui_serverdialog.h"
#include<QtNetwork/QTcpSocket>
#include<QtNetwork/QTcpServer>
#include <QStringList>
ServerDialog::ServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerDialog)
{
    path = QFileDialog::getOpenFileName(this, tr("Open Files"), ".", tr("TEXT Files(*.txt)"));
    Tcp::setpath(path);
    tcp1= new Tcp(this,6667);
    tcp = new Tcp(this,6666);
    ui->setupUi(this);
    connect(&question,SIGNAL(readcontent(QStringList,int)),this,SLOT(showcontent(QStringList,int)));
}

void ServerDialog::on_send_clicked()
{
}

void ServerDialog::solData(QString Data)
{
     ui->conne->append(Data);
     QStringList list = Data.split(" ");
     if(list[0] == "1")
     {
       //tcp->socket->write(QString("yes").toUtf8());
     }
}



ServerDialog::~ServerDialog()
{
    delete ui;
}
void ServerDialog::showcontent(QStringList a,int b){
    switch (b) {
    case 1:
        if(!ui->output->toPlainText().isEmpty())
            ui->output->setText("");
        for(int i=0;i<a.length();i++)
            ui->output->append(a[i]);
        break;
    case 0:
        break;
    default:
        break;
    }
}

void ServerDialog::on_selpath_clicked()
{
}
