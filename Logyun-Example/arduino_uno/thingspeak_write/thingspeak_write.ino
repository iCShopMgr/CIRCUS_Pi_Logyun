#include <SoftwareSerial.h>
SoftwareSerial logyun(11, 12); // RX, TX

String cmd = "";

void setup() {
  Serial.begin(115200);
  logyun.begin(115200);

  logyun.write("WifiConnect(MakerLab_2.4G,53574722)");
  delay(100);
  cmd = logyun.readStringUntil('\n');
  Serial.println(cmd);
}

void loop() {
  logyun.write("ThingSpeakWrite(DADQHLUQOK2A85ED,10,20,30,40,50)");
  delay(100);
  cmd = logyun.readStringUntil('\n');
  Serial.println(cmd);
  delay(15000);
}
