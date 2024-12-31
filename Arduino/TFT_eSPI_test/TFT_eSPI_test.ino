#include <SPI.h>
#include <TFT_eSPI.h>
#include "image_128x160.h"

TFT_eSPI tft=TFT_eSPI();

void setup() {
  tft.init();
  delay(1000);
  tft.setRotation(2);
  tft.fillScreen(0x0000);
  delay(1000);
  tft.setSwapBytes(true); // BGR
  tft.pushImage(0,0,128,160,StarField_128x160);

}

void loop() {
  // put your main code here, to run repeatedly:

}
