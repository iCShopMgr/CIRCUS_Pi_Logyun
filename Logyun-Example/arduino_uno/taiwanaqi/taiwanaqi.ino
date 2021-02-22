#include <SoftwareSerial.h>
SoftwareSerial logyun(11, 12); // RX, TX

String cmd = "";
String data[9] = {};

void setup() {
  Serial.begin(115200);
  logyun.begin(115200);

  logyun.write("WifiConnect(MakerLab_2.4G,53574722)");
  delay(100);
  cmd = logyun.readStringUntil('\n');
  Serial.println(cmd);
}

void loop() {
  logyun.write("TaiwanAQI(左營)");
  delay(100);
  for (int i=0; i<9; i++) {
    cmd = logyun.readStringUntil('\n');
    data[i] = cmd;
  }
  Serial.println("TaiwanAQI:");
  Serial.print("AQI:"+data[0]);
  Serial.print(", CO2:"+data[1]);
  Serial.print(", CO:"+data[2]);
  Serial.print(", O3:"+data[3]);
  Serial.print(", WindSpeed:"+data[4]);
  Serial.print(", PM10:"+data[5]);
  Serial.print(", PM2.5:"+data[6]);
  Serial.print(", PM10_AVG:"+data[7]);
  Serial.print(", PM2.5_AVG:"+data[8]);
  Serial.println("");
  delay(3000);
}
