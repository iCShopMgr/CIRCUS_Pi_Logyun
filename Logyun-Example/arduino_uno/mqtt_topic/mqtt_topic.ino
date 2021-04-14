#include <SoftwareSerial.h>
SoftwareSerial logyun(11, 12); // RX, TX

String topic = "";
String message = "";

void setup() {
  Serial.begin(115200);
  logyun.begin(115200);

  logyun.write("WifiConnect(MakerLab_2.4G,53574722)");
  delay(100);
  Serial.println(logyun.readStringUntil('\n'));

  logyun.write("MQTTConnect(broker.hivemq.com,1883,yisreal,,,home/light)");
  delay(100);
  Serial.println(logyun.readStringUntil('\n'));

  logyun.write("MQTTSubscribe(home/door)");
  delay(100);
  Serial.println(logyun.readStringUntil('\n'));
}

void loop() {
  logyun.write("MQTTReceivedTopic()");
  delay(100);
  topic = logyun.readStringUntil('\n');
  logyun.write("MQTTReceivedMsg()");
  delay(100);
  message = logyun.readStringUntil('\n');
  Serial.println("topic:" +topic+ ", message:" +message);
  delay(3000);
}
