const int adcpin=34;
const int led=2; //built-in LED

int freq=1000; //PWM 設定頻率
int res=12; //解析度 order 2^12=4096
int val=0;

void setup() {
  Serial.begin(115200);

  ledcAttach(led, freq, res); //這支腳位就能當 PWM輸出;
}

void loop() {
  delay(500);
  val=analogRead(adcpin);
  
  ledcWrite(led, val);
  
  
  Serial.println(val);



}
