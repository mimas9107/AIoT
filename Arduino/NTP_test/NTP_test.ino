#include <WiFi.h>
#include "time.h"

const char* ssid="AI-08-2775";
const char* password="aiclass1234";
//要連接的NTP伺服器位址
const char* ntpServer="pool.ntp.org";

//設定格林威治標準時間偏移
//gmtOffset_sec變數定義您的時區和 GMT 之間的偏移量（以秒為單位）；對於 UTC +8.00：8 x 60 x 60=28800
const long gmtOffset_sec=8*60*60;

//日光節約時間：以秒為單位定義夏令時的偏移量(台灣自1980年停止實施)
const int daylightOffset_sec=0;

void printLocalTime(){
  //建立一個叫timeinfo的時間結構(struct tm)
  struct tm timeinfo;

  //獲取有關日期和時間的所有詳細信息
  //並將其保存在timeinfo結構體
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Serial.print("Day of week: ");
  Serial.println(&timeinfo, "%A");
  Serial.print("Month: ");
  Serial.println(&timeinfo, "%B");
  Serial.print("Day of Month: ");
  Serial.println(&timeinfo, "%d");
  Serial.print("Year: ");
  Serial.println(&timeinfo, "%Y");
  Serial.print("Hour: ");
  Serial.println(&timeinfo, "%H");
  Serial.print("Hour (12 hour format): ");
  Serial.println(&timeinfo, "%I");
  Serial.print("Minute: ");
  Serial.println(&timeinfo, "%M");
  Serial.print("Second: ");
  Serial.println(&timeinfo, "%S");
  // //使用strftime()將時間資料結構轉換為變數範例
  // Serial.println("Time variables");
  // char timeHour[3]; //包含小時字符(2)和終止字符(1)
  // strftime(timeHour,3, "%H", &timeinfo);
  // Serial.println(timeHour);

  // char timeWeekDay[10];
  // strftime(timeWeekDay,10, "%A", &timeinfo);
  // Serial.println(timeWeekDay);
  // Serial.println();
}



void setup() {
  Serial.begin(115200);

  //連線到Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");

  // 使用之前的設定配置時間
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  //呼叫自定義函式 ，在取得時間的狀況下，建立第一次的時間結構
  printLocalTime();
  //取得NPT網路時間後，由時間函式維持運作，不再需要網路
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);

}

void loop() {
  delay(1000);
  printLocalTime();

}
