from machine import UART
from time import sleep

# use uart1(GP4, GP5), Logyun baudrate:115200
uart = UART(1, 115200)

uart.write("WifiConnect(MakerLab_2.4G,53574722)")
print(uart.readline())

while True:
    uart.write("ThingSpeakRead(455974,N7JD7AWFN7KSR5FW,1)")
    print(str(uart.readline())[2:-3])
    uart.write("ThingSpeakRead(455974,N7JD7AWFN7KSR5FW,2)")
    print(str(uart.readline())[2:-3])
    uart.write("ThingSpeakRead(455974,N7JD7AWFN7KSR5FW,3)")
    print(str(uart.readline())[2:-3])
    sleep(1)
