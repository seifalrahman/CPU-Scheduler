#include "mainwindow.h"

#include <QApplication>
#include <PCB.h>
#include<vector>
#include "bits/stdc++.h"
std::vector<PCB> JOBQUEUE ;
std::vector<PCB> READYQUEUE ;
std::vector < std:: pair<QString , std::vector <int> > >  calculations ;
std::vector <std :: pair<QString , int > >  TurnaroundTimeVector ;
std::vector <std :: pair<QString , int > >  WaitingTimeVector ;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
