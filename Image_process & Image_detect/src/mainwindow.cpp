#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ui_dialog.h"
#include<QMenuBar>
#include<QMessageBox>
#include<QStatusBar>
#include<QToolBar>
#include<QFileDialog>
#include<QDebug>
#include<QDialog>
#include<dialog.h>
#include<math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon("D:/11.ico"),tr("Open Action"),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction2 = new QAction(tr("File"),this);
    blurAction = new QAction(tr("Blur"),this);
    detectAction = new QAction(tr("Detect"),this);
    reMap = new QAction(tr("Remap"),this);
    sketch = new QAction(tr("Scharr"),this);
    colors = new QAction(tr("Colors"),this);
    equalize = new QAction(tr("Equalize"),this);


    openAction->setStatusTip(tr("一定要记得先点这个图标打开图片，不然会出bug！"));

    connect(openAction,&QAction::triggered,this,&MainWindow::openActionSlot);
    connect(openAction2,&QAction::triggered,this,&MainWindow::openActionSlot);
    connect(blurAction,&QAction::triggered,this,&MainWindow::blurActionSlot);
    connect(reMap,&QAction::triggered,this,&MainWindow::remapSlot);
    connect(sketch,&QAction::triggered,this,&MainWindow::sketchSlot);
    connect(colors,&QAction::triggered,this,&MainWindow::colorsSlot);
    connect(equalize,&QAction::triggered,this,&MainWindow::equalizeHistSlot);
    //connect(detectAction,&QAction::triggered,this,&MainWindow::keyPointsSlot);

    //QMenu *file = menuBar()->addMenu(tr("&File"));
    ui->menuBar->addAction(openAction2);
    ui->mainToolBar->addAction(openAction);
    //ui->mainToolBar->addAction(openAction2);
    ui->mainToolBar->addAction(blurAction);
    ui->mainToolBar->addAction(reMap);
    ui->mainToolBar->addAction(sketch);
    ui->mainToolBar->addAction(colors);
    ui->mainToolBar->addAction(equalize);

    statusBar();
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
    src = image;
    Image = Mat2QImage(image);
    QImage imgScaled;
    imgScaled=Image.scaled(Image.width(),Image.height());
   // detect_1 = imgScaled;
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(imgScaled));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

}


void MainWindow::display(QImage Image)
{

    QImage imgScaled;
    imgScaled=Image.scaled(Image.width(),Image.height());
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(imgScaled));
    ui->graphicsView_2->setScene(scene);
    ui->graphicsView_2->show();

}


QImage MainWindow::Mat2QImage(const cv::Mat &mat)
{

    QImage img;
    if(mat.channels()==3)
    {
        cvtColor(mat,rgb,CV_BGR2RGB);
        img = QImage((const unsigned char*)(rgb.data),rgb.cols,rgb.rows,rgb.cols*rgb.channels(),QImage::Format_RGB888);
    }
    else if(mat.channels()==1)
    {
        img = QImage((const unsigned char*)(mat.data),mat.cols,mat.rows,mat.cols*mat.channels(),QImage::Format_RGB888);
    }
    return img;
}

Mat MainWindow::Blur(Mat &image)
{

    Mat dstImage;
    blur(image,dstImage,Size(7,7));
    return dstImage;
}

void MainWindow::blurActionSlot()
{
    QImage img;
    img=Mat2QImage(Blur(src));
    display(img);
}

void MainWindow::remapSlot()
{
    if(!src.data){
        openActionSlot();
    }
    Mat srcImage,dstImage;
    Mat map_x,map_y;
    srcImage=src;

    dstImage.create(srcImage.size(),srcImage.type());
    map_x.create(srcImage.size(),CV_32FC1);
    map_y.create(srcImage.size(),CV_32FC1);

    for(int j=0;j<srcImage.rows;j++)
    {
        for(int i=0;i<srcImage.cols;i++){
            map_x.at<float>(j,i) = static_cast<float>(srcImage.cols-i);
            map_y.at<float>(j,i) = static_cast<float>(j);
        }
    }
    remap(srcImage,dstImage,map_x,map_y,CV_INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
    remap(srcImage,dstImage,map_x,map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));

    Mat2QImage(dstImage);
    display(Image);
}

void MainWindow::sketchSlot()
{
    QImage image;
    Mat grad_x,grad_y;
    Mat abs_grad_x,abs_grad_y,dst;

    Scharr(src,grad_x,CV_16S,1,0,1,0,BORDER_DEFAULT);
    convertScaleAbs(grad_x,abs_grad_x);
    Scharr(src,grad_y,CV_16S,0,1,1,0,BORDER_DEFAULT);
    convertScaleAbs(grad_y,abs_grad_y);

    addWeighted(abs_grad_x,0.5,abs_grad_y,0.5,0,dst);

    image=Mat2QImage(dst);
    display(image);
}

void MainWindow::equalizeHistSlot()
{
    QImage image;
    Mat srcImage,dstImage;
    cvtColor(src,srcImage,COLOR_BGR2GRAY);
    equalizeHist(srcImage,dstImage);
    //imshow("?",dstImage);
    image=Mat2QImage(dstImage);
    display(image);
}

void MainWindow::colorsSlot()
{

    Dialog dialog;
    connect(dialog.ui->Slider1,SIGNAL(valueChanged(int)),&dialog,SLOT(setLineValue()));
    connect(dialog.ui->Slider2,SIGNAL(valueChanged(int)),&dialog,SLOT(setLineValue()));
    connect(dialog.ui->Slider3,SIGNAL(valueChanged(int)),&dialog,SLOT(setLineValue()));

    int red = dialog.ui->Slider1->value();
    int green = dialog.ui->Slider2->value();
    int blue = dialog.ui->Slider3->value();

    int temp=0;
    for(int y=0;y<src.rows;y++)
    {
            unsigned char *ptr = (unsigned char *)(dst.data + y * dst.step);
            unsigned char *ptr1 = (unsigned char *)(src.data + y * src.step);
            for (int x = 0;x < dst.cols;x++)
            {
                //蓝色设置
                temp = blue;
                if (1)
                {
                    ptr[3 * x + 0] = temp;
                }
                else
                {
                    ptr[3 * x + 0] = ptr1[3 * x + 0];
                }
                //绿色设置
                temp = green;
                if (1)
                {
                    ptr[3 * x + 1] = temp;
                }
                else
                {
                    ptr[3 * x + 1] = ptr1[3 * x + 1];
                }
                //红色设置
                temp = red;
                if (1)
                {
                    ptr[3 * x + 2] = temp;
                }
                else
                {
                    ptr[3 * x + 2] = ptr1[3 * x + 2];
                }
            }
        }
    QImage img=Mat2QImage(dst);
    display(img);
    dialog.exec();
}


/*Mat MainWindow::keyPoints(Mat& image)
{
    int minHessian = 400;
    SurfFeatureDetector detector(400);
    std::vector<KeyPoint> keypoints;

    detector.detect(image,keypoints);

    Mat img_keypoints;
    drawKeypoints(image,keypoints,img_keypoints,Scalar::all(-1),DrawMatchesFlags::DEFAULT);
    return img_keypoints;
}
*/

/*void MainWindow::keyPointsSlot()
{
    int minHessian = 400;

    SurfFeatureDetector detector;
    std::vector<KeyPoint> keypoints;
    detector.detect(src,keypoints);

    Mat img_keypoints;
    QImage img1;

    drawKeypoints(image,keypoints,img_keypoints,Scalar::all(-1),DrawMatchesFlags::DEFAULT);
    img1=Mat2QImage(img_keypoints);
    display(img1);

}
*/
