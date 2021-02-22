from machine import UART
from time import sleep

# use uart1(GP4, GP5), Logyun baudrate:115200
uart = UART(1, 115200)

uart.write("WifiConnect(MakerLab_2.4G,53574722)")
print(uart.readline())

while True:
    uart.write("GoogleSheetRead(157bm1bfwr66tvHEtRUp7dkvLZI-V0NWsES71dVu6ZRQ,C3)")
    print(str(uart.readline())[2:-3])
    sleep(5)
