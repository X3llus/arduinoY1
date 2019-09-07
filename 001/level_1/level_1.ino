// defining pins and times
#define bLED 13
#define onTime 2000
#define offTime 500


void setup() {
  // put your setup code here, to run once:
  pinMode(bLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(bLED, HIGH);
  delay(onTime);
  digitalWrite(bLED, LOW);
  delay(offTime);
}
