/*
        Title: 321Maker Experiment #002 - RGB Blink
        Description: This program will cycle different colors using the RGB LED on the 321Maker shield.
        Tutorial:  http://321maker.com/tutorial/e002-rgb-blink
        Revision Date: January 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
        Instructions: The RGB LED is connected to a Pulse Width Modulation(PWM) pin.
        You can use analogWrite to control brightness.
*/

// program 002: level 3
// author: Braden Coates

#define RGBRedPin 9    //The red RGB LED is connected pin 9 of the Arduino.
#define RGBGreenPin 10 //The green RGB LED is connected pin 10 of the Arduino.
#define RGBBluePin 11  //The blue RGB LED is connected pin 11 of the Arduino.
#define waitTime 2000 //Sets the amount of time to wait between color changes.

int colour;

void setup() { //The Setup function runs once.
  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}

void red() {
  //Display Red
  digitalWrite(RGBRedPin, HIGH); //Turn on RED
  digitalWrite(RGBGreenPin, LOW); //Turn off GREEN
  digitalWrite(RGBBluePin, LOW); //Turn off BLUE
}

void green() {
  //Display Green
  digitalWrite(RGBRedPin, LOW); //Turn off red
  digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
  digitalWrite(RGBBluePin, LOW); //Turn off BLUE
}

void blue() {
  //Display Blue
  digitalWrite(RGBRedPin, LOW); //Turn off red
  digitalWrite(RGBGreenPin, LOW); //Turn off GREEN
  digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
}

void magenta() {
  //Display  Magenta  (Red + Blue)
  digitalWrite(RGBRedPin, HIGH); //Turn on RED
  digitalWrite(RGBGreenPin, LOW); //Turn off GREEN
  digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
}

void yellow() {
  //Display  Yellow  (Red + Green)
  digitalWrite(RGBRedPin, HIGH); //Turn on RED
  digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
  digitalWrite(RGBBluePin, LOW); //Turn off 
}

void cyan() {
  //Display  Cyan  (Blue + Green)
  digitalWrite(RGBRedPin, LOW); //Turn off red
  digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
  digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
}

void white() {
  //Display White  (Red + Blue + Green)
  digitalWrite(RGBRedPin, HIGH); //Turn on RED
  digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
  digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
}

void allOff() {
  //Display No colours
  digitalWrite(RGBRedPin, LOW); //Turn off RED
  digitalWrite(RGBBluePin, LOW); //Turn off BLUE
  digitalWrite(RGBGreenPin, LOW); //Turn off GREEN
}

void loop() { //The loop function runs forever.
  while (millis() <= 15000) { // run for 15 seconds
    colour = random(0, 7) + 1; // generates a random number
    switch (colour) { // uses the random number to choose a colour
      case 1:
        red();
        break;
      case 2:
        green();
        break;
      case 3:
        blue();
        break;
      case 4:
        magenta();
        break;
      case 5:
        yellow();
        break;
      case 6:
        cyan();
        break;
      case 7:
        white();
        break;
    }
    delay(random(1, 10) * 100); // random on time
  }
  allOff(); // turn lights off
}
