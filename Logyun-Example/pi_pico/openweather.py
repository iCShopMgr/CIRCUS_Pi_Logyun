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
    uart.write("OpenWeather(1673820,e917ccc7b76f97e8578ef8d851257d)")
    data = readData(6)
    print("OpenWeather:")
    print("Temp:{}, Temp_min:{}, Temp_max:{}, Pressure:{}, Humid:{}, WindSpeed:{}"
            .format(data[0], data[1], data[2], data[3], data[4], data[5]))
    sleep(1)
