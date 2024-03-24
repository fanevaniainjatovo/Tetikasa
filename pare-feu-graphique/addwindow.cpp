#include "addwindow.h"
#include "ui_addwindow.h"
#include <QComboBox>
#include <QVBoxLayout>
#include <QCheckBox>
#include <stdlib.h>
#include <vector>
#include <string>
#include <QLineEdit>
#include <QSpinBox>
#include <QApplication>
#include <QObject>
#include <QDebug>
#include <QPushButton>

using namespace std;
AddWindow::AddWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
    biface=0;
    bprot=0;
    bnport=0;bport=0;
    bmac=0;
    bip=0;

}

AddWindow::~AddWindow()
{
    delete ui;
}


void AddWindow::on_checkBox_stateChanged(int arg1)
{

    if(arg1 == Qt::Checked){

        QVBoxLayout *layout=new QVBoxLayout(ui->widget_5);
        prot=new QComboBox(ui->widget_5);
        checkport=new QCheckBox("Port",ui->widget_5);

        bprot=1;

        prot->addItem("udp");
        prot->addItem("tcp");
        prot->addItem("icmp");

        layout->addWidget(prot);
        layout->addWidget(checkport);

        strprot=prot->currentText();

        QObject::connect(checkport,&QCheckBox::stateChanged,this,&AddWindow::on_checkBox_5_stateChanged);
        ui->widget_5->setLayout(layout);

        ui->widget_5->show();
    }

    else{


        QObjectList children = ui->widget_5->children();
        for(QObject* child : children){
            child->deleteLater();
        }

        QObjectList children5 = ui->widget_6->children();
        for(QObject* child : children5){
            child->deleteLater();
        }

        QObjectList children6 = ui->widget_7->children();
        for(QObject* child : children6){
            child->deleteLater();
        }
        bprot=0;
        strprot="";
    }

}

vector <string> splita(string line,string sep){

        vector <string> elmt;

        size_t deb=0;
        size_t fin=0;

        for(int i=0;i<3;i++){
                fin=line.find(sep,deb);
                elmt.push_back(line.substr(deb,fin-deb));
                deb=fin+1;
        }

        return elmt;
}

void AddWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        iface=new QComboBox(ui->widget_4);
        QVBoxLayout *layout=new QVBoxLayout(ui->widget_4);

        biface=1;

        FILE* f=popen("ifconfig","r");
        char result[200];
        string cmd;
        vector <string>t;

        while(fgets(result,200,f)){
                 string tmp(result);
                 cmd+=tmp;
        }

        t=splita(cmd,"\n\n");
        char a[3][20];
        for(int i=0;i<t.size();i++){
            sscanf(t[i].c_str(),"\n%[^:]:",a[i]);
            iface->addItem(QString::fromStdString(a[i]));
        }

        striface=iface->currentText();
        layout->addWidget(iface);
        ui->widget_4->setLayout(layout);

        ui->widget_4->show();
    }

    else{

        QObjectList children = ui->widget_4->children();
        for(QObject* child : children){
            child->deleteLater();
        }
        striface="";
        biface=0;
    }

}


void AddWindow::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        mac=new QLineEdit(ui->widget_3);
        QVBoxLayout *layout=new QVBoxLayout(ui->widget_3);

        bmac=1;

        strmac=mac->text();
        qDebug() << strmac;
        layout->addWidget(mac);
        ui->widget_3->setLayout(layout);

        ui->widget_3->show();
    }

    else{

        QObjectList children = ui->widget_3->children();
        for(QObject* child : children){
            child->deleteLater();
        }
        strmac="";
        bmac=0;
    }

}

void AddWindow::on_checkBox_4_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        ip=new QLineEdit(ui->widget_13);
        QVBoxLayout *layout=new QVBoxLayout(ui->widget_13);
        destIP=new QComboBox(ui->widget_13);

        bip=1;

        destIP->addItem("destination");
        destIP->addItem("source");

        optip=destIP->currentText();
        strip=ip->text();
        layout->addWidget(destIP);
        layout->addWidget(ip);
        ui->widget_13->setLayout(layout);
        ui->widget_13->show();
    }

    else{

        QObjectList children = ui->widget_13->children();
        for(QObject* child : children){
            child->deleteLater();
        }
        strip="";
        bip=0;
    }
}

void AddWindow::on_checkBox_5_stateChanged(int arg1){

    if(arg1 == Qt::Checked){

        nport=new QSpinBox(ui->widget_7);
        QVBoxLayout* layout=new QVBoxLayout(ui->widget_7);
        QPushButton* but=new QPushButton("valider");
        QPushButton* but1=new QPushButton("effacer");
        destPort=new QComboBox(ui->widget_7);

        bnport=1;
        destPort->addItem("destination");
        destPort->addItem("source");

        nport->setMinimum(1);
        nport->setMaximum(10);

        optport=destPort->currentText();
        int np=nport->value();

        layout->addWidget(destPort);
        layout->addWidget(nport);
        layout->addWidget(but);
        layout->addWidget(but1);

        QObject::connect(but,&QPushButton::clicked,this,&AddWindow::on_valider_nport);
        QObject::connect(but1,&QPushButton::clicked,this,&AddWindow::on_effacer_nport);

        ui->widget_7->setLayout(layout);
        ui->widget_7->show();

    }

    else{
        QObjectList children = ui->widget_7->children();
        for(QObject* child : children){
            child->deleteLater();
        }
        bport=0;
    }

}

void AddWindow::on_valider_nport(int np){

    np=nport->value();
    QVBoxLayout* layout=new QVBoxLayout(ui->widget_6);
    spinport=(QSpinBox**)malloc(sizeof(QSpinBox*)*np);
    strport=(QString*)malloc(sizeof(QString)*np);
    for(int i=0;i<np;i++){
        //spinport[i]->setMinimum(1);
        spinport[i]=new QSpinBox(ui->widget_6);
        //strport[i]=spinport[i]->value();
        layout->addWidget(spinport[i]);
    }

    ui->widget_6->setLayout(layout);
    ui->widget_6->show();

}

void AddWindow::on_effacer_nport(){

    QObjectList children = ui->widget_6->children();
    for(QObject* child : children){
        child->deleteLater();
    }
    //strport=(QString*)malloc(sizeof(QString)*np);
}

void AddWindow::on_pushButton_clicked()
{
    //TARGET ET POLICY
    this->cmd="sudo iptables";
    this->cmd+=" -j "+ui->comboBox->currentText();
    this->cmd+=" -A "+ui->comboBox_2->currentText();

    //protocole
    if(bprot==1){
    if(!prot->currentText().isEmpty()){
        this->cmd+=" -p "+prot->currentText();
    }
    }

    //port
    if(bnport==1 && bport==1){
    if(nport->value()!=0){
        int np=nport->value();
        if(np==1){
            if(destPort->currentText()=="destination"){
               this->cmd+=" --dport "+QString::number(spinport[0]->value());
            }

            else{
               this->cmd+=" --sport "+QString::number(spinport[0]->value());
            }
        }
        else if(np>1){
            QString multiport;
             for(int i=0;i<np;i++){
                 qDebug() << spinport[i]->value();
                if(i!=np-1){
                     multiport+=QString::number(spinport[i]->value())+",";
                }
                else{
                    multiport+=QString::number(spinport[i]->value());
                }
             }
            if(destPort->currentText()=="destination"){
                this->cmd+=" -m multiport --dports "+multiport;
            }
            else{
                this->cmd+=" -m multiport --sports "+multiport;
            }
        }
    }
    }
    //adresse mac
    if(bmac==1){
    if(!mac->text().isEmpty()){
        this->cmd+=" -m mac --mac-source "+mac->text();
    }
    }

    //adresse ip
    if(bip==1){
    if(!ip->text().isEmpty()){
        if(optip=="destination"){
            this->cmd+=" -d "+ip->text();
        }
        else{
            this->cmd+=" -s "+ip->text();
        }
    }
    }

    if(biface==1){
    if(!iface->currentText().isEmpty()){
       QString opt=ui->comboBox_2->currentText();
        if(opt=="INPUT"){
            this->cmd+=" -i "+iface->currentText();
       }
       else{
            this->cmd+=" -o "+iface->currentText();
       }
    }
    }

    qDebug() << this->cmd;
    QByteArray byteArray=this->cmd.toUtf8();
    const char* utf8str=byteArray.constData();

    system(utf8str);
    this->cmd="";

    this->close();
}
