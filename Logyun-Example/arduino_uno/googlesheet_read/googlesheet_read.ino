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
  logyun.write("GoogleSheetRead(1L1v3Wch0S7yPmfk-pO82ByfS_868aONRgyby0o5tKAE,C3)");
  delay(100);
  cmd = logyun.readStringUntil('\n');
  Serial.println("C3 Data: "+cmd);
  delay(5000);
}
