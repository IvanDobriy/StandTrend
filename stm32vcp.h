#ifndef STM32VCP_H
#define STM32VCP_H

#include <QObject>
#include <QDebug>

class StmVCP: public QObject
{
    Q_OBJECT
public:
    StmVCP(QObject* parent = 0);
public slots:
    void test_slot();
};
#endif // STM32VCP_H

