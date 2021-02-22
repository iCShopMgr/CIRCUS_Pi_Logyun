#include <SoftwareSerial.h>
SoftwareSerial logyun(11, 12); // RX, TX

String cmd = "";
String data[6] = {};

void setup() {
  Serial.begin(115200);
  logyun.begin(115200);

  logyun.write("WifiConnect(MakerLab_2.4G,53574722)");
  delay(100);
  cmd = logyun.readStringUntil('\n');
  Serial.println(cmd);
}

void loop() {
  logyun.write("OpenWeather(1668341,e917ccc7b76f97e8578ef8d851257d76)");
  delay(100);
  for (int i=0; i<6; i++) {
    cmd = logyun.readStringUntil('\n');
    data[i] = cmd;
  }
  Serial.println("OpenWeather:");
  Serial.print("Temp:"+data[0]);
  Serial.print(", Temp_min:"+data[1]);
  Serial.print(", Temp_max:"+data[2]);
  Serial.print(", Pressure:"+data[3]);
  Serial.print(", Humid:"+data[4]);
  Serial.print(", WindSpeed:"+data[5]);
  Serial.println("");
  delay(3000);
}
