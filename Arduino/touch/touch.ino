int led=19;
int touchpad=13;
unsigned long gettime;
void setup() {
  // 使用內建觸控 sensor
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 built-in Touch sensor Test...");
  pinMode(led,OUTPUT);
  pinMode(touchpad,INPUT);
  gettime=millis();
}

void loop() {
  // Serial.println(touchRead(T4));//ESP32內建
  // int val = touchRead(T4); //ESP32內建
  
  // if(val <=40){
  //   digitalWrite(led, !digitalRead(led));
  // }
  // Serial.println(val);
  // delay(300);
  int val = digitalRead(touchpad);
  
    if(val == HIGH){
      digitalWrite(led, !digitalRead(led));
    }
  
  // Serial.println(val);
  delay(500);
}
