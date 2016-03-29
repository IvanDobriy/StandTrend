#include "serialporthandler.h"

SerialPortHandler::SerialPortHandler(QObject *parent):
    QObject(parent),
    serialPort(new QSerialPort),
    serialPortInfo(new QSerialPortInfo),
    vendorIdentifer(1155),
    productIdentifer(22336)
{
    serialPort->setParent(this);
    if(SearchPort(vendorIdentifer, productIdentifer, serialPortInfo)){
        serialPort->setPort(*serialPortInfo);
        qDebug() << "Serial port Name is " << serialPort->portName();
        if(serialPort->setBaudRate(QSerialPort::Baud9600)){
            qDebug() << "Serial port Baud rate is " << serialPort->baudRate();
        }
        if(serialPort->setDataBits(QSerialPort::Data8)){
            qDebug() << "Serial port Data bits is " << serialPort->dataBits();
        }
        if(serialPort->setFlowControl(QSerialPort::NoFlowControl)){
            if(serialPort->flowControl() == QSerialPort::NoFlowControl){
                qDebug() << "Serial port has not flow control";
            }else{
                qDebug() << "Serial port has  flow control";
            }
        }
        if(serialPort->setStopBits(QSerialPort::OneStop)){
            if (serialPort->stopBits() == QSerialPort::OneStop){
                qDebug() << "Serial port has one stop bit";
            }else{
                qDebug() << "Serial port has more than on stop bit";
            }
        }

        if(serialPort->open(QIODevice::ReadWrite)){
            qDebug()<< "Serial Port with vid" << serialPortInfo->vendorIdentifier()
                    << "and PID "<< serialPortInfo->productIdentifier()
                    <<  "has been searched and configured";
        }
    }
}

void SerialPortHandler::ReadData__Debug(){
    qDebug() << " test is started";
    if(serialPort->isOpen()){
        emit isRunning();
        QByteArray buffer;
        while(1){
            if(serialPort->waitForReadyRead(1)){
                buffer = serialPort->readAll();
                qDebug() << "The reading value is: " << buffer;
            }
        }
    }
}


bool SerialPortHandler::SearchPort(quint16 vid, quint16 pid,
                                   QSerialPortInfo* info){
    quint16 length = info->availablePorts().length();

    if(length > 0){
        qDebug() << "Number of Serial ports is" << numSP;
        for (int i = 0; i < length; i++){
            if(info->availablePorts()[i].vendorIdentifier() == vid){
                if(info->availablePorts()[i].productIdentifier() == pid){
                    /*The port and it`s information has searched*/
                    *info = info->availablePorts()[i];
                    return true;
                }else{
                    qDebug() << "Port with the PID " << pid << " is not available now";
                    return false;
                }
            }else{
                qDebug() << "Port with the VID " << vid << " is not available now";
                return false;
            }
        }
    }else{
         qDebug() << "Serial ports is not available now";
    }
    return false;
}

SerialPortHandler::~SerialPortHandler(){
    if(serialPort->isOpen()){
        serialPort->close();
    }
    delete serialPort;
    delete serialPortInfo;
}

