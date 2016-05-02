#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QString>
#include<QDebug>
#include<QLabel>
#include<QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Open Image"));
    fileDialog->setDirectory(".");
    fileDialog->setNameFilter(tr("Image Files (*.png *.jpg *.bmp)"));
    if(fileDialog->exec() == QDialog::Accepted)
    {
        QString path = fileDialog->selectedFiles()[0];

        //载入图像
        Image = imread((const char*)path.toLocal8Bit());

        origin = Image.clone();
        img = Widget::Mat2QImage(Image);
        display(img);

    }
    else
    {
        return;
    }

}

void Widget::display(QImage img)
{
    QImage imgScaled;
    imgScaled = img.scaled(width()-25,height()-55);
    QGraphicsScene *scene = new QGraphicsScene;
                scene->addPixmap(QPixmap::fromImage(imgScaled));

                ui->graphicsView->setScene(scene);
               // ui->graphicsView->resize(imgScaled.width(),imgScaled.height());
                ui->graphicsView->show();
}


QImage  Widget::Mat2QImage(const cv::Mat &mat)
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

void Widget::on_pushButton_2_clicked()
{
    qApp->quit();
    ui->pushButton_2->setToolTip("Ready to quit");
    ui->pushButton_2->setStatusTip("退出");
}


void Widget::on_pushButton_3_clicked()
{
    salt(Image,3000);
    img = Widget::Mat2QImage(Image);

    display(img);
}

void Widget::on_pushButton_4_clicked()
{
    img = Widget::Mat2QImage(origin);

    display(img);
}

void Widget::salt(cv::Mat &image,int n)
{
    int i,j;
    for(int k=0;k<n;k++)
    {
        i = qrand()%image.cols;
        j = qrand()%image.rows;

        if(image.channels() == 1){
            //灰度图
            image.at<uchar>(j,i) = 255;

        }
        else if(image.channels() == 3){
            //RGB图
            image.at<cv::Vec3b>(j,i)[0]=255;
            image.at<cv::Vec3b>(j,i)[1]=255;
            image.at<cv::Vec3b>(j,i)[2]=255;
        }
    }
}

Mat Widget::Erode(cv::Mat &image)
{
    Mat element = getStructuringElement(MORPH_RECT,Size(15,15));
    Mat dstImage;
    erode(image,dstImage,element);
    return dstImage;
}

Mat Widget::Blur(cv::Mat &image)
{
    Mat dstImage;
    blur(image,dstImage,Size(10,10));
    return dstImage;
}

void Widget::on_pushButton_5_clicked()
{
    img = Widget::Mat2QImage(Erode(Image));

    display(img);
}

void Widget::on_pushButton_6_clicked()
{
    img = Widget::Mat2QImage(Blur(Image));

    display(img);
}
