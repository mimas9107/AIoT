#include <DHT.h>
#define DHTPIN 27
#define DHTYPE DHT11

DHT dht(DHTPIN, DHTYPE);


void setup() {
  Serial.begin(115200);

  Serial.println("DHT11 demo1");

  //dht object initialize
  dht.begin();
}

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

  if(isnan(humidity1) || isnan(temperature)){
    Serial.println("failed to read from DHT sensor!");
    return;
  }

  Serial.print("humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("*C\n");


}
