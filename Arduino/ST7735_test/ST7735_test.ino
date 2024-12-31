#include <Adafruit_ST7735.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
// 定義要使用的自訂腳位, 其他 SPI用預設腳位
#define TFT_RST 5
#define TFT_DC 17
#define TFT_CS 16

// 用上面定義的腳來建構 tft物件,
Adafruit_ST7735 tft=Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

//自定義一個繪文字函數
void drawText(char *text, int color, byte size, bool wrap){
  tft.setTextColor(color); // RGB565顏色模式, 
  tft.setTextSize(size);
  tft.setTextWrap(wrap); // 是否換行, 否:超出就超出了不管, 是:換行
  tft.print(text);

  
}

void setup() {
  Serial.begin(115200);
  Serial.println("hello ST7735 TFT test!");

  tft.initR(INITR_BLACKTAB); // 初始化 tft模組
  Serial.println("Initialized");

  //自定義資料型態
  uint16_t time=millis();

  //填入顏色到 tft
  tft.fillScreen(0x0000);
  // 量測填完顏色
  time=millis()-time;
  Serial.println("fill screen need time: "+String(time)+" ms.");
  delay(500);
  tft.print("ST7735 LCD TFT start TesT!");
  tft.print("\n");
  tft.print("new line");

  // 0(0),1(90),2(180),3(270)
  tft.setRotation(3);
  //用法跟 1602類似,
  tft.setCursor(0,0);
  drawText("Hello !", 0xF800, 1, true); // r
  drawText("ST7735", 0x07E0, 2, true); // g
  drawText("\nWorLd!", 0x001F, 3, true); // b
  
  delay(1000);
  //畫像素
  tft.fillScreen(0x0000);
  tft.drawPixel(tft.width()/2, tft.height()/2, 0xFFFF);
  tft.drawPixel(tft.width()/2+1, tft.height()/2, 0xFFFF);
  tft.drawPixel(tft.width()/2-1, tft.height()/2, 0xFFFF);
  tft.drawPixel(tft.width()/2, tft.height()/2+1, 0xFFFF);
  tft.drawPixel(tft.width()/2, tft.height()/2-1, 0xFFFF);
  delay(2000);
  //畫線
  tft.fillScreen(0x0000);
  for(int x=0; x<tft.width(); x+=6){
    tft.drawLine(0, 0, x, tft.height(), ST7735_YELLOW);
  }
  delay(2000);
  tft.fillScreen(0x0000);
  for(int x=0; x<tft.width(); x+=16){
    tft.drawRect(tft.width()/2-x/2, tft.height()/2-x/2, x, x, ST7735_GREEN);
  }
  delay(2000);
  int radius=10;
  tft.fillScreen(0x0000);
  for(int x=radius; x<tft.width(); x+=radius*2){
    for (int y=radius; y < tft.height(); y+=radius*2) {
      tft.fillCircle(x, y, radius, ST7735_BLUE);
    }
  }
  for (int x=0; x < tft.width()+radius; x+=radius*2) {
    for (int y=0; y < tft.height()+radius; y+=radius*2) {
      tft.drawCircle(x, y, radius, ST7735_WHITE);
      }
  }
  delay(1000);
}

void loop() {
  

}
