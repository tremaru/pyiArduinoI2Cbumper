// Пример автоматической калибровки бампера:               // * Строки со звёздочкой являются необязательными.
                                                           //
#include "Serial.h"
#include "../iarduino_I2C_Bumper.h"                        //   Подключаем библиотеку для работы с бампером I2C-flash.
iarduino_I2C_Bumper bum(0x09);                             //   Объявляем объект bum для работы с функциями и методами библиотеки iarduino_I2C_Bumper, указывая адрес модуля на шине I2C.
                                                           //   Если объявить объект без указания адреса (iarduino_I2C_Bumper bum;), то адрес будет найден автоматически.
int main(){                                                //
    delay(500);                                            // * Ждём завершение переходных процессов связанных с подачей питания.
    Serial.begin(9600);                                    //   Инициируем передачу данных в монитор последовательного порта на скорости 9600 бит/сек.
    while(!Serial){;}                                      // * Ждём завершения инициализации шины UART.
    bool f;                                                //   Объявляем флаг для отслеживания результатов калибровки.
    bum.begin();                                           //   Инициируем работу с бампером.
    Serial.println("Установите бампер над линией трассы"); //   Выводим текст.
    Serial.println("У Вас есть 5 секунд...\r\n");          // * Выводим текст.
    delay(5000);                                           // *
    Serial.println("Запускаем калибровку.");               // * Выводим текст.
    Serial.println("Ждите...\r\n");                        // * Выводим текст.
    f = bum.setCalibrationRun();                           //   Запускаем калибровку.
    if(f){Serial.println("Линия считана!");}               //   Если калибровка запустилась (f==true), то выводим текст.
    else {Serial.println("Ошибка!."); while(1){;} }        //   Иначе, выводим сообщение об ошибке и завершаем выполнение программы входом в бесконечный цикл while.
    Serial.println("------------");                        // * Выводим текст.
    delay(1000);                                           // *
    Serial.println("Установите бампер над фоном трассы");  //   Выводим текст.
    Serial.println("У Вас есть 5 секунд...\r\n");          // * Выводим текст.
    delay(5000);                                           // *
    Serial.println("Завершаем калибровку.");               // * Выводим текст.
    Serial.println("Ждите...\r\n");                        // * Выводим текст.
    f = bum.setCalibrationEnd();                           //   Завершаем калибровку.
    if(f){Serial.println("Фон считан!");}                  //   Если калибровка успешно завершена (f==true), то выводим текст.
    else {Serial.println("Ошибка!."); while(1){;} }        //   Иначе, выводим сообщение об ошибке и завершаем выполнение программы входом в бесконечный цикл while.
    Serial.println("------------");                        // * Выводим текст.
    delay(1000);                                           // *
    Serial.println("Калибровка успешно завершена!");       //   Выводим текст.
    Serial.print("Бампер откалиброван для трассы с");      // * Выводим текст.
    switch(bum.getLineType()){                             // * Получаем тип линии.
        case BUM_LINE_BLACK:                               // * Если функция getLineType() вернула значение BUM_LINE_BLACK, то ...
        Serial.println(" тёмной линией на светлом фоне."); // * Выводим текст.
        break;                                             // *
        case BUM_LINE_WHITE:                               // * Если функция getLineType() вернула значение BUM_LINE_WHITE, то ...
        Serial.println("о светлой линией на тёмном фоне.");// * Выводим текст.
        break;                                             // *
        default:                                           // *
        Serial.println("неизвестным типом линии.");        // * Выводим текст.
    }   Serial.println("============");                    // * Выводим текст.
}                                                          //
/*  Автоматическая калибровка состоит из 2 этапов:
 *  Запуск     калибровки функцией setCalibrationRun() - при этом модуль считывает показания датчиков над линией.
 *  Завершение калибровки функцией setCalibrationEnd() - при этом модуль считывает показания датчиков над фоном.
 *  Калибровка считается успешно завершённой, если обе функции вернули true.
 *
 *  ПРИМЕЧАНИЕ:
 *  Выполнение каждой функции (setCalibrationRun/setCalibrationEnd), занимает до 5 секунд.
 *  Все датчики модуля должны находиться над линией (для первой функции), или над фоном (для второй функции)
 *  с момента обращения к функции и до момента возвращения ей результата.
 */
