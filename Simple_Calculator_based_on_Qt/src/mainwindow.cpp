#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QMenubar>
#include<QAction>
#include<QTimer>
#include<QDialog>
#include"dialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentAction(NoAction),
    isEmpty(true)
{
    ui->setupUi(this);

    connect(ui->btnClear,SIGNAL(clicked(bool)),this,SLOT(clear()));
    connect(ui->btnNegetivity,SIGNAL(clicked(bool)),this,SLOT(negativeClicked()));
    connect(ui->btnPercentage,SIGNAL(clicked(bool)),this,SLOT(percentageClicked()));
    connect(ui->btnDecimalPoint,SIGNAL(clicked(bool)),this,SLOT(decimalPointClicked()));
    connect(ui->btnEquality,SIGNAL(clicked(bool)),this,SLOT(btnEqualityClicked()));

    connect(ui->btnAddtion,SIGNAL(clicked(bool)),this,SLOT(actionChanged()));
    connect(ui->btnSubtraction,SIGNAL(clicked(bool)),this,SLOT(actionChanged()));
    connect(ui->btnMultication,SIGNAL(clicked(bool)),this,SLOT(actionChanged()));
    connect(ui->btnDivision,SIGNAL(clicked(bool)),this,SLOT(actionChanged()));

    connect(ui->btnNum0,SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum1,SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum2,SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum3,SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum4,SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum5,SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum6,SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum7,SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum8,SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum9,SIGNAL(clicked(bool)),this,SLOT(inputNumber()));

    connect(ui->actionQuit,SIGNAL(triggered(bool)),this,SLOT(on_actionQuit_triggered()));
    connect(ui->actionKula,SIGNAL(triggered(bool)),this,SLOT(on_actionKula_triggered()));


    statusBar()->showMessage("TestMsg",3000);

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::clear()
{
    if(ui->btnClear->text()=="AC")
    {
        currentAction = NoAction;
        statusBar()->showMessage("cleared",3000);
        currentNumber="0";
        lastNumber = "0";
        isEmpty = true;

    }
    else if(ui->btnClear->text()=="C"){

        currentNumber = "0";
        isEmpty = true;
        ui->btnClear->setText("AC");
        statusBar()->showMessage("Screen clear!",2500);
}
         displayNumber();
}

void MainWindow::actionChanged()
{
    QPushButton *currentButton = qobject_cast<QPushButton*>(this->sender());
    if(currentButton)
    {
        isEmpty = false;
        if(currentButton == ui->btnAddtion)
        {
            currentAction = AddtionFlag;
            statusBar()->showMessage("Input +",3000);
        }
        else if(currentButton == ui->btnSubtraction)
        {
            currentAction = SubtractionFlag;
            statusBar()->showMessage("Input -",3000);
        }
        else if(currentButton == ui->btnMultication)
        {
            currentAction = MultiplicationFlag;
            statusBar()->showMessage("Input *",3000);
        }
        else if(currentButton == ui->btnDivision)
        {
            currentAction = DivisionFlag;
            statusBar()->showMessage("Input ÷",3000);
        }
        else{
            currentAction = NoAction;
        }
    }

}

void MainWindow::inputNumber()
{
    QPushButton *currentButton = qobject_cast<QPushButton *>(this->sender());

    if(currentButton)
    {
        ui->btnClear->setText("C");
        if(!isEmpty)
        {
            lastNumber = currentNumber;
            currentNumber.clear();
            isEmpty = true;
        }
        if(currentNumber =="0")
        {
            currentNumber.clear();
        }

        if(currentButton == ui->btnNum0)
        {
            currentNumber.append("0");
            statusBar()->showMessage("It's 0",3000);
        }
        if(currentButton == ui->btnNum1)
        {
            currentNumber.append("1");
            statusBar()->showMessage("It's 1",3000);
        }
        if(currentButton == ui->btnNum2)
        {
            currentNumber.append("2");
            statusBar()->showMessage("It's 2",3000);
        }
        if(currentButton == ui->btnNum3)
        {
            currentNumber.append("3");
            statusBar()->showMessage("It's 3",3000);
        }
        if(currentButton == ui->btnNum4)
        {
            currentNumber.append("4");
            statusBar()->showMessage("It's 4",3000);
        }
        if(currentButton == ui->btnNum5)
        {
            currentNumber.append("5");
            statusBar()->showMessage("It's 5",3000);
        }if(currentButton == ui->btnNum6)
        {
            currentNumber.append("6");
            statusBar()->showMessage("It's 6",3000);
        }if(currentButton == ui->btnNum7)
        {
            currentNumber.append("7");
            statusBar()->showMessage("It's 7",3000);
        }if(currentButton == ui->btnNum8)
        {
            currentNumber.append("8");
            statusBar()->showMessage("It's 8",3000);
        }if(currentButton == ui->btnNum9)
        {
            currentNumber.append("9");
            statusBar()->showMessage("It's 9",3000);
        }

    displayNumber();
}
}

void MainWindow::displayNumber()
{
    ui->label->setText(currentNumber);
}

void MainWindow::negativeClicked()
{
    if(!isEmpty||(currentNumber.size() == 0))
    {
        currentNumber ="0";
        isEmpty = true;
    }
    else{

        if(currentNumber.at(0) == '-')
        {
            currentNumber.remove(0,1);
        }
        else{
            currentNumber.push_front("-");
        }

    }
    displayNumber();
    statusBar()->showMessage("Change the fuhao",3000);
}

void MainWindow::percentageClicked()
{
    if(!isEmpty)
    {
        currentNumber ="0";
        isEmpty = true;
    }
    else
    {
        double number = currentNumber.toDouble()/100;
        currentNumber = QString::number(number);

    }
    displayNumber();
    statusBar()->showMessage("Percentage cal",3000);
}

void MainWindow::decimalPointClicked()
{
    if(!isEmpty)
    {
        currentNumber = "0.";
        isEmpty = true;
    }
    else if(currentNumber.indexOf(".")==-1){
        currentNumber.push_back(".");
    }
    displayNumber();
    statusBar()->showMessage("Input point",3000);
}

void MainWindow::btnEqualityClicked()
{

    if(currentAction == NoAction)
    {
        statusBar()->showMessage("请选择一个运算",3000);
        return;
    }

    switch(currentAction){
    case AddtionFlag:
    {
        currentNumber = QString::number(lastNumber.toDouble() + currentNumber.toDouble());
        break;
    }
    case SubtractionFlag:
    {
        currentNumber = QString::number(lastNumber.toDouble() - currentNumber.toDouble());
        break;
    }
    case MultiplicationFlag:
    {
        currentNumber = QString::number(lastNumber.toDouble() * currentNumber.toDouble());
        break;
    }
    case DivisionFlag:
    {
        currentNumber = QString::number(lastNumber.toDouble() / currentNumber.toDouble());
        break;
    }
    default:
        break;
    }
    currentAction = NoAction;
    statusBar()->showMessage("Succeed",3000);
    displayNumber();
}

void MainWindow::on_actionKula_triggered()
{
    Dialog dialog;
    QLabel *label = new QLabel("I'm Kula",&dialog);
    label->setText("<h1>Hello,I'm Kula =w=<h1>");
    label->setStyleSheet(tr("color:blue"));
    dialog.exec();
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
    ui->actionQuit->setToolTip("Quit");
    ui->actionQuit->setStatusTip("Quit Now");
}


