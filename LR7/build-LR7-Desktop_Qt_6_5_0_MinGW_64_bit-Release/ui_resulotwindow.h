/********************************************************************************
** Form generated from reading UI file 'resulotwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULOTWINDOW_H
#define UI_RESULOTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resulotWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelres1;
    QLabel *labelres2;
    QLabel *label;

    void setupUi(QDialog *resulotWindow)
    {
        if (resulotWindow->objectName().isEmpty())
            resulotWindow->setObjectName("resulotWindow");
        resulotWindow->resize(400, 300);
        layoutWidget = new QWidget(resulotWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 20, 331, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelres1 = new QLabel(layoutWidget);
        labelres1->setObjectName("labelres1");

        verticalLayout->addWidget(labelres1);

        labelres2 = new QLabel(layoutWidget);
        labelres2->setObjectName("labelres2");

        verticalLayout->addWidget(labelres2);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);


        retranslateUi(resulotWindow);

        QMetaObject::connectSlotsByName(resulotWindow);
    } // setupUi

    void retranslateUi(QDialog *resulotWindow)
    {
        resulotWindow->setWindowTitle(QCoreApplication::translate("resulotWindow", "Dialog", nullptr));
        labelres1->setText(QCoreApplication::translate("resulotWindow", "TextLabel", nullptr));
        labelres2->setText(QCoreApplication::translate("resulotWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("resulotWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resulotWindow: public Ui_resulotWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULOTWINDOW_H
