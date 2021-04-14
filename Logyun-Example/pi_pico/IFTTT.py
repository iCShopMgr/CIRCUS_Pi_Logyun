from machine import UART
from time import sleep
import random

# use uart1(GP4, GP5), Logyun baudrate:115200
uart = UART(1, 115200)


uart.write("WifiConnect(MakerLab_2.4G,53574722)")
print(uart.readline())

uart.write("WifiLocalIP()")
ip = str(uart.readline())[2:-3]
print(ip)


while True:
    value = random.randint(0, 100)
    value1, value2, value3 = value/2, value/5, value/10
    uart.write("IFTTT(認證碼,事件名稱,value1:{},value2:{},value3:{})"
        .format(value1, value2, value3))
    print(uart.readline())
    sleep(10)
