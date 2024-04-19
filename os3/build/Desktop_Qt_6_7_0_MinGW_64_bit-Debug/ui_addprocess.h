/********************************************************************************
** Form generated from reading UI file 'addprocess.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPROCESS_H
#define UI_ADDPROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addprocess
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QLabel *label_2;
    QSpinBox *CPUBurstTimenum;
    QLabel *label_4;
    QSpinBox *ArrivalTimenum;
    QLabel *label_5;
    QComboBox *ColorComboBox;
    QLabel *label;
    QSpinBox *Prioritynum;
    QLabel *label_3;
    QSpinBox *spinBox;
    QPushButton *Addbtn;

    void setupUi(QWidget *addprocess)
    {
        if (addprocess->objectName().isEmpty())
            addprocess->setObjectName("addprocess");
        addprocess->resize(795, 128);
        horizontalLayoutWidget = new QWidget(addprocess);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 30, 771, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(horizontalLayoutWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setMaximumSize(QSize(150, 30));

        horizontalLayout->addWidget(textEdit);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        CPUBurstTimenum = new QSpinBox(horizontalLayoutWidget);
        CPUBurstTimenum->setObjectName("CPUBurstTimenum");
        CPUBurstTimenum->setMinimum(1);

        horizontalLayout->addWidget(CPUBurstTimenum);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        ArrivalTimenum = new QSpinBox(horizontalLayoutWidget);
        ArrivalTimenum->setObjectName("ArrivalTimenum");

        horizontalLayout->addWidget(ArrivalTimenum);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        ColorComboBox = new QComboBox(horizontalLayoutWidget);
        ColorComboBox->addItem(QString());
        ColorComboBox->addItem(QString());
        ColorComboBox->addItem(QString());
        ColorComboBox->addItem(QString());
        ColorComboBox->addItem(QString());
        ColorComboBox->addItem(QString());
        ColorComboBox->addItem(QString());
        ColorComboBox->addItem(QString());
        ColorComboBox->setObjectName("ColorComboBox");

        horizontalLayout->addWidget(ColorComboBox);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(label);

        Prioritynum = new QSpinBox(horizontalLayoutWidget);
        Prioritynum->setObjectName("Prioritynum");
        Prioritynum->setValue(0);

        horizontalLayout->addWidget(Prioritynum);

        label_3 = new QLabel(addprocess);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 80, 141, 31));
        spinBox = new QSpinBox(addprocess);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(210, 80, 61, 29));
        spinBox->setValue(1);
        Addbtn = new QPushButton(addprocess);
        Addbtn->setObjectName("Addbtn");
        Addbtn->setGeometry(QRect(650, 80, 111, 29));

        retranslateUi(addprocess);

        QMetaObject::connectSlotsByName(addprocess);
    } // setupUi

    void retranslateUi(QWidget *addprocess)
    {
        addprocess->setWindowTitle(QCoreApplication::translate("addprocess", "Form", nullptr));
#if QT_CONFIG(accessibility)
        textEdit->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        textEdit->setHtml(QCoreApplication::translate("addprocess", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Process Name</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("addprocess", "CPU Burst Time", nullptr));
        label_4->setText(QCoreApplication::translate("addprocess", "Arrival Time", nullptr));
        label_5->setText(QCoreApplication::translate("addprocess", "     Color", nullptr));
        ColorComboBox->setItemText(0, QCoreApplication::translate("addprocess", "Red", nullptr));
        ColorComboBox->setItemText(1, QCoreApplication::translate("addprocess", "Blue", nullptr));
        ColorComboBox->setItemText(2, QCoreApplication::translate("addprocess", "Green", nullptr));
        ColorComboBox->setItemText(3, QCoreApplication::translate("addprocess", "Purple", nullptr));
        ColorComboBox->setItemText(4, QCoreApplication::translate("addprocess", "Yellow", nullptr));
        ColorComboBox->setItemText(5, QCoreApplication::translate("addprocess", "Grey", nullptr));
        ColorComboBox->setItemText(6, QCoreApplication::translate("addprocess", "White", nullptr));
        ColorComboBox->setItemText(7, QCoreApplication::translate("addprocess", "Orange", nullptr));

        label->setText(QCoreApplication::translate("addprocess", "  Priority", nullptr));
        label_3->setText(QCoreApplication::translate("addprocess", "Number of Processes", nullptr));
        Addbtn->setText(QCoreApplication::translate("addprocess", "ADD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addprocess: public Ui_addprocess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPROCESS_H
