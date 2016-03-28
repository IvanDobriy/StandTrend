#ifndef STM32VCP_H
#define STM32VCP_H
#include <QObject>
#include <QSerialPort>

class Stm32VCP: public QObject
{
public:
    Stm32VCP(QObject parent = 0);
signals:
private slots:

private:
    QSerialPort* serialPort;

};
#endif // STM32VCP_H

