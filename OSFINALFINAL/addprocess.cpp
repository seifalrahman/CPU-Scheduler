#include "addprocess.h"
#include "ui_addprocess.h"
#include <QString>
#include<cstring>
#include <PCB.h>



int id =0 ;

int ArrivalTime =0;
int CPUBurstTime =0 ;
int Priority =8 ;
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

}


void addprocess::on_spinBox_valueChanged(int arg1)
{
    numProcesses=arg1 ;
}



