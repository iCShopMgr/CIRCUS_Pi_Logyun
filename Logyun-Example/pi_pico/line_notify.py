from machine import UART
from time import sleep

# use uart1(GP4, GP5), Logyun baudrate:115200
uart = UART(1, 115200)

uart.write("WifiConnect(MakerLab_2.4G,53574722)")
print(uart.readline())

uart.write("WifiLocalIP()")
ip = str(uart.readline())[2:-3]
print(ip)

count = 0

while True:
    uart.write("LineNotify(認證碼,Temp:27.5)")
    print(uart.readline())
    sleep(1)

    uart.write("LineNotify(認證碼,Temp:27.5, Humid:75)")
    print(uart.readline())
    sleep(1)

    uart.write("LineNotify(認證碼,count:{})".format(count))
    print(uart.readline())
    sleep(1)

    count += 100

    
