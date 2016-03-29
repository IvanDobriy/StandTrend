#ifndef SERIALPORTHANDLER_H
#define SERIALPORTHANDLER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>


class SerialPortHandler: public QObject{
    Q_OBJECT
public:
    SerialPortHandler(QObject* parent = 0);
    ~SerialPortHandler();
    /*<<<< Add constuctors for setting vendor and
    product ID*/
public slots:
    void ReadData__Debug();
signals:
 void isRunning();
private:
    QSerialPort* serialPort;
    QSerialPortInfo* serialPortInfo;
    quint16 vendorIdentifer;
    quint16 productIdentifer;
    quint16 numSP;
    bool SearchPort(quint16 vid, quint16 pid,
                    QSerialPortInfo* info);

};

#endif // SERIALPORTHANDLER_H
