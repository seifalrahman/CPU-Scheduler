#ifndef ADDPROCESS_H
#define ADDPROCESS_H

#include <QWidget>

namespace Ui {
class addprocess;
}

class addprocess : public QWidget
{
    Q_OBJECT

public:
    explicit addprocess(QWidget *parent = nullptr);
    ~addprocess();

private slots:
    void on_Prioritynum_valueChanged(int arg1);

    void on_CPUBurstTimenum_valueChanged(int arg1);

    void on_ArrivalTimenum_valueChanged(int arg1);

    void on_ColorComboBox_currentIndexChanged(int index);

    void on_Addbtn_clicked();

    void on_spinBox_valueChanged(int arg1);

public:
    Ui::addprocess *ui;
};

#endif // ADDPROCESS_H
