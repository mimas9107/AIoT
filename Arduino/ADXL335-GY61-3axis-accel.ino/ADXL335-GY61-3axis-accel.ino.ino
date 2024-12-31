const int xInput=36;
const int yInput=39;
const int zInput=34;

int RawMin=0;
int RawMax=4095;

int sampleSize=10;

int ReadAxis(int axisPin){
  long reading=0;
  reading=analogRead(axisPin);
  delay(10);
  for(int i=0;i<sampleSize;i++){
    reading+=analogRead(axisPin);
  }
  return reading/sampleSize;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xRaw=ReadAxis(xInput);
  int yRaw=ReadAxis(yInput);
  int zRaw=ReadAxis(zInput);
  long xScaled = map(xRaw,RawMin, RawMax, -1000,1000);
  long yScaled = map(yRaw, RawMin, RawMax, -1000, 1000);
  long zScaled = map(zRaw, RawMin, RawMax, -1000, 1000);
// 將數值除以1000以取得正確值
  float xAccel = xScaled / 1000.0;
  float yAccel = yScaled / 1000.0;
  float zAccel = zScaled / 1000.0;
  Serial.print("X,Y,Z ::");
  Serial.print(xRaw);
  Serial.print(", ");
  Serial.print(yRaw);
  Serial.print(", ");
  Serial.print(zRaw);
  Serial.print(" :: ");
  Serial.print(xAccel,2);
  Serial.print("G, ");
  Serial.print(yAccel,2);
  Serial.print("G, ");
  Serial.print(zAccel,2);
  Serial.println("G");
  delay(200);


}
