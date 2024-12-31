#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <Keypad.h>
const byte rows=4;
const byte cols=4;

char keys[rows][cols]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[rows]={32,33,25,26};
byte colPins[cols]={27,14,12,13};

Keypad myKeypad=Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

// LiquidCrystal_I2C LCD(addr, cols, rows);
LiquidCrystal_I2C LCD(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Serial.println("");

  //LiquidCrystal_I2C initialize
  LCD.init();
  //背光
  LCD.backlight();

  // LCD.setCursor(0,0);
  // LCD.print("Hello World!");
}

String str="";
byte temp=B11011111; // binary number前面加個大寫 B, => 度

void loop() {
  
char keybuf=myKeypad.getKey();

  if(keybuf != NO_KEY){
    if(keybuf=='#'){
      LCD.clear();
      LCD.setCursor(0,1);
      LCD.print(str);
      
      LCD.write(temp);
      LCD.print("C");
      str="";
    }else{
      str+=keybuf;
    }
    Serial.println(keybuf);
  }
}
