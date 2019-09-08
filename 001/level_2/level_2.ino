// defining pins and times
#define bLED 13
#define onTimeOne 50
#define offTimeOne 950
#define onTimeTwo 6000
#define offTimeTwo 3000
#define onTimeThree 60
#define offTimeThree 40


void setup() {
  // put your setup code here, to run once:
  pinMode(bLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // part one
  digitalWrite(bLED, HIGH);
  delay(onTimeOne);
  digitalWrite(bLED, LOW);
  delay(offTimeOne);
  
  // part two
  digitalWrite(bLED, HIGH);
  delay(onTimeTwo);
  digitalWrite(bLED, LOW);
  delay(offTimeTwo);

  // part three
  digitalWrite(bLED, HIGH);
  delay(onTimeThree);
  digitalWrite(bLED, LOW);
  delay(offTimeThree);
}
