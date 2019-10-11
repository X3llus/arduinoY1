// Program: 007 level 4
// Author: Braden Coates
#define RGBRedPin 9
#define RGBGreenPin 10
#define RGBBluePin 11
#define SW2 3
#define rotationSensor A0

void redFade(int fade) { // Fade red LED
  analogWrite(RGBRedPin, fade);
}

void greenFade(int fade) { // Fade green LED
  analogWrite(RGBGreenPin, fade);
}

void blueFade(int fade) { // Fade blue LED
  analogWrite(RGBBluePin, fade);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}

void loop() {
  // put your main code here, to run repeatedly:
  while (true) { // map the rotation to the red fade value
    redFade(map(analogRead(rotationSensor), 0, 1023, 0, 255));
    if (digitalRead(SW2) == LOW) { // go to the next colour when SW1 is pressed
      delay(500);
      break;
    }
  }
  while (true) { // map the rotation to the green fade value
    greenFade(map(analogRead(rotationSensor), 0, 1023, 0, 255));
    if (digitalRead(SW2) == LOW) { // go to the next colour when SW1 is pressed
      delay(500);
      break;
    }
  }
  while (true) { // map the rotation to the blue fade value
    blueFade(map(analogRead(rotationSensor), 0, 1023, 0, 255));
    if (digitalRead(SW2) == LOW) { // go to the next colour when SW1 is pressed
      delay(500);
      break;
    }
  }
}
