from machine import UART
from time import sleep

# use uart1(GP4, GP5), Logyun baudrate:115200
uart = UART(1, 115200)

uart.write("WifiConnect(MakerLab_2.4G,53574722)")
print(uart.readline())

while True:
    uart.write("GoogleSheetWrite(157bm1bfwr66tvHEtRUp7dkvLZI-V0NWsES71dVu6ZRQ,1,2,3,4,5,6,7,8,9,10)")
    print(uart.readline())
    sleep(10)
