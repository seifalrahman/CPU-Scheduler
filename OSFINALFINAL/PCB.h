#ifndef PCB_H
#define PCB_H
#include<QString>

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
}PCB;

extern std::vector<PCB> JOBQUEUE ;
extern std::vector<PCB> READYQUEUE ;



extern bool LiveScheduling ;
extern bool Preemptive ;

typedef enum {
    SJF ,PRIORITY_BASED,FCFS,ROUND_ROBIN
}Scheduler ;
extern Scheduler CurrentScheduler ;
#endif // PCB_H
