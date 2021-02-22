#include <SoftwareSerial.h>
SoftwareSerial logyun(11, 12); // RX, TX

String cmd = "";
String data[8] = {};

void setup() {
  Serial.begin(115200);
  logyun.begin(115200);

  logyun.write("WifiConnect(MakerLab_2.4G,53574722)");
  delay(100);
  cmd = logyun.readStringUntil('\n');
  Serial.println(cmd);
}

void loop() {
  logyun.write("AirBox(123456789012)");
  delay(100);
  for (int i=0; i<8; i++) {
    cmd = logyun.readStringUntil('\n');
    data[i] = cmd;
  }
  Serial.println("AirBox:");
  Serial.print("Area:"+data[0]);
  Serial.print(", gps_lon:"+data[1]);
  Serial.print(", gps_lat:"+data[2]);
  Serial.print(", PM1.0:"+data[3]);
  Serial.print(", PM2.5:"+data[4]);
  Serial.print(", PM10:"+data[5]);
  Serial.print(", Temp:"+data[6]);
  Serial.print(", Humid:"+data[7]);
  Serial.println("");
  delay(3000);
}
