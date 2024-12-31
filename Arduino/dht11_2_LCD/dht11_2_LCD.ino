#include <DHT.h>
#define DHTPIN 27
#define DHTYPE DHT11

DHT dht(DHTPIN, DHTYPE);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const byte rows=4;
const byte cols=4;

// LiquidCrystal_I2C LCD(addr, cols, rows);
LiquidCrystal_I2C LCD(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  Serial.println("DHT11 demo1");

  //dht object initialize
  dht.begin();

  LCD.init();
  //背光
  LCD.backlight();
}

String str="";
byte temp=B11011111; // binary number前面加個大寫 B, => 11011111:°

void loop() {
  delay(2000);
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


}
