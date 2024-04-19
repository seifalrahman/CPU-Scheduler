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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QCheckBox *PreemptiveBool;
    QCheckBox *checkBox;
    QFrame *frame;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *clear;
    QPushButton *Stats;
    QLabel *waitLabel;
    QLabel *turnLabel;
    QPushButton *Pause;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 550, 101, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(50, 550, 101, 31));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(70, 10, 661, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(50, 0));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        PreemptiveBool = new QCheckBox(horizontalLayoutWidget);
        PreemptiveBool->setObjectName("PreemptiveBool");
        PreemptiveBool->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(PreemptiveBool);

        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName("checkBox");

        horizontalLayout->addWidget(checkBox);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 460, 721, 81));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget_2 = new QWidget(frame);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 701, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(30, 60, 741, 391));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayoutWidget = new QWidget(frame_2);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 721, 371));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        clear = new QPushButton(centralwidget);
        clear->setObjectName("clear");
        clear->setGeometry(QRect(340, 550, 91, 31));
        Stats = new QPushButton(centralwidget);
        Stats->setObjectName("Stats");
        Stats->setGeometry(QRect(430, 550, 91, 31));
        waitLabel = new QLabel(centralwidget);
        waitLabel->setObjectName("waitLabel");
        waitLabel->setGeometry(QRect(540, 550, 211, 20));
        waitLabel->setFrameShape(QFrame::Box);
        turnLabel = new QLabel(centralwidget);
        turnLabel->setObjectName("turnLabel");
        turnLabel->setGeometry(QRect(540, 570, 211, 20));
        turnLabel->setFrameShape(QFrame::Box);
        Pause = new QPushButton(centralwidget);
        Pause->setObjectName("Pause");
        Pause->setGeometry(QRect(150, 550, 91, 31));
        MainWindow->setCentralWidget(centralwidget);
        frame_2->raise();
        pushButton->raise();
        pushButton_2->raise();
        horizontalLayoutWidget->raise();
        frame->raise();
        clear->raise();
        Stats->raise();
        waitLabel->raise();
        turnLabel->raise();
        Pause->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Scheduler Type ", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "SJF", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Priority based", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "FCFS", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Round Robin", nullptr));

        PreemptiveBool->setText(QCoreApplication::translate("MainWindow", "Preemptive", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Live Scheduling", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        Stats->setText(QCoreApplication::translate("MainWindow", "Stats", nullptr));
        waitLabel->setText(QCoreApplication::translate("MainWindow", "Average Wait Time", nullptr));
        turnLabel->setText(QCoreApplication::translate("MainWindow", "Average Turn Around Time ", nullptr));
        Pause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
