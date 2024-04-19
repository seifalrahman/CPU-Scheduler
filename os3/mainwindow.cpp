#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"addprocess.h"
#include"ui_addprocess.h"
#include"algorithm"
#include<PCB.h>
#include<QThread>
#include "bits/stdc++.h"
Scheduler CurrentScheduler=SJF;


bool LiveScheduling =false ;
bool Preemptive = false ;
int flag=0;

int delay(int milliseconds){
    clock_t goal = milliseconds + clock();
    while(goal>clock());
    return 1;
}

void addEndPoint (QString pname , int t){
    for (auto p : calculations){
        if(p.first==pname){
            p.second.push_back(t) ;
        }
    }
}

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

    if(flag==1 && Preemptive==true || i==0 ){
        ShortTermScheduler();
    }

}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Timer = new QTimer(this) ;
    connect (Timer , SIGNAL(timeout()) ,this ,SLOT(Timer_TimeOut_Event_Slot()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    static addprocess add ;
    connect(&add, SIGNAL(someSignal(int)), this, SLOT(handleSignal(int)));
    if(CurrentScheduler==FCFS ||CurrentScheduler == ROUND_ROBIN ||CurrentScheduler==SJF){
        add.ui->Prioritynum->setVisible(false);
        add.ui->label->setVisible(false)      ;


    }else {
        add.ui->Prioritynum->setVisible(true);
        add.ui->label->setVisible(true)      ;

    }
    add.show()            ;
}

int prevID=200;
void MainWindow::handleSignal(int value) {

    if(value!=prevID){
        QHBoxLayout *hBoxLayout = new QHBoxLayout;
        QLabel *color1 = new QLabel();
        switch(JOBQUEUE.back().COLOR){
        case 0:
            color1->setStyleSheet("background-color: red;border-radius: 5px; border: 1px solid black;");
            break;
        case 1:
            color1->setStyleSheet("background-color: blue;border-radius: 5px; border: 1px solid black;");
            break;
        case 2:
            color1->setStyleSheet("background-color: green;border-radius: 5px; border: 1px solid black;");
            break;
        case 3:
            color1->setStyleSheet("background-color: purble;border-radius: 5px; border: 1px solid black;");
            break;
        case 4:
            color1->setStyleSheet("background-color: yellow;border-radius: 5px; border: 1px solid black;");
            break;
        case 5:
            color1->setStyleSheet("background-color: grey;border-radius: 5px; border: 1px solid black;");
            break;
        case 6:
            color1->setStyleSheet("background-color: white;border-radius: 5px; border: 1px solid black;");
            break;
        case 7:
            color1->setStyleSheet("background-color: orange;border-radius: 5px; border: 1px solid black;");
            break;
        }
        QLabel *label = new QLabel("  Process ID: "+QString::number(JOBQUEUE.back().id)+
                                   "  Cpu Burst:  "+QString::number(JOBQUEUE.back().CPUBurst)+
                                   "  Arrival Time:  "+QString::number(JOBQUEUE.back().ArrivalTime)+
                                   "  Priority: "+QString::number(JOBQUEUE.back().priority));
        label->setStyleSheet("border-radius: 5px; border: 1px solid black;");
        label->setFixedSize(300, 50);
        ui->formLayout->setSpacing(0);
        hBoxLayout->addWidget(label);
        hBoxLayout->addWidget(JOBQUEUE.back().timeLabel);
        hBoxLayout->addWidget(color1);
        ui->formLayout->addRow(hBoxLayout);
        qDebug() << "Received value from YourWidget:" << value;
        prevID=value;
    }
    else{

    }

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

int t=0 ;


//RUN BUTTON   qDebug() <<      ;
void MainWindow::on_pushButton_2_clicked()
{
    ui->horizontalLayout_2->setSpacing(0);
    ui->horizontalLayout_2->setAlignment(Qt::AlignLeft);
    if(LiveScheduling==false){
        Timer->stop();


        for(;  !JOBQUEUE.empty() || ! READYQUEUE.empty() ;t++){

            LongTermScheduler(t) ;

            if(READYQUEUE.size()==0){
                //DISPLAY IDLE
                QLabel *label = new QLabel("Idle", ui->centralwidget);
                //label->setGeometry(x, 430, 50, 50); // x, y, width, height
                label->setStyleSheet("color: black; background-color: white;  border: 1px solid black;");
                label->setFont(QFont("Arial", 12));
                label->setAlignment(Qt::AlignCenter);
                label->setFixedSize(50, 50);
                //label->show();
                ui->horizontalLayout_2->addWidget(label);
                qDebug() <<   "0"   ;

            }else{
                for(int j=0 ;j<READYQUEUE.size() ;j++ ){

                    if(CurrentScheduler!=ROUND_ROBIN){
                        if(READYQUEUE[j].timeleft!=0){
                            READYQUEUE[j].timeleft--;

                            qDebug() <<" "<<   READYQUEUE[j].id<<" "   ;


                            //DISPLAY ONE TIME UNIT OF THE PROCESS EXEC
                            QLabel *label = new QLabel("P"+QString::number(READYQUEUE[j].id), ui->centralwidget);
                            label->setFont(QFont("Arial", 12));
                            label->setFixedSize(50, 50);
                            label->setAlignment(Qt::AlignCenter);
                            switch(READYQUEUE[j].COLOR){
                            case 0:
                                label->setStyleSheet("background-color: red;  border: 1px solid black;");
                                break;
                            case 1:
                                label->setStyleSheet("background-color: blue;  border: 1px solid black;");
                                break;
                            case 2:
                                label->setStyleSheet("background-color: green; border: 1px solid black;");
                                break;
                            case 3:
                                label->setStyleSheet("background-color: purble; border: 1px solid black;");
                                break;
                            case 4:
                                label->setStyleSheet("color: black;background-color: yellow; border: 1px solid black;");
                                break;
                            case 5:
                                label->setStyleSheet("background-color: grey; border: 1px solid black;");
                                break;
                            case 6:
                                label->setStyleSheet("background-color: white;border: 1px solid black;");
                                break;
                            case 7:
                                label->setStyleSheet("background-color: orange;border: 1px solid black;");
                                break;
                            }
                            ui->horizontalLayout_2->addWidget(label);
                            READYQUEUE[j].timeLabel->setText(" Time Left: "+QString::number(READYQUEUE[j].timeleft )+
                                                             "   Turn Around:"+ QString::number(READYQUEUE[j].TurnAround)+
                                                             "   Wait Time:"+ QString::number(READYQUEUE[j].WaitTime));

                            if(CurrentScheduler==PRIORITY_BASED && Preemptive==true && READYQUEUE.size()>1 &&READYQUEUE[j+1].priority == READYQUEUE[j].priority ){
                                t++;

                            }else{
                                if(READYQUEUE[j].timeleft==0){

                                    addEndPoint(READYQUEUE[j].name , t+1) ;
                                    TurnaroundTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  (t+1) -READYQUEUE[j].ArrivalTime)     );
                                    WaitingTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst   )  ) ;
                                    READYQUEUE[j].TurnAround =  (t+1) -READYQUEUE[j].ArrivalTime ;
                                    READYQUEUE[j].WaitTime = ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst ;
                                    READYQUEUE[j].timeLabel->setText(" Time Left: "+QString::number(READYQUEUE[j].timeleft )+
                                                                     "   Turn Around:"+ QString::number(READYQUEUE[j].TurnAround)+
                                                                     "   Wait Time:"+ QString::number(READYQUEUE[j].WaitTime));
                                    READYQUEUE.erase(READYQUEUE.begin() + j);
                                    j--;
                                    ShortTermScheduler();

                                }
                                break;
                            }
                            if(READYQUEUE[j].timeleft==0){

                                addEndPoint(READYQUEUE[j].name , t+1) ;
                                TurnaroundTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  (t+1) -READYQUEUE[j].ArrivalTime)     );
                                WaitingTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst   )  ) ;
                                READYQUEUE[j].TurnAround =  (t+1) -READYQUEUE[j].ArrivalTime ;
                                READYQUEUE[j].WaitTime = ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst ;
                                READYQUEUE[j].timeLabel->setText(" Time Left: "+QString::number(READYQUEUE[j].timeleft )+
                                                                 "   Turn Around:"+ QString::number(READYQUEUE[j].TurnAround)+
                                                                 "   Wait Time:"+ QString::number(READYQUEUE[j].WaitTime));
                                READYQUEUE.erase(READYQUEUE.begin() + j);
                                j--;
                                ShortTermScheduler();

                            }



                        }


                    }else {
                        t++;
                        READYQUEUE[j].timeleft--;
                        qDebug() <<" "<<   READYQUEUE[j].id<<" "   ;
                        QLabel *label = new QLabel("P"+QString::number(READYQUEUE[j].id), ui->centralwidget);
                        label->setFont(QFont("Arial", 12));
                        label->setFixedSize(50, 50);
                        label->setAlignment(Qt::AlignCenter);
                        switch(READYQUEUE[j].COLOR){
                        case 0:
                            label->setStyleSheet("background-color: red;  border: 1px solid black;");
                            break;
                        case 1:
                            label->setStyleSheet("background-color: blue;  border: 1px solid black;");
                            break;
                        case 2:
                            label->setStyleSheet("background-color: green; border: 1px solid black;");
                            break;
                        case 3:
                            label->setStyleSheet("background-color: purble; border: 1px solid black;");
                            break;
                        case 4:
                            label->setStyleSheet("color: black;background-color: yellow; border: 1px solid black;");
                            break;
                        case 5:
                            label->setStyleSheet("background-color: grey; border: 1px solid black;");
                            break;
                        case 6:
                            label->setStyleSheet("background-color: white;border: 1px solid black;");
                            break;
                        case 7:
                            label->setStyleSheet("background-color: orange;border: 1px solid black;");
                            break;
                        }
                        ui->horizontalLayout_2->addWidget(label);
                        READYQUEUE[j].timeLabel->setText(" Time Left: "+QString::number(READYQUEUE[j].timeleft )+
                                                         "   Turn Around:"+ QString::number(READYQUEUE[j].TurnAround)+
                                                         "   Wait Time:"+ QString::number(READYQUEUE[j].WaitTime));
                        if(READYQUEUE[j].timeleft==0){
                            addEndPoint(READYQUEUE[j].name , t+1) ;
                            TurnaroundTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  (t+1) -READYQUEUE[j].ArrivalTime)     );
                            WaitingTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst   )  ) ;
                            READYQUEUE[j].TurnAround =  (t+1) -READYQUEUE[j].ArrivalTime ;
                            READYQUEUE[j].WaitTime = ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst ;
                            READYQUEUE[j].timeLabel->setText(" Time Left: "+QString::number(READYQUEUE[j].timeleft )+
                                                             "   Turn Around:"+ QString::number(READYQUEUE[j].TurnAround)+
                                                             "   Wait Time:"+ QString::number(READYQUEUE[j].WaitTime));
                            READYQUEUE.erase(READYQUEUE.begin() + j);
                            j--;
                        }
                        if((j==(READYQUEUE.size()-1)) && (!READYQUEUE.empty())){
                            j=-1;
                        }
                        LongTermScheduler(t);


                    }
                }
            }




        }



    }else{
        Timer->setInterval (1000) ;
        Timer->start();

    }



}




int j=0;
void MainWindow::Timer_TimeOut_Event_Slot()
{
    LongTermScheduler(t) ;

    if(READYQUEUE.size()==0){
        //DISPLAY IDLE
        QLabel *label = new QLabel("Idle", ui->centralwidget);
        //label->setGeometry(x, 430, 50, 50); // x, y, width, height
        label->setStyleSheet("color: black; background-color: white;  border: 1px solid black;");
        label->setFont(QFont("Arial", 12));
        label->setAlignment(Qt::AlignCenter);
        label->setFixedSize(50, 50);
        //label->show();
        ui->horizontalLayout_2->addWidget(label);
        qDebug() <<   "0"   ;




    }else{
        if(CurrentScheduler!=ROUND_ROBIN  && !(CurrentScheduler==PRIORITY_BASED && Preemptive==true &&READYQUEUE.size()>1 &&j!=0&&READYQUEUE[j-1].priority == READYQUEUE[j].priority    )   )
            j=0;

        for( ;j<READYQUEUE.size() ;j++ ){

            if(CurrentScheduler!=ROUND_ROBIN){

                if(READYQUEUE[j].timeleft!=0){
                    READYQUEUE[j].timeleft--;
                    qDebug() <<" "<<   READYQUEUE[j].id<<" "   ;

                    int flaggg=0;

                    //DISPLAY ONE TIME UNIT OF THE PROCESS EXEC
                    QLabel *label = new QLabel("P"+QString::number(READYQUEUE[j].id), ui->centralwidget);
                    label->setFont(QFont("Arial", 12));
                    label->setFixedSize(50, 50);
                    label->setAlignment(Qt::AlignCenter);
                    switch(READYQUEUE[j].COLOR){
                    case 0:
                        label->setStyleSheet("background-color: red;  border: 1px solid black;");
                        break;
                    case 1:
                        label->setStyleSheet("background-color: blue;  border: 1px solid black;");
                        break;
                    case 2:
                        label->setStyleSheet("background-color: green; border: 1px solid black;");
                        break;
                    case 3:
                        label->setStyleSheet("background-color: purble; border: 1px solid black;");
                        break;
                    case 4:
                        label->setStyleSheet("color: black;background-color: yellow; border: 1px solid black;");
                        break;
                    case 5:
                        label->setStyleSheet("background-color: grey; border: 1px solid black;");
                        break;
                    case 6:
                        label->setStyleSheet("background-color: white;border: 1px solid black;");
                        break;
                    case 7:
                        label->setStyleSheet("background-color: orange;border: 1px solid black;");
                        break;
                    }
                    ui->horizontalLayout_2->addWidget(label);
                    READYQUEUE[j].timeLabel->setText(" Time Left: "+QString::number(READYQUEUE[j].timeleft )+
                                                     "   Turn Around:"+ QString::number(READYQUEUE[j].TurnAround)+
                                                     "   Wait Time:"+ QString::number(READYQUEUE[j].WaitTime));
                    if(CurrentScheduler==PRIORITY_BASED && Preemptive==true &&READYQUEUE.size()>1 &&READYQUEUE[j+1].priority == READYQUEUE[j].priority){
                        j++;
                        flaggg=1;
                    }


                    // if(flaggg==0&&CurrentScheduler==PRIORITY_BASED && Preemptive==true &&READYQUEUE.size()>1 &&READYQUEUE[j+1].priority != READYQUEUE[j].priority &&j!=0 &&READYQUEUE[j-1].priority == READYQUEUE[j].priority ){
                    //     if(j==READYQUEUE.size()-1){}

                    //     j=0;
                    // }
                    if(flaggg==0 && CurrentScheduler == PRIORITY_BASED && Preemptive == true && READYQUEUE.size() > 1 && j != 0 ){
                        if(j == READYQUEUE.size()-1 && READYQUEUE[j-1].priority == READYQUEUE[j].priority){
                            j=0 ;
                        }
                        else if(READYQUEUE[j-1].priority == READYQUEUE[j].priority && READYQUEUE[j+1].priority != READYQUEUE[j].priority ){
                            j = 0;
                        }
                    }



                    if(READYQUEUE[j].timeleft==0){
                        addEndPoint(READYQUEUE[j].name , t+1) ;
                        TurnaroundTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  (t+1) -READYQUEUE[j].ArrivalTime)     );
                        WaitingTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst   )  ) ;
                        READYQUEUE[j].TurnAround =  (t+1) -READYQUEUE[j].ArrivalTime ;
                        READYQUEUE[j].WaitTime = ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst ;
                        READYQUEUE[j].timeLabel->setText(" Time Left: "+QString::number(READYQUEUE[j].timeleft )+
                                                         "   Turn Around:"+ QString::number(READYQUEUE[j].TurnAround)+
                                                         "   Wait Time:"+ QString::number(READYQUEUE[j].WaitTime));
                        READYQUEUE.erase(READYQUEUE.begin() + j);
                        if(!(CurrentScheduler==PRIORITY_BASED && Preemptive==true &&READYQUEUE.size()>1 &&READYQUEUE[j-1].priority == READYQUEUE[j].priority    ) )
                            j--;
                        ShortTermScheduler();

                    }
                    break;


                }
                if(READYQUEUE[j].timeleft==0){

                    addEndPoint(READYQUEUE[j].name , t+1) ;
                    TurnaroundTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  (t+1) -READYQUEUE[j].ArrivalTime)     );
                    WaitingTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst   )  ) ;
                    READYQUEUE[j].TurnAround =  (t+1) -READYQUEUE[j].ArrivalTime ;
                    READYQUEUE[j].WaitTime = ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst ;
                    READYQUEUE[j].timeLabel->setText(" Time Left: "+QString::number(READYQUEUE[j].timeleft )+
                                                     "   Turn Around:"+ QString::number(READYQUEUE[j].TurnAround)+
                                                     "   Wait Time:"+ QString::number(READYQUEUE[j].WaitTime));
                    READYQUEUE.erase(READYQUEUE.begin() + j);

                    if(!(CurrentScheduler==PRIORITY_BASED && Preemptive==true &&READYQUEUE.size()>1 &&READYQUEUE[j-1].priority == READYQUEUE[j].priority    ) )
                        j--;
                    ShortTermScheduler();

                }

            }else {

                READYQUEUE[j].timeleft--;
                qDebug() <<" "<<   READYQUEUE[j].id<<" "   ;
                QLabel *label = new QLabel("P"+QString::number(READYQUEUE[j].id), ui->centralwidget);
                label->setFont(QFont("Arial", 12));
                label->setFixedSize(50, 50);
                label->setAlignment(Qt::AlignCenter);
                switch(READYQUEUE[j].COLOR){
                case 0:
                    label->setStyleSheet("background-color: red;  border: 1px solid black;");
                    break;
                case 1:
                    label->setStyleSheet("background-color: blue;  border: 1px solid black;");
                    break;
                case 2:
                    label->setStyleSheet("background-color: green; border: 1px solid black;");
                    break;
                case 3:
                    label->setStyleSheet("background-color: purble; border: 1px solid black;");
                    break;
                case 4:
                    label->setStyleSheet("color: black;background-color: yellow; border: 1px solid black;");
                    break;
                case 5:
                    label->setStyleSheet("background-color: grey; border: 1px solid black;");
                    break;
                case 6:
                    label->setStyleSheet("background-color: white;border: 1px solid black;");
                    break;
                case 7:
                    label->setStyleSheet("background-color: orange;border: 1px solid black;");
                    break;
                }
                ui->horizontalLayout_2->addWidget(label);
                READYQUEUE[j].timeLabel->setText(" Time Left: "+QString::number(READYQUEUE[j].timeleft )+
                                                 "   Turn Around:"+ QString::number(READYQUEUE[j].TurnAround)+
                                                 "   Wait Time:"+ QString::number(READYQUEUE[j].WaitTime));

                if(READYQUEUE[j].timeleft==0){

                    addEndPoint(READYQUEUE[j].name , t+1) ;
                    TurnaroundTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  (t+1) -READYQUEUE[j].ArrivalTime)     );
                    WaitingTimeVector.push_back(std::make_pair(   READYQUEUE[j].name,  ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst   )  ) ;
                    READYQUEUE[j].TurnAround =  (t+1) -READYQUEUE[j].ArrivalTime ;
                    READYQUEUE[j].WaitTime = ((t+1) -READYQUEUE[j].ArrivalTime)-READYQUEUE[j].CPUBurst ;
                    READYQUEUE[j].timeLabel->setText(" Time Left: "+QString::number(READYQUEUE[j].timeleft )+
                                                     "   Turn Around:"+ QString::number(READYQUEUE[j].TurnAround)+
                                                     "   Wait Time:"+ QString::number(READYQUEUE[j].WaitTime));
                    READYQUEUE.erase(READYQUEUE.begin() + j);
                    j--;
                }
                if((j==(READYQUEUE.size()-1)) && (!READYQUEUE.empty())){
                    j=-1;
                }
                j++;
                t++;
                return ;
                //LongTermScheduler(t);


            }
        }
    }



    t++;
}

void clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (QWidget *widget = item->widget()) {
            delete widget;
        }
        delete item;

    }
}

void clearFormLayout(QFormLayout *formLayout) {
    QLayoutItem *item;
    while ((item = formLayout->takeAt(0)) != nullptr) {
        if (QWidget *widget = item->widget()) {
            delete widget;
        } else if (QLayout *layout = item->layout()) {
            clearLayout(layout); // Recursively clear nested layouts
        }
        delete item;
    }
}

void MainWindow::on_clear_clicked()
{
    t=0;
    j=0;
    id=0;
    READYQUEUE.clear();
    JOBQUEUE.clear() ;
    calculations.clear() ;
    TurnaroundTimeVector.clear() ;
    WaitingTimeVector.clear() ;
    clearLayout(ui->horizontalLayout_2);
    clearFormLayout(ui->formLayout);
}

void MainWindow::on_Stats_clicked()
{
    float averageWait=0;
    float averageTurn=0;

    for(auto x:TurnaroundTimeVector){
        averageTurn += x.second;

    }
    averageTurn = averageTurn / (float)TurnaroundTimeVector.size();

    for(auto x:WaitingTimeVector){
        averageWait += x.second;

    }
    averageWait = averageWait / (float) WaitingTimeVector.size();

    ui->turnLabel->setText("Average Turn Around Time = "+QString::number(averageTurn));
    ui->waitLabel->setText("Average Wait Time              = "+QString::number(averageWait));
}


void MainWindow::on_Pause_clicked()
{
    Timer->stop();
}

