/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_Caculator;
    QAction *Quit;
    QAction *actionKula;
    QAction *actionQuit;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnSubtraction;
    QPushButton *btnMultication;
    QPushButton *btnNum1;
    QPushButton *btnClear;
    QPushButton *btnNum3;
    QPushButton *btnNum2;
    QPushButton *btnPercentage;
    QPushButton *btnNum7;
    QPushButton *btnNum8;
    QPushButton *btnDivision;
    QPushButton *btnNum9;
    QPushButton *btnNum6;
    QPushButton *btnNum5;
    QPushButton *btnNum4;
    QPushButton *btnEquality;
    QPushButton *btnNegetivity;
    QPushButton *btnAddtion;
    QPushButton *btnDecimalPoint;
    QPushButton *btnNum0;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuAuthor;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(261, 386);
        actionAbout_Caculator = new QAction(MainWindow);
        actionAbout_Caculator->setObjectName(QStringLiteral("actionAbout_Caculator"));
        Quit = new QAction(MainWindow);
        Quit->setObjectName(QStringLiteral("Quit"));
        actionKula = new QAction(MainWindow);
        actionKula->setObjectName(QStringLiteral("actionKula"));
        QIcon icon;
        icon.addFile(QStringLiteral("D:/m_37035361bb02000001ab502e70ee.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionKula->setIcon(icon);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("C:/Users/Administrator/Desktop/666.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 0, 231, 326));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(12);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnSubtraction = new QPushButton(gridLayoutWidget);
        btnSubtraction->setObjectName(QStringLiteral("btnSubtraction"));
        btnSubtraction->setMinimumSize(QSize(45, 45));
        btnSubtraction->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnSubtraction, 4, 3, 1, 1);

        btnMultication = new QPushButton(gridLayoutWidget);
        btnMultication->setObjectName(QStringLiteral("btnMultication"));
        btnMultication->setMinimumSize(QSize(45, 45));
        btnMultication->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnMultication, 3, 3, 1, 1);

        btnNum1 = new QPushButton(gridLayoutWidget);
        btnNum1->setObjectName(QStringLiteral("btnNum1"));
        btnNum1->setMinimumSize(QSize(45, 45));
        btnNum1->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnNum1, 4, 0, 1, 1);

        btnClear = new QPushButton(gridLayoutWidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setMinimumSize(QSize(45, 45));
        btnClear->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnClear, 1, 0, 1, 1);

        btnNum3 = new QPushButton(gridLayoutWidget);
        btnNum3->setObjectName(QStringLiteral("btnNum3"));
        btnNum3->setMinimumSize(QSize(45, 45));
        btnNum3->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnNum3, 4, 2, 1, 1);

        btnNum2 = new QPushButton(gridLayoutWidget);
        btnNum2->setObjectName(QStringLiteral("btnNum2"));
        btnNum2->setMinimumSize(QSize(45, 45));
        btnNum2->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnNum2, 4, 1, 1, 1);

        btnPercentage = new QPushButton(gridLayoutWidget);
        btnPercentage->setObjectName(QStringLiteral("btnPercentage"));
        btnPercentage->setMinimumSize(QSize(45, 45));
        btnPercentage->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnPercentage, 1, 2, 1, 1);

        btnNum7 = new QPushButton(gridLayoutWidget);
        btnNum7->setObjectName(QStringLiteral("btnNum7"));
        btnNum7->setMinimumSize(QSize(45, 45));
        btnNum7->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnNum7, 2, 0, 1, 1);

        btnNum8 = new QPushButton(gridLayoutWidget);
        btnNum8->setObjectName(QStringLiteral("btnNum8"));
        btnNum8->setMinimumSize(QSize(45, 45));
        btnNum8->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnNum8, 2, 1, 1, 1);

        btnDivision = new QPushButton(gridLayoutWidget);
        btnDivision->setObjectName(QStringLiteral("btnDivision"));
        btnDivision->setMinimumSize(QSize(45, 45));
        btnDivision->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnDivision, 2, 3, 1, 1);

        btnNum9 = new QPushButton(gridLayoutWidget);
        btnNum9->setObjectName(QStringLiteral("btnNum9"));
        btnNum9->setMinimumSize(QSize(45, 45));
        btnNum9->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnNum9, 2, 2, 1, 1);

        btnNum6 = new QPushButton(gridLayoutWidget);
        btnNum6->setObjectName(QStringLiteral("btnNum6"));
        btnNum6->setMinimumSize(QSize(45, 45));
        btnNum6->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnNum6, 3, 2, 1, 1);

        btnNum5 = new QPushButton(gridLayoutWidget);
        btnNum5->setObjectName(QStringLiteral("btnNum5"));
        btnNum5->setMinimumSize(QSize(45, 45));
        btnNum5->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnNum5, 3, 1, 1, 1);

        btnNum4 = new QPushButton(gridLayoutWidget);
        btnNum4->setObjectName(QStringLiteral("btnNum4"));
        btnNum4->setMinimumSize(QSize(45, 45));
        btnNum4->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnNum4, 3, 0, 1, 1);

        btnEquality = new QPushButton(gridLayoutWidget);
        btnEquality->setObjectName(QStringLiteral("btnEquality"));
        btnEquality->setMinimumSize(QSize(45, 45));
        btnEquality->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnEquality, 1, 3, 1, 1);

        btnNegetivity = new QPushButton(gridLayoutWidget);
        btnNegetivity->setObjectName(QStringLiteral("btnNegetivity"));
        btnNegetivity->setMinimumSize(QSize(45, 45));
        btnNegetivity->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnNegetivity, 1, 1, 1, 1);

        btnAddtion = new QPushButton(gridLayoutWidget);
        btnAddtion->setObjectName(QStringLiteral("btnAddtion"));
        btnAddtion->setMinimumSize(QSize(45, 45));
        btnAddtion->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnAddtion, 5, 3, 1, 1);

        btnDecimalPoint = new QPushButton(gridLayoutWidget);
        btnDecimalPoint->setObjectName(QStringLiteral("btnDecimalPoint"));
        btnDecimalPoint->setMinimumSize(QSize(45, 45));
        btnDecimalPoint->setMaximumSize(QSize(45, 45));

        gridLayout->addWidget(btnDecimalPoint, 5, 2, 1, 1);

        btnNum0 = new QPushButton(gridLayoutWidget);
        btnNum0->setObjectName(QStringLiteral("btnNum0"));
        btnNum0->setMinimumSize(QSize(45, 45));
        btnNum0->setMaximumSize(QSize(90, 45));

        gridLayout->addWidget(btnNum0, 5, 0, 1, 2);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 39));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 261, 23));
        menuAuthor = new QMenu(menuBar);
        menuAuthor->setObjectName(QStringLiteral("menuAuthor"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuAuthor->menuAction());
        menuAuthor->addAction(actionKula);
        menuAuthor->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Caculator", 0));
        actionAbout_Caculator->setText(QApplication::translate("MainWindow", "About Caculator", 0));
        Quit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionKula->setText(QApplication::translate("MainWindow", "Kula", 0));
        actionKula->setShortcut(QApplication::translate("MainWindow", "Ctrl+K", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        btnSubtraction->setText(QApplication::translate("MainWindow", "-", 0));
        btnMultication->setText(QApplication::translate("MainWindow", "*", 0));
        btnNum1->setText(QApplication::translate("MainWindow", "1", 0));
        btnClear->setText(QApplication::translate("MainWindow", "AC", 0));
        btnNum3->setText(QApplication::translate("MainWindow", "3", 0));
        btnNum2->setText(QApplication::translate("MainWindow", "2", 0));
        btnPercentage->setText(QApplication::translate("MainWindow", "%", 0));
        btnNum7->setText(QApplication::translate("MainWindow", "7", 0));
        btnNum8->setText(QApplication::translate("MainWindow", "8", 0));
        btnDivision->setText(QApplication::translate("MainWindow", "\303\267", 0));
        btnNum9->setText(QApplication::translate("MainWindow", "9", 0));
        btnNum6->setText(QApplication::translate("MainWindow", "6", 0));
        btnNum5->setText(QApplication::translate("MainWindow", "5", 0));
        btnNum4->setText(QApplication::translate("MainWindow", "4", 0));
        btnEquality->setText(QApplication::translate("MainWindow", "=", 0));
        btnNegetivity->setText(QApplication::translate("MainWindow", "+/-", 0));
        btnAddtion->setText(QApplication::translate("MainWindow", "+", 0));
        btnDecimalPoint->setText(QApplication::translate("MainWindow", ".", 0));
        btnNum0->setText(QApplication::translate("MainWindow", "0", 0));
        label->setText(QApplication::translate("MainWindow", "0", 0));
        menuAuthor->setTitle(QApplication::translate("MainWindow", "Author", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
