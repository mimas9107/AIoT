// 
int led1=15;
int led2=19;
int btn=23;
bool btnState=0; // 防止重複觸發狀態紀錄
bool lastBtnState=1; // 上一次的按鍵狀態

unsigned long getTime;
unsigned long debounceDelayTime=50; //防彈跳延遲時間

void setup() {
  // put your setup code here, to run once:
  pinMode(led2, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  
  getTime=millis();  // 初始化抓取時間;

}

void loop() {
  // put your main code here, to run repeatedly:
  bool reading=digitalRead(btn);    //initial t0: HIGH
  if(reading!=lastBtnState){
    getTime=millis(); //只要 reading一有 HIGH/LOW變化, 則重新抓時間
  }
  if(millis()-getTime >= debounceDelayTime){ // 先判斷時間是否大於防彈跳延遲時間,
    if(reading==LOW && btnState==0){
      digitalWrite(led2, !digitalRead(led2));
      btnState=1;                     //設定按鈕狀態為按下,
    }else if(reading==HIGH && btnState==1){
      //
      btnState=0;
    }
  }
  lastBtnState=reading; //結束前將 reading存起來作為下一次的判斷,

}
