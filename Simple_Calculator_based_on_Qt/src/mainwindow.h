#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QLabel>
namespace Ui {
class MainWindow;
}

enum ActionFlag{
    NoAction,
    AddtionFlag,
    SubtractionFlag,
    MultiplicationFlag,
    DivisionFlag
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void clear();
    void actionChanged();
    void inputNumber();
    void displayNumber();
    void negativeClicked();
    void percentageClicked();
    void decimalPointClicked();
    void btnEqualityClicked();

    void on_actionKula_triggered();

    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;

    ActionFlag currentAction;
    QString lastNumber;
    QString currentNumber;
    bool isEmpty;


};

#endif // MAINWINDOW_H
