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
  logyun.write("LineNotify(認證碼,Temp:27.5)");
  delay(100);
  Serial.println(logyun.readStringUntil('\n'));
  delay(3000);

  logyun.write("LineNotify(認證碼,Temp:27.5, Humid:75)");
  delay(100);
  Serial.println(logyun.readStringUntil('\n'));
  delay(3000);

  logyun.write(("LineNotify(認證碼," +String(count)+")").c_str());
  delay(100);
  Serial.println(logyun.readStringUntil('\n'));
  delay(3000);

  count += 1;
}
