// Program: 007 level 3
// Author: Braden Coates
#define RGBGreenPin 10
#define rotationSensor A0

void greenFade(int fade) { // Fade green LED
  analogWrite(RGBGreenPin, fade);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
}

void loop() {
  // put your main code here, to run repeatedly:
  greenFade(map(analogRead(rotationSensor), 0, 1023, 0, 255)); // maps the rotation to the green fade
}
