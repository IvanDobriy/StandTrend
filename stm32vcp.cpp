#include "stm32vcp.h"

 StmVCP::StmVCP(QObject* parent): QObject(parent){
    qDebug() << "The object is initialized";

}

void StmVCP::test_slot(){
    qDebug() << "Test slot is launched";
}
