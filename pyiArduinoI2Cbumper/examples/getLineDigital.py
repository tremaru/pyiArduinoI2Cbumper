# Пример чтения линий под датчиками бампера:                #
                                                            #
from time import sleep
from pyiArduinoI2Cbumper import *                           #   Подключаем библиотеку для работы с бампером I2C-flash.
bum = pyiArduinoI2Cbumper(0x09)                             #   Объявляем объект bum для работы с функциями и методами библиотеки pyiArduinoI2Cbumper, указывая адрес модуля на шине I2C.
                                                            #   Если объявить объект без указания адреса bum = pyiArduinoI2Cbumper(), то адрес будет найден автоматически.
while True:                                                 #
    print("Линия находится под датчиком:", end="")          #   Выводим текст.
    if bum.getLineDigital(1): print(" 1", end="")         #   Выводим номер 1 датчика, если под ним находится линия.
    if bum.getLineDigital(2): print(" 2", end="")         #   Выводим номер 2 датчика, если под ним находится линия.
    if bum.getLineDigital(3): print(" 3", end="")         #   Выводим номер 3 датчика, если под ним находится линия.
    if bum.getLineDigital(4): print(" 4", end="")         #   Выводим номер 4 датчика, если под ним находится линия.
    if bum.getLineDigital(5): print(" 5", end="")         #   Выводим номер 5 датчика, если под ним находится линия.
    if bum.getLineDigital(6): print(" 6", end="")         #   Выводим номер 6 датчика, если под ним находится линия.
    if bum.getLineDigital(7): print(" 7", end="")         #   Выводим номер 7 датчика, если под ним находится линия.
    if bum.getLineDigital(8): print(" 8", end="")         #   Выводим номер 8 датчика, если под ним находится линия.
    if bum.getLineDigital(9): print(" 9", end="")         #   Выводим номер 9 датчика, если под ним находится линия.
    print(".")                                    #   Завершаем строку.
    sleep(.2)                                             # * Задержка позволяет медленнее заполнять монитор последовательного порта.
