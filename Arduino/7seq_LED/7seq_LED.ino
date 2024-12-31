//指定7Seg腳位 {a,b,c,d,e,f,g,dp)
int pin[8]={15,2,4,16,17,5,18,19}; 

//數字對應要亮的腳位, 其實概念就是 bitmap.
byte num[10][8]={
{1,1,1,1,1,1,0,0}, // 0
{0,1,1,0,0,0,0,0}, // 1
{1,1,0,1,1,0,1,0}, // 2
{1,1,1,1,0,0,1,0}, // 3
{0,1,1,0,0,1,1,0},  //4
{1,0,1,1,0,1,1,0},  //5
{1,0,1,1,1,1,1,0},  //6
{1,1,1,0,0,0,0,0},  //7
{1,1,1,1,1,1,1,0},  //8
{1,1,1,1,0,1,1,0}   //9
};

int birth[4]={1,2,1,4};

void setup() {
  // 設定腳位輸出:
  for(int i=0; i<8; i++){
    pinMode(pin[i], OUTPUT);
  }
}

void loop() {
  // 迴圈把數字對應 pin腳寫入:
  // for(int i=0; i<10; i++){
  //   for(int j=0; j<8; j++){
  //     digitalWrite(pin[j],num[i][j]);
  //   }
  //   delay(1000);
  // }

  // 迴圈把對應我要顯示的數字群寫進去:
  for(int i=0; i<4; i++){
    for(int j=0; j<8; j++){
      digitalWrite(pin[j],num[birth[i]][j]); 
    }
    delay(1000);
  }  
}
