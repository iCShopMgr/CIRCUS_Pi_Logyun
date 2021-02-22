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
  logyun.write("GoogleSheetWrite(1L1v3Wch0S7yPmfk-pO82ByfS_868aONRgyby0o5tKAE,1,2,3,4,5,6,7,8,9,10)");
  delay(100);
  cmd = logyun.readStringUntil('\n');
  delay(15000);
}
