// defining pins and times
#define bLED 13
#define sFlash 1000
#define fFlash 100

void setup() {
  // put your setup code here, to run once:
  pinMode(bLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //three slow flashes
  for (int i = 3; i > 0; i--) {
    digitalWrite(bLED, HIGH);
    delay(sFlash);
    digitalWrite(bLED, LOW);
    delay(sFlash);
  }

  //three long flashes
  for (int i = 3; i > 0; i--) {
    digitalWrite(bLED, HIGH);
    delay(fFlash);
    digitalWrite(bLED, LOW);
    delay(fFlash);
  }
}
