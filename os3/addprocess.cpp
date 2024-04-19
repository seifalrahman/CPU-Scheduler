#include "addprocess.h"
#include "ui_addprocess.h"
#include <QString>
#include<cstring>
#include <PCB.h>
#include "bits/stdc++.h"

int id =0 ;

int ArrivalTime =0;
int CPUBurstTime =0 ;
int Priority =0 ;
int numProcesses=0;
int numprocess =0;
Color color ;
QString name ;
addprocess::addprocess(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addprocess)
{
    ui->setupUi(this);
}

addprocess::~addprocess()
{
    delete ui;
}

void addprocess::on_Prioritynum_valueChanged(int arg1)
{

    Priority=arg1 ;
}


void addprocess::on_CPUBurstTimenum_valueChanged(int arg1)
{
    CPUBurstTime=arg1 ;
}


void addprocess::on_ArrivalTimenum_valueChanged(int arg1)
{
    ArrivalTime=arg1 ;
}


void addprocess::on_ColorComboBox_currentIndexChanged(int index)
{
    color=(Color)index ;
}

/*
void addprocess::on_Addbtn_clicked()
{

    id++ ;
    PCB process ;
    name=ui->textEdit->toPlainText() ;
    process.id =id ;
    process.COLOR=color;
    process.CPUBurst=CPUBurstTime;
    process.priority=Priority;
    process.name=name;
    process.timeleft=CPUBurstTime;
    process.ArrivalTime=ArrivalTime;
    JOBQUEUE.push_back(process) ;

    numprocess++;

    if(numprocess==numProcesses){
        this->close() ;
        numprocess=0;
        for (PCB c : JOBQUEUE){
            qDebug() << c.name<<"\n"     ;
        }
    }


}*/
void addprocess::on_Addbtn_clicked()
{

    id++ ;
    PCB process ;
    name=ui->textEdit->toPlainText() ;
    process.id =id ;
    process.COLOR=color;
    process.CPUBurst=CPUBurstTime;
    process.priority=Priority;
    process.name=name;
    process.timeleft=CPUBurstTime;
    process.ArrivalTime=ArrivalTime;
    process.timeLabel =new QLabel("  Time Left: "+QString::number(process.timeleft));
    process.timeLabel->setStyleSheet("border-radius: 5px; border: 1px solid black;");
    process.timeLabel->setFixedSize(300, 50);
    JOBQUEUE.push_back(process) ;
    std :: vector <int> twotimeparameters ;
    twotimeparameters.push_back(process.ArrivalTime);
    twotimeparameters.push_back(process.CPUBurst) ;
    calculations.push_back(std::make_pair(process.name,twotimeparameters ) );
    numprocess++;


    if(numprocess==numProcesses){
        this->close() ;
        numprocess=0;
        for (PCB c : JOBQUEUE){
            qDebug() << c.name<<"\n"     ;
        }
    }
     emit someSignal(id);

}



void addprocess::on_spinBox_valueChanged(int arg1)
{
    numProcesses=arg1 ;
}



