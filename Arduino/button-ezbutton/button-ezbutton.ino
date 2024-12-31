#include <ezButton.h>

int led=19;
int led2=15;
int btn=23;

ezButton btn1(btn); // 程式庫內部是用內部上拉設計, 
unsigned long btn1_getTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(led2,OUTPUT);
  // btn 23已經交由 ezButton物件,
  // 只要設定此物件的防彈跳時間:
  btn1.setDebounceTime(50);

}

void loop() {
  // put your main code here, to run repeatedly:
  btn1.loop();
  if(btn1.isPressed()){
    btn1_getTime=millis();
  }

  if(btn1.isReleased()){
    // digitalWrite(led, !digitalRead(led));
    if(millis()-btn1_getTime >=2000){
      digitalWrite(led2, !digitalRead(led2));
    }//else{
      digitalWrite(led, !digitalRead(led));
    //}
    
  }
}
