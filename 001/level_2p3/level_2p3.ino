// defining pins and times
#define bLED 13
#define onTime 60
#define offTime 40


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
