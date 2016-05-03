#include "dialog.h"
#include "ui_dialog.h"
#include<QString>
#include<QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->Slider1->setMaximum(255);
    ui->Slider2->setMaximum(255);
    ui->Slider3->setMaximum(255);

    ui->Slider1->setMinimum(0);
    ui->Slider2->setMinimum(0);
    ui->Slider3->setMinimum(0);

    ui->lineEdit_1->setText("0");
    ui->lineEdit_2->setText("0");
    ui->lineEdit_3->setText("0");

    ui->Slider1->setValue(0);
    ui->Slider2->setValue(0);
    ui->Slider3->setValue(0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setLineValue()
{
    int pos_1 = ui->Slider1->value();
    int pos_2 = ui->Slider2->value();
    int pos_3 = ui->Slider3->value();

    QString str1 = QString ("%1").arg(pos_1);
    QString str2 = QString ("%1").arg(pos_2);
    QString str3 = QString ("%1").arg(pos_3);

    ui->lineEdit_1->setText(str1);
    ui->lineEdit_2->setText(str2);
    ui->lineEdit_3->setText(str3);
}
