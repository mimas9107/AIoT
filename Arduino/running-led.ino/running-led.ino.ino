//int led[8]={15,2,4,16,17,5,18,19};
// 使用 74HC595 位移暫存器IC. 控制8顆 LEDs
int pinData=32;
int pinLatch=33;
int pinClock=25;
byte LEDs=0;


void setup() {
  // put your setup code here, to run once:
  // for(int i=0; i<8; i++){
  //   pinMode(led[i], OUTPUT);
  // }

  pinMode(pinLatch, OUTPUT);
  pinMode(pinData,OUTPUT);
  pinMode(pinClock,OUTPUT);

  Serial.begin(115200);
  Serial.println("Type LED number to on/off! ");

}

void loop() {
  // ==== 直接 GPIO to LED ====
  // put your main code here, to run repeatedly:
  // for(int i=0; i<8; i++){
  //   digitalWrite(led[i],HIGH);
  //   delay(200);
  //   digitalWrite(led[i],LOW);
  //   delay(200);
  // }
  // ========
  // while(Serial.available()){
  //   int recieve=1;
  //   byte myWord=Serial.read();
  //   if((myWord-48)>=56){
  //     LEDs=0;
  //   }
  //   bitSet(LEDs, myWord-48);
    
  // }


  LEDs=0;
  updateShiftRegister();  //進行送資料的副程式
  delay(100);
  for (int i = 0; i < 8; i++) //依序亮燈
  {
    bitSet(LEDs, i);    // 經由多少燈要亮的i，換算成10進位，並把結果交給leds
    updateShiftRegister(); //進行送資料的副程式
    delay(80);
  }

  // ==== 74HC595 交替 Red / Green ====
  // digitalWrite(pinLatch, LOW);
  // shiftOut(pinData, pinClock,LSBFIRST,170);   //170 binary: 10101010
  // digitalWrite(pinLatch, HIGH);
  // delay(500);
  // digitalWrite(pinLatch, LOW);
  // shiftOut(pinData, pinClock, LSBFIRST, 85);  //85 binary: 01010101
  // digitalWrite(pinLatch, HIGH);
  // delay(500);
  // ========
}
void updateShiftRegister()
{  // ==== 74HC595 使用副程式: ====
   digitalWrite(pinLatch, LOW);
   shiftOut(pinData, pinClock, LSBFIRST, LEDs);
   digitalWrite(pinLatch, HIGH);
}