#ifndef PCB_H
#define PCB_H
#include<QString>
#include <QLabel>

typedef enum{
    RED ,GREEN, BLUE , PURPLE ,YELLOW ,GREY , White ,ORANGE
} Color;
#define IDLE_TASK_PRIORITY  8
typedef  struct {
    int id ;
    int CPUBurst ;
    int timeleft ;
    int priority =IDLE_TASK_PRIORITY;
    QString name ;
    Color COLOR ;
    int ArrivalTime ;
    QLabel *timeLabel;
    int TurnAround=0;
    int WaitTime=0;
}PCB;

extern std::vector<PCB> JOBQUEUE ;
extern std::vector<PCB> READYQUEUE ;
extern std::vector < std:: pair<QString , std::vector <int> > >  calculations ;
extern std::vector <std :: pair<QString , int > >  TurnaroundTimeVector ;
extern std::vector <std :: pair<QString , int > >  WaitingTimeVector ;
extern bool LiveScheduling ;
extern bool Preemptive ;
extern int id;

typedef enum {
    SJF ,PRIORITY_BASED,FCFS,ROUND_ROBIN
}Scheduler ;
extern Scheduler CurrentScheduler ;
#endif // PCB_H
