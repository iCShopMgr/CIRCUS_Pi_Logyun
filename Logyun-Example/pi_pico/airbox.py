from machine import UART
from time import sleep

# use uart1(GP4, GP5), Logyun baudrate:115200
uart = UART(1, 115200)

# read data(type:str)
def readData(dataSet):
    dataList = []
    for i in range(0, dataSet):
        ch = str(uart.readline())
        dataList.append(ch[2:-3])
    return dataList

uart.write("WifiConnect(MakerLab_2.4G,53574722)")
print(uart.readline())

while True:
    uart.write("AirBox(123456789012)")
    data = readData(8)
    print("AirBox:")
    print("Area:{}, gps_lon:{}, gps_lat:{}, PM1.0:{}, PM2.5:{}, PM10:{}, Temp:{}, Humid:{}".format(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]))
    sleep(1)
