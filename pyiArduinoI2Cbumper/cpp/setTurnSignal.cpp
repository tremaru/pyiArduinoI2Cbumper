// Пример управления поворотниками на бампере:             // * Строки со звёздочкой являются необязательными.
                                                           //
#include "Serial.h"
#include "../iarduino_I2C_Bumper.h"                        //   Подключаем библиотеку для работы с бампером I2C-flash.
iarduino_I2C_Bumper bum(0x09);                             //   Объявляем объект bum для работы с функциями и методами библиотеки iarduino_I2C_Bumper, указывая адрес модуля на шине I2C.
                                                           //   Если объявить объект без указания адреса (iarduino_I2C_Bumper bum;), то адрес будет найден автоматически.
int main(){                                                //
    delay(500);                                            // * Ждём завершение переходных процессов связанных с подачей питания.
    bum.begin();                                           //   Инициируем работу с бампером.
    bum.setTurnPeriod(BUM_TURN_400);                       // * Задаём скорость мигания поворотников в 400мс. Возможные значения: BUM_TURN_100, BUM_TURN_200, BUM_TURN_400 и BUM_TURN_800.
    for (;;)
        loop();
}                                                          //
                                                           //
void loop(){                                               //
    bum.setTurnSignal(BUM_TURN_LEFT);                      //   Включаем левый поворотник.
    delay(5000);                                           //   Ждём 5 секунд.
    bum.setTurnSignal(BUM_TURN_RIGHT);                     //   Включаем правый поворотник.
    delay(5000);                                           //   Ждём 5 секунд.
    bum.setTurnSignal(BUM_TURN_EMERGENCY);                 //   Включаем поворотниками аварийный сигнал.
    delay(5000);                                           //   Ждём 5 секунд.
    bum.setTurnSignal(BUM_TURN_POLICE);                    //   Включаем поворотники в полицейский режим.
    delay(5000);                                           //   Ждём 5 секунд.
    bum.setTurnSignal(BUM_TURN_OFF);                       //   Отключаем поворотники.
    delay(5000);                                           //   Ждём 5 секунд.
}                                                          //
