#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QAction>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<QPaintEvent>
#include<QImage>
#include<opencv2/nonfree/nonfree.hpp>
#include<opencv2/legacy/legacy.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    QImage Mat2QImage(const cv::Mat &mat);
    void display(QImage img);

private:
    QAction *openAction;
    QAction *openAction2;
    QAction *detectAction;
    QAction *graEqualizeAction;
    cv::Mat src,dst;

private slots:
    void openActionSlot();
    void openActionSlot2();
//    void detectSlot();
//    void grayEqulizeActionSlot();


private:
    Ui::MainWindow *ui;
    cv::Mat image;
    cv::Mat rgb;
    QImage Image;
    QImage detect_1;
    QImage detect_2;

};

#endif // MAINWINDOW_H
