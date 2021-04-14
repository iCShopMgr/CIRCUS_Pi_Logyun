from machine import UART
from time import sleep

# use uart1(GP4, GP5), Logyun baudrate:115200
uart = UART(1, 115200)


uart.write("WifiConnect(MakerLab_2.4G,53574722)")
print(uart.readline())

uart.write("WifiLocalIP()")
ip = str(uart.readline())[2:-3]
print(ip)

uart.write("MQTTConnect(broker.hivemq.com,1883,yisreal,,,home/light)")
print(uart.readline())

uart.write("MQTTSubscribe(home/door)")
print(uart.readline())

while True:
    uart.write("MQTTReceivedTopic()")
    topic = str(uart.readline())[2:-3]
    uart.write("MQTTReceivedMsg()")
    message = str(uart.readline())[2:-3]
    print("topic:{}, message:{}".format(topic, message))
    sleep(3)
