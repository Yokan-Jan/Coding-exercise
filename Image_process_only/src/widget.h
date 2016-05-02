#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPaintEvent>
#include<QImage>
#include<QTimer>
#include<opencv/cv.h>
#include<opencv/highgui.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public:
    void display(QImage);
    QImage Mat2QImage(const cv::Mat &mat);

    void salt(cv::Mat &image,int n);
    Mat Erode(cv::Mat &image);
    Mat Blur(cv::Mat &image);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();


private:
    Ui::Widget *ui;
    cv::Mat Image;
    cv::Mat origin;
    cv::Mat rgb;
    IplImage* iplImage;
    QImage img;
    QImage imgScaled;

};

#endif // WIDGET_H
