#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSerialPort>
#include <QThread>
#include "stm32vcp.h"
#include "serialporthandler.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    SerialPortHandler* portHandler;
    Stm32VCP* stm;
    QThread thread;
    QThread thread2;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
