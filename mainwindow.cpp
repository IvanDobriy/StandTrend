#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),

    stm(new Stm32VCP),

    portHandler(new SerialPortHandler)


{

    ui->setupUi(this);

    //stm->setParent(this);
    //stm->moveToThread(&thread);
    portHandler->moveToThread(&thread2);
   // connect(&thread, SIGNAL(finished()),
  //            stm, SLOT(deleteLater()));
    connect(&thread2, SIGNAL(finished()),
            portHandler, SLOT(deleteLater()));
    connect(ui->openPortButton, SIGNAL(clicked(bool)),
            portHandler, SLOT(ReadData__Debug()));
    //connect(portHandler, SIGNAL(isRunning()),
      //      stm, SLOT(test_slot()));
  //  thread.start();
    thread2.start();

}

MainWindow::~MainWindow()
{
    if(thread.isRunning()){
        qDebug() << "Thread is exited";

        thread.quit();
    }
    if (thread2.isRunning()){

        qDebug() << "Thread2 is exited";
        thread2.quit();

    }

    delete ui;
}
