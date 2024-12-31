// 
int led1=15;
int led2=19;
int btn=23;
bool btnState=0; // 防止重複觸發狀態紀錄

unsigned long getTime;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  // pinMode(btn,INPUT);
  pinMode(btn, INPUT_PULLUP); //啟用內建上拉電阻
  getTime=millis();

}

void loop() {
  // put your main code here, to run repeatedly:
  // getTime=millis();
  // Serial.println(getTime);
  // delay(1000);
  
  // 這邊led1的連續閃爍若是用 delay, 下方另外一顆 led的控制會無法執行到,
  if(millis()-getTime >=500){
    digitalWrite(led1, !digitalRead(led1));
    getTime=millis(); // 時間重抓 reset
  }


  bool reading=digitalRead(btn);
  if(reading == LOW && btnState == 0){ //讀取到上升緣時,
    digitalWrite(led2, !digitalRead(led2)); //直接讀 led狀態, 然後反轉輸出.
    btnState=1;
    delay(200);
  }else if(reading == HIGH && btnState == 1){ //下降緣, 表示按鈕釋放.
    btnState=0;
  }
}
