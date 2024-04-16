#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"addprocess.h"
#include"ui_addprocess.h"

#include<PCB.h>
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
    add.show()            ;
}
bool LiveScheduling =true ;
bool Preemptive = true ;

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
    Scheduler CurrentScheduler =(Scheduler)index;
}

//RUN BUTTON
void MainWindow::on_pushButton_2_clicked()
{

}

