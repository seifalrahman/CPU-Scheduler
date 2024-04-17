#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"addprocess.h"
#include"ui_addprocess.h"
#include"algorithm"
#include<PCB.h>
Scheduler CurrentScheduler;


bool LiveScheduling =false ;
bool Preemptive = false ;


std::vector<PCB> SJFScheduler (std::vector<PCB> input){
    int n =input.size() ;
    std::vector<PCB> NEWReadyQueue ;
    for (PCB process : input ){
        NEWReadyQueue.push_back(process) ;
    }

    for(int i =0 ; i< n-1 ;i++){
        for(int j=0; j<n-i-1;j++){
            if(NEWReadyQueue[j].timeleft>NEWReadyQueue[j+1].timeleft){
                std::swap(NEWReadyQueue[j] ,NEWReadyQueue[j+1]) ;
            }
        }
    }
    return NEWReadyQueue ;

}


std::vector<PCB> PriorityScheduler (std::vector<PCB> input){
    int n =input.size() ;
    std::vector<PCB> NEWReadyQueue ;
    for (PCB process : input ){
        NEWReadyQueue.push_back(process) ;
    }

    for(int i =0 ; i< n-1 ;i++){
        for(int j=0; j<n-i-1;j++){
            if(NEWReadyQueue[j].priority>NEWReadyQueue[j+1].priority){
                std::swap(NEWReadyQueue[j] ,NEWReadyQueue[j+1]) ;
            }
        }
    }
    return NEWReadyQueue ;

}

std::vector<PCB> FCFSScheduler (std::vector<PCB> input){
    int n =input.size() ;
    std::vector<PCB> NEWReadyQueue ;
    for (PCB process : input ){
        NEWReadyQueue.push_back(process) ;
    }

    for(int i =0 ; i< n-1 ;i++){
        for(int j=0; j<n-i-1;j++){
            if(NEWReadyQueue[j].ArrivalTime<NEWReadyQueue[j+1].ArrivalTime){
                std::swap(NEWReadyQueue[j] ,NEWReadyQueue[j+1]) ;
            }
        }
    }
    return NEWReadyQueue ;

}



void ShortTermScheduler (void){
    if(CurrentScheduler==SJF){
        READYQUEUE=SJFScheduler(READYQUEUE) ;

    }else if(CurrentScheduler==PRIORITY_BASED) {
        READYQUEUE=PriorityScheduler(READYQUEUE);

    }else if (CurrentScheduler ==FCFS){

    }
}



void LongTermScheduler (int i ){
    int flag=0 ;
    for (int j=0 ; j<JOBQUEUE.size() ; j++){
        if (JOBQUEUE[j].ArrivalTime==i){
            READYQUEUE.push_back(JOBQUEUE[j]) ;
            JOBQUEUE.erase(JOBQUEUE.begin() + j);
            j--;
            flag=1;
        }
    }

    if(flag==1 && Preemptive==true ){
        ShortTermScheduler();
    }

}


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

void MainWindow::on_pushButton_clicked()
{
    static addprocess add ;
    if(CurrentScheduler==FCFS ||CurrentScheduler == ROUND_ROBIN ){
        add.ui->Prioritynum->setVisible(false);
        add.ui->label->setVisible(false)      ;

    }
    add.show()            ;
}


void MainWindow::on_checkBox_toggled(bool checked)
{
    LiveScheduling=checked ;
}


void MainWindow::on_PreemptiveBool_toggled(bool checked)
{

    Preemptive =checked ;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    CurrentScheduler =(Scheduler)index;
    if(CurrentScheduler==FCFS ||CurrentScheduler == ROUND_ROBIN ){
        this->ui->PreemptiveBool->setEnabled(false) ;
    }else{
        this->ui->PreemptiveBool->setEnabled(true) ;
    }
}

//RUN BUTTON   qDebug() <<      ;
void MainWindow::on_pushButton_2_clicked()
{
    if(LiveScheduling==false){


        for(int t=0 ;  !JOBQUEUE.empty() || ! READYQUEUE.empty() ;t++){

            LongTermScheduler(t) ;

            if(READYQUEUE.size()==0){
                //DISPLAY IDLE
                 qDebug() <<   "0"   ;
            }else{
                for(int j=0 ;j<READYQUEUE.size() ;j++ ){

                    if(READYQUEUE[j].timeleft!=0){
                        READYQUEUE[j].timeleft--;
                        qDebug() <<" "<<   READYQUEUE[j].id<<" "   ;

                        //DISPLAY ONE TIME UNIT OF THE PROCESS EXEC
                        break;
                    }else if(READYQUEUE[j].timeleft==0){


                        READYQUEUE.erase(READYQUEUE.begin() + j);
                        j--;
                        ShortTermScheduler();

                    }

                }
            }




        }
    }else{


    }
}

