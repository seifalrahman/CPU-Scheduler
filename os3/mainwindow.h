#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QThread"
#include <QTimer>
#include <QDebug >
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pushButton_clicked();

    void on_checkBox_toggled(bool checked);

    void on_PreemptiveBool_toggled(bool checked);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();
    void handleSignal(int value) ;
    void Timer_TimeOut_Event_Slot();
signals :
    void startOperation();

private slots:
    void on_clear_clicked();

    void on_Stats_clicked();

    void on_Pause_clicked();

private:
    Ui::MainWindow *ui;
    QThread _thread ;
    QTimer *Timer ;
};
#endif // MAINWINDOW_H
