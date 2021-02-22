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
  logyun.write("MQTTConnect(broker.hivemq.com,1883,yisreal,,,yisreal/7697)");
  delay(100);
  cmd = logyun.readStringUntil('\n');
  Serial.println(cmd);
}

void loop() {
  logyun.write("MQTTPublish(yisreal/7697,1)");
  delay(3000);
  logyun.write("MQTTPublish(yisreal/7697,0)");
  delay(3000);
}
