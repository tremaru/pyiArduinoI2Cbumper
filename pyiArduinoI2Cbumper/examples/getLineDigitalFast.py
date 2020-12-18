# ПРИМЕР БЫСТРОГО ЧТЕНИЯ ЛИНИЙ ПОД ДАТЧИКАМИ БАМПЕРА

#  Данный пример, в отличии от примера «getLineDigital», читает состояние всех датчиков одним запросом,
#  это значительно ускоряет процесс получения данных от бампера.
from time import sleep

#   Подключаем библиотеку для работы с бампером I2C-flash.
from pyiArduinoI2Cbumper import *

#   Объявляем объект bum для работы с функциями и методами библиотеки
#   pyiArduinoI2Cbumper, указывая адрес модуля на шине I2C.
#   Если объявить объект без указания адреса bum = pyiArduinoI2Cbumper(),
#   то адрес будет найден автоматически.
bum = pyiArduinoI2Cbumper(0x09)

while True:                                                #

    sleep(.2)
    t = ""

    #   Читаем состояние сразу всех датчиков.
    #   Каждый бит переменной i отвечает за свой датчик (кроме 0 бита).
    i = bum.getLineDigital(BUM_LINE_ALL)

    if (i):
        t += "Линия под датчиком:"
    else:
        t = "Линия не найдена."
        print(t)
        continue

    if i & (1<<1): t+=" 1"   # Записываем номер 1 датчика, если под ним находится линия.
    if i & (1<<2): t+=" 2"   # Записываем номер 2 датчика, если под ним находится линия.
    if i & (1<<3): t+=" 3"   # Записываем номер 3 датчика, если под ним находится линия.
    if i & (1<<4): t+=" 4"   # Записываем номер 4 датчика, если под ним находится линия.
    if i & (1<<5): t+=" 5"   # Записываем номер 5 датчика, если под ним находится линия.
    if i & (1<<6): t+=" 6"   # Записываем номер 6 датчика, если под ним находится линия.
    if i & (1<<7): t+=" 7"   # Записываем номер 7 датчика, если под ним находится линия.
    if i & (1<<8): t+=" 8"   # Записываем номер 8 датчика, если под ним находится линия.
    if i & (1<<9): t+=" 9"   # Записываем номер 9 датчика, если под ним находится линия.
    t += '.'

    print(t)