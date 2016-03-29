#include "stm32vcp.h"

 Stm32VCP::Stm32VCP(QObject* par): QObject(par){
       qDebug() << "The object is initialized";

}

void Stm32VCP::test_slot(){
      qDebug() << "Test slot is launched";
}
