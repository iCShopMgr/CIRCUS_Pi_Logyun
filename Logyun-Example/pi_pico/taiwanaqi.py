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
    uart.write("TaiwanAQI(左營)")
    data = readData(9)
    print("TaiwanAQI:")
    print("AQI:{},SO2:{}, CO:{}, O3:{}, WindSpeed:{}, PM10:{}, PM2.5:{}, PM10_AVG:{}, PM2.5_AVG:{}".format(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8]))
    sleep(1)
