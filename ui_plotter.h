/********************************************************************************
** Form generated from reading UI file 'plotter.ui'
**
** Created: Fri Dec 24 19:44:49 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTTER_H
#define UI_PLOTTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_Plotter
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QwtPlot *plotDisp;
    QHBoxLayout *horizontalLayout;
    QPushButton *exportBtn;
    QPushButton *printBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Plotter)
    {
        if (Plotter->objectName().isEmpty())
            Plotter->setObjectName(QString::fromUtf8("Plotter"));
        Plotter->resize(400, 300);
        horizontalLayout_2 = new QHBoxLayout(Plotter);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plotDisp = new QwtPlot(Plotter);
        plotDisp->setObjectName(QString::fromUtf8("plotDisp"));

        verticalLayout->addWidget(plotDisp);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        exportBtn = new QPushButton(Plotter);
        exportBtn->setObjectName(QString::fromUtf8("exportBtn"));

        horizontalLayout->addWidget(exportBtn);

        printBtn = new QPushButton(Plotter);
        printBtn->setObjectName(QString::fromUtf8("printBtn"));

        horizontalLayout->addWidget(printBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Plotter);

        QMetaObject::connectSlotsByName(Plotter);
    } // setupUi

    void retranslateUi(QDialog *Plotter)
    {
        Plotter->setWindowTitle(QApplication::translate("Plotter", "Dialog", 0, QApplication::UnicodeUTF8));
        exportBtn->setText(QApplication::translate("Plotter", "Export", 0, QApplication::UnicodeUTF8));
        printBtn->setText(QApplication::translate("Plotter", "Print", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Plotter: public Ui_Plotter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTTER_H
