#include "serverdialog.h"
#include "ui_serverdialog.h"

ServerDialog::ServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerDialog)
{
    selres<<"./result/class1.txt"<<"./result/class2.txt"<<"./result/class3.txt";

    member<<"./student/class1.txt"<<"./student/class2.txt"<<"./student/class3.txt";

    path = QFileDialog::getOpenFileName(this, tr("Open Files"), ".", tr("TEXT Files(*.txt)"));
    Tcp::setpath(path);
    tcp1= new Tcp(this,6667);
    tcp = new Tcp(this,6666);

    ui->setupUi(this);
//    connect(&question,SIGNAL(readcontent(QStringList,int)),this,SLOT(showcontent(QStringList,int)));
}


void ServerDialog::on_send_clicked()
{
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(3);
    model->setHeaderData(2,Qt::Horizontal,"成员信息");
    model->setHeaderData(0,Qt::Horizontal,"题目编号");
    model->setHeaderData(1,Qt::Horizontal,"题目");
    ui->output->setModel(model);
    ui->output->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->output->setColumnWidth(0,30);
    ui->output->setColumnWidth(1,180);
    ui->output->setColumnWidth(2,630);
    int cls=ui->comboBox->currentText().toInt();
    QStringList quescont=question.readfile(path).split("\n");
    QStringList me=question.readfile(member[cls-1]).split("\n");
    QStringList selectresult=question.readfile(selres[cls-1]).split("\n");
    if(selectresult[0]!=""){
        for(int i=0;i<selectresult.length()-1;i++){
            QString target=selectresult[i].split("|")[0];
            model->setItem(i,0,new QStandardItem(target));
            model->setItem(i,1,new QStandardItem(quescont[target.toInt()].split("|")[1]));
            model->setItem(i,2,new QStandardItem(selectresult[i].split("|")[1]));
        }
        ui->output->resizeColumnsToContents();
    }else{
        QMessageBox msg;
        msg.setText("错误");
        msg.setInformativeText("该班无人选题！");
        msg.exec();
    }
}

ServerDialog::~ServerDialog()
{
    delete ui;
}

void ServerDialog::on_selpath_clicked()
{
    QString tmp=question.readfile(path);
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal,"题号");
    model->setHeaderData(1,Qt::Horizontal,"题目名称");
    model->setHeaderData(2,Qt::Horizontal,"题目内容");
    ui->output->setModel(model);
    ui->output->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->output->setColumnWidth(0,30);
    ui->output->setColumnWidth(1,180);
    ui->output->setColumnWidth(2,630);
    QStringList ta = tmp.split("\n");
    for(int i = 0;i < ta.length()-1;i++)
    {
        QStringList now = ta[i].split("|");
        for(int j = 0;j < now.length();j++)
        {
            model->setItem(i,j,new QStandardItem(now[j]));
        }
    }
    ui->output->resizeRowsToContents();
}

void ServerDialog::on_exit_clicked()
{
    this->close();
}
