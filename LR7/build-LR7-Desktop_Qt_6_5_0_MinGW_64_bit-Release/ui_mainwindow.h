/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtoncalc;
    QSpinBox *spinBoxn1;
    QDoubleSpinBox *doubleSpinBoxm1;
    QLabel *labeln;
    QLabel *labelm;
    QLabel *labeln_2;
    QDoubleSpinBox *doubleSpinBoxm2;
    QLabel *labelm_2;
    QSpinBox *spinBoxn2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(606, 390);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButtoncalc = new QPushButton(centralwidget);
        pushButtoncalc->setObjectName("pushButtoncalc");
        pushButtoncalc->setGeometry(QRect(240, 190, 80, 24));
        spinBoxn1 = new QSpinBox(centralwidget);
        spinBoxn1->setObjectName("spinBoxn1");
        spinBoxn1->setGeometry(QRect(200, 110, 71, 25));
        spinBoxn1->setMaximum(200);
        doubleSpinBoxm1 = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxm1->setObjectName("doubleSpinBoxm1");
        doubleSpinBoxm1->setGeometry(QRect(330, 110, 81, 25));
        doubleSpinBoxm1->setMinimum(-100000.000000000000000);
        doubleSpinBoxm1->setMaximum(100000.000000000000000);
        labeln = new QLabel(centralwidget);
        labeln->setObjectName("labeln");
        labeln->setGeometry(QRect(170, 110, 21, 16));
        labelm = new QLabel(centralwidget);
        labelm->setObjectName("labelm");
        labelm->setGeometry(QRect(290, 110, 31, 16));
        labeln_2 = new QLabel(centralwidget);
        labeln_2->setObjectName("labeln_2");
        labeln_2->setGeometry(QRect(170, 140, 21, 16));
        doubleSpinBoxm2 = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxm2->setObjectName("doubleSpinBoxm2");
        doubleSpinBoxm2->setEnabled(true);
        doubleSpinBoxm2->setGeometry(QRect(330, 140, 81, 25));
        doubleSpinBoxm2->setMinimum(-100000.000000000000000);
        doubleSpinBoxm2->setMaximum(100000.000000000000000);
        labelm_2 = new QLabel(centralwidget);
        labelm_2->setObjectName("labelm_2");
        labelm_2->setGeometry(QRect(290, 140, 31, 16));
        spinBoxn2 = new QSpinBox(centralwidget);
        spinBoxn2->setObjectName("spinBoxn2");
        spinBoxn2->setGeometry(QRect(200, 140, 71, 25));
        spinBoxn2->setMaximum(200);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 606, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtoncalc->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        labeln->setText(QCoreApplication::translate("MainWindow", "n1 =", nullptr));
        labelm->setText(QCoreApplication::translate("MainWindow", "m1 =", nullptr));
        labeln_2->setText(QCoreApplication::translate("MainWindow", "n2 =", nullptr));
        labelm_2->setText(QCoreApplication::translate("MainWindow", "m2 =", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
