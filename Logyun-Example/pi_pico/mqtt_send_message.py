from machine import UART
from time import sleep

# use uart1(GP4, GP5), Logyun baudrate:115200
uart = UART(1, 115200)

uart.write("WifiConnect(MakerLab_2.4G,53574722)")
print(uart.readline())
uart.write("MQTTConnect(broker.hivemq.com,1883,yisreal,,,yisreal/7697)")
print(uart.readline())

while True:
    uart.write("MQTTPublish(yisreal/7697,1)")
    print(uart.readline())
    sleep(3)
    uart.write("MQTTPublish(yisreal/7697,0)")
    print(uart.readline())
    sleep(3)
