int led=19;
int mq2dout=12;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(mq2dout, INPUT);

}

void loop() {
  bool gasSignal=digitalRead(mq2dout);
  Serial.print("gas sensor val:");
  Serial.println(gasSignal);
  digitalWrite(led,!gasSignal);

}
