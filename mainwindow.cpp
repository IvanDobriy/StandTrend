#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    thread(new QThread),
    stm(new Stm32VCP)
{

    ui->setupUi(this);


    stm->moveToThread(thread);
    connect(thread, SIGNAL(finished()),
              stm, SLOT(deleteLater()));
    connect(ui->openPortButton, SIGNAL(clicked(bool)),
            stm, SLOT(test_slot()));
    thread->start();

}

MainWindow::~MainWindow()
{
    if(thread->isRunning()){
        thread->exit();
    }
    delete thread;
    delete stm;
    delete ui;
}
