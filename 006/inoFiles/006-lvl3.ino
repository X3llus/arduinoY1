#define b1 2 // button 1
#define b2 3 // button 2
#define RGBRedPin 9    // The red RGB LED is connected pin 9 of the Arduino.
#define RGBGreenPin 10 // The green RGB LED is connected pin 10 of the Arduino.
#define RGBBluePin 11  // The blue RGB LED is connected pin 11 of the Arduino.

boolean active = false; // Boolean for active loop
int passThrough = 1; // Pass through value for colour loop

void red() { // Display Red
  digitalWrite(RGBRedPin, HIGH); // Turn on RED
  digitalWrite(RGBGreenPin, LOW); // Turn off GREEN
  digitalWrite(RGBBluePin, LOW); // Turn off BLUE
}

void green() { // Display Green
  digitalWrite(RGBRedPin, LOW); // Turn off red
  digitalWrite(RGBGreenPin, HIGH); // Turn on GREEN
  digitalWrite(RGBBluePin, LOW); // Turn off BLUE
}

void blue() { // Display Blue
  digitalWrite(RGBRedPin, LOW); // Turn off red
  digitalWrite(RGBGreenPin, LOW); // Turn off GREEN
  digitalWrite(RGBBluePin, HIGH); // Turn on BLUE
}

void off() { // Turn off RGB
  digitalWrite(RGBRedPin, LOW); // Turn off RED
  digitalWrite(RGBGreenPin, LOW); // Turn off GREEN
  digitalWrite(RGBBluePin, LOW); // Turn off BLUE
}

void setup() {
  // put your setup code here, to run once:
  pinMode(RGBRedPin, OUTPUT);    // Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  // Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   // Setup blue RGB LED pin as an output pin.
  pinMode(b1, INPUT); // Setup button one as input pin
  pinMode(b2, INPUT); // Setup button two as input pin
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(b1) == LOW) {
    active = true; // sets loop to active when button 1 is pressed
  }

  while (active) {
    switch (passThrough) { // switched between the three colours
      case 1:
        red();
        delay(500);
        passThrough++;
        break;
      case 2:
        green();
        delay(500);
        passThrough++;
        break;
      case 3:
        blue();
        delay(500);
        passThrough = 1;
        break;
    }
    if (digitalRead(b2) == LOW) { // stops loop when button 2 is pressed
      off();
      active = false;
    }
  }
}
