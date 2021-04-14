#include <SoftwareSerial.h>
SoftwareSerial logyun(11, 12); // RX, TX

int count = 1;

void setup() {
  Serial.begin(115200);
  logyun.begin(115200);

  logyun.write("WifiConnect(MakerLab_2.4G,53574722)");
  delay(100);
  Serial.println(logyun.readStringUntil('\n'));
}

void loop() {
  int value1 = random(100);
  int value2 = random(100);
  int value3 = random(100);
  logyun.write(("IFTTT(認證碼,事件名稱,"+String(value1)+","
                +String(value2)+","+String(value3)+","+")").c_str());
  delay(100);
  Serial.println(logyun.readStringUntil('\n'));
  delay(10000);
}
