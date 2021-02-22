#include <ESP8266WiFi.h>

String cmd = "";
String check_cmd = "";
String text = "";
byte count_cmd = 0;


void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    cmd = Serial.readString();
    check_cmd = "";
    for (int i=0; i<cmd.indexOf("("); i++) {
      count_cmd = i;
      text = cmd.charAt(i);
      check_cmd += text;
    }
    if (check_cmd == "WifiConnect") {
      Wifi_Connect();
    }
    else {
      Serial.print("error\n");
    }
  }
}

// WifiConnect(SSID,Password)
void Wifi_Connect() {
  String wifi_ssid = "";
  String wifi_password = "";
  for (int i=cmd.indexOf("(")+1; i<cmd.indexOf(","); i++) {
    text = cmd.charAt(i);
    wifi_ssid += text;
  }
  for (int i=cmd.indexOf(",")+1; i<cmd.indexOf(")"); i++) {
    text = cmd.charAt(i);
    wifi_password += text;
  }
  WiFi.begin(wifi_ssid, wifi_password);
  count_cmd = 0;
  while( WiFi.status() != WL_CONNECTED ) {
      delay(500);
      count_cmd += 1;
      if (count_cmd > 7) {
        break;
      }
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("error\n");

  }
  else {
    Serial.print("ok\n");
  }
}
