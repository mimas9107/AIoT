
//指定7Seg腳位 {a,b,c,d,e,f,g,dp):
int pin[7]={15,2,4,16,17,5,18}; 
int dp_pin=19; //dp_pin獨立控制

//控制 4個 7段顯示器,D1~D4:
int com[4]={13,12,14,27};

// 數字對應要亮的腳位, 其概念就是 bitmap.
// 4位數 7段顯示器, 每筆資料只要7筆元素, 最後一筆由 dp_pin獨立控制,
byte num[10][7]={
{1,1,1,1,1,1,0}, // 0
{0,1,1,0,0,0,0}, // 1
{1,1,0,1,1,0,1}, // 2
{1,1,1,1,0,0,1}, // 3
{0,1,1,0,0,1,1},  //4
{1,0,1,1,0,1,1},  //5
{1,0,1,1,1,1,1},  //6
{1,1,1,0,0,0,0},  //7
{1,1,1,1,1,1,1},  //8
{1,1,1,1,0,1,1}   //9
};

void seg(int number, int pos, int dp){
  //4顆顯示器先關掉:
  for(int i=0; i<4; i++){
    digitalWrite(com[i],HIGH);
  }
  
  for(int i=0; i<7; i++){
    digitalWrite(pin[i],num[number][i]);
  }
  //小數點要不要開:
  digitalWrite(dp_pin, dp);
  
  //打開哪顆顯示器:
  digitalWrite(com[pos],LOW);

  delay(10); //delay越長亮度越亮, 越閃爍; 反之越暗,越不閃. 
}

void setup() {
  //a,b,c,...f,g
  for(int i=0; i<7; i++){
    pinMode(pin[i],OUTPUT);
  }
  pinMode(dp_pin,OUTPUT);

  //com腳位
  for(int i=0; i<4; i++){
    pinMode(com[i],OUTPUT); //預設pinMode OUTPUT設定完就是 LOW, 但在這 D1~D4為 LOW時, 會4位全亮.
    //因此初始化應該設定 HIGH
    digitalWrite(com[i],HIGH);
  }

  // test:
  // for(int i=0; i<7; i++){
  //   digitalWrite(pin[i], num[1][i]);
  // }
  // digitalWrite(com[0],LOW);

}

void loop() {
  
  seg(0, 0, 1); // 會顯示 " 0. "
  seg(1, 1, 0);
  seg(2, 2, 0);
  seg(3, 3, 0);
}
