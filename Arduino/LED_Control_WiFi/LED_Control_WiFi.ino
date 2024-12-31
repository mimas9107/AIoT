#include <WiFi.h>
#include <HTTPClient.h> // 用途: 將 ESP32當成瀏覽器角色
// WiFi(client) 設定: 
const char* ssid="AI-08-2775";
char* password="aiclass1234";
// 設定呼叫字串: server端位址+ api位址
String server="http://192.168.137.1/ledctrl/result.php";

// 用內建LED燈來提示連線狀態:
const int led=2; 

// 建立 http client物件:
HTTPClient http;

// 處理傳送 api的函數:
void sendData(){
    
  // 先將組合好的字串塞給 http物件, 還未真的送出!
  http.begin(server);
  
  int httpCode=http.GET();
  if(httpCode == HTTP_CODE_OK){ // HTTP_CODE_OK=200
    String responsePayload=http.getString(); // 取得網站回應結果(字串)
    Serial.println("server response Payload: ");
    Serial.println(responsePayload);
    if(responsePayload=="1"){
      digitalWrite(led, HIGH);
    }else{
      digitalWrite(led, LOW);
    }

  }else{
    Serial.println("server response Code: ");
    Serial.println(httpCode);
  }
  http.end();
}


void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);

  WiFi.mode(WIFI_STA); // station模式, 當成瀏覽器去連線別的主機.
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    
  }
  Serial.println();
  Serial.println(" WiFi+ LED Control connected!");
}

void loop() {
  // put your main code here, to run repeatedly:
  sendData();
  delay(1000);
}
