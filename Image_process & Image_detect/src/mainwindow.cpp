#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMenuBar>
#include<QMessageBox>
#include<QStatusBar>
#include<QToolBar>
#include<QFileDialog>
#include<QDebug>
#include<opencv2/features2d/features2d.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon("D:/11.ico"),tr("Open Action"),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction2 = new QAction(QIcon("D:/22.ico"),tr("Open Action2"),this);

    //openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction,&QAction::triggered,this,&MainWindow::openActionSlot);
    connect(openAction2,&QAction::triggered,this,&MainWindow::openActionSlot2);

    //QMenu *file = menuBar()->addMenu(tr("&File"));
    ui->menuBar->addAction(tr("File"));

    ui->mainToolBar->addAction(openAction);
    ui->mainToolBar->addAction(openAction2);

    //statusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openActionSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),
                                                   ".",tr("Image Files(*.png *.jpg *.bmp"));
    qDebug()<<"FileName is:"<<fileName;
    image = cv::imread(fileName.toLocal8Bit().data());
    Image = Mat2QImage(image);
    QImage imgScaled;
    detect_1=Image.scaled(418,490);
   // detect_1 = imgScaled;
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(detect_1));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();


}

void MainWindow::openActionSlot2()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),
                                                   ".",tr("Image Files(*.png *.jpg *.bmp"));
    qDebug()<<"FileName is:"<<fileName;
    image = cv::imread(fileName.toLocal8Bit().data());
    Image = Mat2QImage(image);
    QImage imgScaled;

    detect_2=Image.scaled(418,490);
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(detect_2));
    ui->graphicsView_2->setScene(scene);
    ui->graphicsView_2->show();
}

/*void MainWindow::display(QImage img)
{
    QImage imgScaled;
    imgScaled=img.scaled(418,490);
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(imgScaled));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

}*/


QImage MainWindow::Mat2QImage(const cv::Mat &mat)
{

    QImage img;
    if(mat.channels()==3)
    {
        cvtColor(mat,rgb,CV_BGR2RGB);
        img = QImage((const unsigned char*)(rgb.data),rgb.cols,rgb.rows,rgb.cols*rgb.channels(),QImage::Format_RGB888);
    }
    else
    {
        img = QImage((const unsigned char*)(mat.data),mat.cols,mat.rows,mat.cols*mat.channels(),QImage::Format_RGB888);
    }
    return img;
}
