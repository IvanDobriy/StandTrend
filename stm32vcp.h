#ifndef STM32VCP_H
#define STM32VCP_H

#include <QObject>
#include <QDebug>

class Stm32VCP: public QObject
{
    Q_OBJECT
public:
    Stm32VCP(QObject* par = 0);
    ~Stm32VCP();
public slots:
    void test_slot();
};

#endif // STM32VCP_H

