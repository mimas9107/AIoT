int btn_led=15;
int btn = 23;

bool state=0;
bool btnState=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(btn_led,OUTPUT);
  pinMode(btn,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // if(digitalRead(btn) == HIGH){
  //   digitalWrite(btn_led, HIGH);
    
  // }else{
  //   digitalWrite(btn_led, LOW);
  // }

  // toggle功能
  // 以 btnState紀錄 toggle狀態
  if(digitalRead(btn)==HIGH && btnState==0){
    // 若沒有加 btnState判斷,
    // 按鈕按著不放會造成 loop一直進來判斷為HIGH, 
    // state就 true->false->true->false->... LED閃爍.
    state=!state; 
    digitalWrite(btn_led, state);
    btnState=1;
    delay(300); // suedo de-bounce 
  }else if(digitalRead(btn)==LOW && btnState==1){
    btnState=0; 
  }

}
