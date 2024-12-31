#include "WiFi.h"

String encryption_type[]={
  "OPEN",
  "WEP",
  "WPA_PSK",
  "WPA2_PSK",
  "WPA_WPA2_PSK",
  "WPA2_ENTERPRISE",
  "MAX"
  };

void scanAP(){
  int n = WiFi.scanNetworks();
  delay(1000);
  Serial.println("scan Wi-Fi done");
  if(n == 0){ //接收到多少個存取點信號
    Serial.println("no Wi-Fi networks found");
  }else{
    Serial.print(n);
    Serial.println(" Wi-Fi networks found");
    for(int i=0; i<n; i++){
        Serial.print(i+1);
        Serial.print(": ");
        Serial.print(WiFi.SSID(i)+"\t");
        Serial.print("(");
        Serial.print(WiFi.RSSI(i)); //信號強度
        Serial.print(")\t");
      //加密類型
        Serial.println(encryption_type[WiFi.encryptionType(i)]);
        delay(10);
      }
  }
}


void setup() {
  Serial.begin(115200);


}

void loop() {
  scanAP();
  delay(10000);


}
