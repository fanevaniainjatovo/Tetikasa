#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <string>
#include <QDebug>
#include "addwindow.h"
#include <QHBoxLayout>
#include <string.h>
#include <QComboBox>
#include <ctype.h>
#include <QLineEdit>
#include <QString>

using namespace std;

vector <string> split(string line,string sep);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

vector <string> split(string line,string sep){

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

void MainWindow::afficheTab(int entry){

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    FILE* f=popen("sudo iptables --line-number -L","r");
    char result[200];
    string cmd;
    vector <string>t;

    while(fgets(result,200,f)){
            string tmp(result);
            cmd+=tmp;
   }

   string line;
   char numero[6];
   char target[10];QComboBox* target1=new QComboBox(this);
   char prot[10];QComboBox* prot1=new QComboBox(this);
   char opt[10];
   char source[20]; QLineEdit* source1=new QLineEdit();
   char destination[20];QLineEdit* dest1=new QLineEdit();
   char details[30];

   t=split(cmd,"\n\n");
   istringstream iss(t[entry]);

   ui->tableWidget->setColumnWidth(5,150);
   ui->tableWidget->setColumnWidth(6,200);
   ui->tableWidget->setColumnWidth(4,150);

   if(entry!=0){
        getline(iss,line);
   }

   getline(iss,line);
   ui->label_2->setText(QString::fromStdString(line));

   for(int i=0;getline(iss,line);i++){
           strcpy(details,"");
           sscanf(line.c_str(),"%s %s %s %s %s %s %[^\n]",numero,target,prot,opt,source,destination,details);
           ui->tableWidget->insertRow(i);
           QTableWidgetItem* item=new QTableWidgetItem(QString::fromStdString(numero));
           ui->tableWidget->setItem(i,0,item);


           if(i==this->mod){

                target1->addItem("ACCEPT");
                target1->addItem("DROP");
                target1->addItem("REJECT");
                ui->tableWidget->setCellWidget(i,1,target1);

                prot1->addItem("udp");
                prot1->addItem("tcp");
                prot1->addItem("icmp");
                prot1->addItem("all");
                ui->tableWidget->setCellWidget(i,2,prot1);

                ui->tableWidget->setCellWidget(i,4,source1);

                ui->tableWidget->setCellWidget(i,5,dest1);

           }

           else{
                QTableWidgetItem* item1=new QTableWidgetItem(QString::fromStdString(target));
                ui->tableWidget->setItem(i,1,item1);

                QTableWidgetItem* item2=new QTableWidgetItem(QString::fromStdString(prot));
                ui->tableWidget->setItem(i,2,item2);
           }

                QTableWidgetItem* item3=new QTableWidgetItem(QString::fromStdString(opt));
                ui->tableWidget->setItem(i,3,item3);

           if(i!=this->mod){
                QTableWidgetItem* item4=new QTableWidgetItem(QString::fromStdString(source));
                ui->tableWidget->setItem(i,4,item4);

                QTableWidgetItem* item5=new QTableWidgetItem(QString::fromStdString(destination));
                ui->tableWidget->setItem(i,5,item5);
           }


           if(i!=0){
              QTableWidgetItem* item6=new QTableWidgetItem(QString::fromStdString(details));
              ui->tableWidget->setItem(i,6,item6);
           }
           else{
               QTableWidgetItem* item6=new QTableWidgetItem(QString::fromStdString("Details"));
               ui->tableWidget->setItem(i,6,item6);
           }

           if(i!=0 && i!=this->mod){
            QPushButton* modify=new QPushButton("Modify");
            QPushButton* remove=new QPushButton("Remove");

            QObject::connect(remove,&QPushButton::clicked,[this,entry,numero](){

                string a="sudo iptables -D ";
                string chain=(entry==0)?"INPUT ":(entry==2)?"OUTPUT ":"FORWARD ";

                //qDebug() << QString::fromStdString((a+chain+numero));
                system((a+chain+numero).c_str());
                this->afficheTab(entry);

            });

            QObject::connect(modify,&QPushButton::clicked,[this,entry,numero](){

                this->mod=atoi(numero);
                this->afficheTab(entry);


            });

            ui->tableWidget->setCellWidget(i,7,modify);
            ui->tableWidget->setCellWidget(i,8,remove);

         }

           else if(i==this->mod){
               QPushButton* sendMod=new QPushButton("Valider les modifications");
               QObject::connect(sendMod,&QPushButton::clicked,[this,target1,prot1,entry,source1,dest1,numero](){

                   this->tg=target1->currentText().toStdString();
                   this->prt=prot1->currentText().toStdString();
                   this->src=source1->text().toStdString();
                   this->dest=dest1->text().toStdString();

                   string chain=(entry==0)?"INPUT ":(entry==2)?"OUTPUT ":"FORWARD ";
                   string tmp="sudo iptables -R "+chain+numero+" -j "+tg+" -s "+src+" -d "+dest;

                   system(tmp.c_str());
                   this->mod=-1;
                   afficheTab(entry);


               });

           ui->tableWidget->setCellWidget(i,7,sendMod);
           }

    }

}

void MainWindow::on_pushButton_clicked()
{
   afficheTab(0);
}

void MainWindow::on_pushButton_2_clicked()
{
   afficheTab(1);
}

void MainWindow::on_pushButton_3_clicked()
{
   afficheTab(2);
}

void MainWindow::on_pushButton_4_clicked()
{
    AddWindow* win=new AddWindow();
    win->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    string chain=ui->comboBox_2->currentText().toStdString();
    string action=ui->comboBox->currentText().toStdString();
    string def="sudo iptables -P "+chain+" "+action;/*
    QByteArray byteArray=QString::fromStdString(default).toUtf8();
    const char* utf8str=byteArray.constData();
*/
    system(def.c_str());
}
