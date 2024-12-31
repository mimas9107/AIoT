#include <WiFi.h>
#include <HTTPClient.h> // 用途: 將 ESP32當成瀏覽器角色

#include <DHT.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 27
#define DHTYPE DHT11
DHT dht(DHTPIN, DHTYPE);

const byte rows=4;
const byte cols=4;
// LiquidCrystal_I2C LCD(addr, cols, rows);
LiquidCrystal_I2C LCD(0x27, 16, 2);

// WiFi(client) 設定: 
// const char* ssid="AIMESH93_B";
// const char* password="93abcd1234";
// 設定呼叫字串: server端位址+ api位址
// String server="http://192.168.208.37/web3/add_api.php";
const char* ssid="AI-08-2775";
char* password="aiclass1234";
String server="http://192.168.137.1/web3/add_api.php";

// 用內建LED燈來提示連線狀態:
const int led=2; 

// 建立 http client物件:
HTTPClient http;

// 處理傳送 api的函數:
void sendData(String urlData){
  // 組合
  String str=server+urlData;
  // 先將組合好的字串塞給 http物件, 還未真的送出!
  http.begin(str);
  
  // Debug 印字串看看:
  Serial.print("str: ");
  Serial.println(str);

  int httpCode=http.GET();
  if(httpCode == HTTP_CODE_OK){ // HTTP_CODE_OK=200
    String responsePayload=http.getString(); // 取得網站回應結果(字串)
    Serial.println("server response Payload: ");
    Serial.println(responsePayload);

  }else{
    Serial.println("server response Code: ");
    Serial.println(httpCode);
  }
  http.end();
  delay(20000); // 給個 20s延遲, 免得 DDOS server.
}


void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);

  WiFi.mode(WIFI_STA); // station模式, 當成瀏覽器去連線別的主機.
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    digitalWrite(led, !digitalRead(led)); // 讓內建 LED閃爍
  }
  Serial.println();
  Serial.println("DHT11+ LCD+ WiFi connected!");
  digitalWrite(led, HIGH); // 正確連上, 讓 LED恆亮

  //dht object initialize
  dht.begin();

  LCD.init();
  //背光
  LCD.backlight();
}

String str="";
byte temp=B11011111; // binary number前面加個大寫 B, => 11011111:°

void loop() {
  String strData="";


  float humidity1=dht.readHumidity();
  delay(50);
  float humidity2=dht.readHumidity();
  delay(50);
  float humidity3=dht.readHumidity();

  float temperature=dht.readTemperature();


  float humidity=humidity1+humidity2+humidity3;
  humidity /=3;
  // isnan(float) 用這個函數判斷時, 只能接受浮點數; 其他會出邏輯問題 
  if(isnan(humidity1) || isnan(temperature)){
    Serial.println("failed to read from DHT sensor!");
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("failed to read");
    LCD.setCursor(0,1);
    LCD.print("from DHT sensor!");
    return;
  }

  str=humidity;
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print("H="+str+"%");
  
  LCD.setCursor(0,1);
  str=temperature;
  LCD.print("T="+str);
  LCD.write(temp);
  LCD.print("C");


  Serial.print("humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("*C\n");

  //準備要存的資料字串: 用 String(變數)將量測數據轉換成字串
  strData="?temp="+String(temperature)+"&humi="+String(humidity);
  //送出字串
  sendData(strData);

  delay(2000);
}
