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
  logyun.write("ThingSpeakRead(455974,N7JD7AWFN7KSR5FW,5)");
  delay(100);
  cmd = logyun.readStringUntil('\n');
  Serial.println("Field5 Data:" + cmd);
  delay(5000);
}
