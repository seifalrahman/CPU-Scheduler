#include "mainwindow.h"

#include <QApplication>
#include <PCB.h>
#include<vector>
std::vector<PCB> JOBQUEUE ;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}