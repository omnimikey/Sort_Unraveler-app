/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QSlider *verticalSlider;
    QLabel *label_Value;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 20, 91, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius: 8px;	\n"
"	border:2px solid #5A5A5A;\n"
"	color:white;\n"
"	background-color:blue;\n"
"	text-align:center;\n"
"	\n"
"\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{\n"
"	background-color:orange;\n"
"	color:yellow;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"background-color:green;\n"
"color: black;\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(50, 60, 91, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius: 8px;	\n"
"	border:2px solid #5A5A5A;\n"
"	color:white;\n"
"	background-color:blue;\n"
"	\n"
"\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{\n"
"	background-color:orange;\n"
"	color:yellow;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"background-color:green;\n"
"color: black;\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(150, 20, 91, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius: 8px;	\n"
"	border:2px solid #5A5A5A;\n"
"	color:white;\n"
"	background-color:blue;\n"
"	\n"
"\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{\n"
"	background-color:orange;\n"
"	color:yellow;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"background-color:green;\n"
"color: black;\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(150, 60, 91, 31));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        pushButton_4->setFont(font3);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius: 8px;	\n"
"	border:2px solid #5A5A5A;\n"
"	color:white;\n"
"	background-color:blue;\n"
"	\n"
"\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{\n"
"	background-color:orange;\n"
"	color:yellow;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"background-color:green;\n"
"color: black;\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(370, 20, 71, 41));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius: 8px;	\n"
"	border:2px solid #5A5A5A;\n"
"	color:black;\n"
"	background-color:red;\n"
"	\n"
"\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{\n"
"	background-color:yellow;\n"
"	color:black;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"background-color:black;\n"
"color: white;\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setEnabled(true);
        pushButton_6->setGeometry(QRect(250, 20, 91, 31));
        QFont font4;
        font4.setBold(true);
        pushButton_6->setFont(font4);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius: 8px;	\n"
"	border:2px solid #5A5A5A;\n"
"	color:white;\n"
"	background-color:blue;\n"
"	\n"
"\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{\n"
"	background-color:orange;\n"
"	color:yellow;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"background-color:green;\n"
"color: black;\n"
"}"));
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(20, 20, 22, 160));
        verticalSlider->setMaximum(100);
        verticalSlider->setValue(20);
        verticalSlider->setOrientation(Qt::Orientation::Vertical);
        verticalSlider->setInvertedAppearance(false);
        verticalSlider->setInvertedControls(false);
        verticalSlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        label_Value = new QLabel(centralwidget);
        label_Value->setObjectName("label_Value");
        label_Value->setGeometry(QRect(10, 60, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName("toolBar_2");
        MainWindow->addToolBar(Qt::ToolBarArea::BottomToolBarArea, toolBar_2);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        pushButton_6->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "BUBBLE ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "SELECTION ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Insertion ", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Merge", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "QUICK", nullptr));
        label_Value->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
