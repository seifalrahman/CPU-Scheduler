/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QCheckBox *PreemptiveBool;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(650, 468, 101, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(630, 530, 141, 29));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(530, 30, 263, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        checkBox = new QCheckBox(gridLayoutWidget);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        PreemptiveBool = new QCheckBox(gridLayoutWidget);
        PreemptiveBool->setObjectName("PreemptiveBool");

        gridLayout->addWidget(PreemptiveBool, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Scheduler Type ", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Live Scheduling", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "SJF", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Priority based", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "FCFS", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Round Robin", nullptr));

        PreemptiveBool->setText(QCoreApplication::translate("MainWindow", "Preemptive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
