#include <SoftwareSerial.h>
SoftwareSerial logyun(11, 12); // RX, TX

String cmd = "";
String data[10] = {};

void setup() {
  Serial.begin(115200);
  logyun.begin(115200);

  logyun.write("WifiConnect(MakerLab_2.4G,53574722)");
  delay(100);
  cmd = logyun.readStringUntil('\n');
  Serial.println(cmd);
}

void loop() {
  logyun.write("TaiwanStock(2330)");
  delay(100);
  for (int i=0; i<10; i++) {
    cmd = logyun.readStringUntil('\n');
    data[i] = cmd;
  }
  Serial.println("TaiwanStock:");
  Serial.print("ID:"+data[0]);
  Serial.print(", Opening Price:"+data[1]);
  Serial.print(", Closing Price:"+data[2]);
  Serial.print(", Day High:"+data[3]);
  Serial.print(", Day Low:"+data[4]);
  Serial.print(", Volume:"+data[5]);
  Serial.print(", Total Volume:"+data[6]);
  Serial.print(", Strike price:"+data[7]);
  Serial.print(", data:"+data[8]);
  Serial.print(", time:"+data[9]);
  Serial.println("");
  delay(3000);
}
