#include <Arduino.h>

// Author: Braden
// Program: 008 lvl 3

#include <pitches.h>

#define buzzerPin 5
#define buttonPin 2
#define RGBRedPin 9
#define RGBGreenPin 10
#define RGBBluePin 11

int notes[119][3] = {{NOTE_G3, 50, 100}, {NOTE_A3, 50, 100}, {NOTE_G3, 50, 50}, {NOTE_FS3, 50, 50}, {NOTE_E3, 50, 100}, {NOTE_G3, 50, 100}, {NOTE_A3, 50, 100}, {NOTE_G3, 50, 50}, {NOTE_FS3, 50, 50}, {NOTE_E3, 50, 100}, {NOTE_G3, 50, 100}, {NOTE_A3, 50, 100}, {NOTE_G3, 50, 50}, {NOTE_FS3, 50, 50}, {NOTE_E3, 50, 100}, {NOTE_G3, 50, 100}, {NOTE_A3, 50, 100}, {NOTE_G3, 50, 50}, {NOTE_FS3, 50, 50}, {NOTE_E3, 50, 100}, {NOTE_G3, 50, 100}, {NOTE_A3, 50, 100}, {NOTE_G3, 50, 50}, {NOTE_FS3, 50, 50}, {NOTE_E3, 50, 100}, {NOTE_G3, 50, 100}, {NOTE_A3, 50, 100}, {NOTE_G3, 50, 50}, {NOTE_FS3, 50, 50}, {NOTE_E3, 50, 100}, {NOTE_G3, 50, 100}, {NOTE_A3, 50, 100}, {NOTE_G3, 50, 50}, {NOTE_FS3, 50, 50}, {NOTE_E3, 50, 100}, {NOTE_G3, 50, 100}, {NOTE_A3, 50, 50}, {NOTE_G3, 50, 50}, {NOTE_FS3, 50, 50}, {NOTE_E3, 50, 100}, {NOTE_E4, 50, 100}, {NOTE_FS4, 50, 100}, {NOTE_G4, 50, 200}, {NOTE_A4, 50, 200}, {NOTE_B3, 50, 200}, {NOTE_A4, 50, 200}, {NOTE_G4, 50, 100}, {NOTE_FS4, 50, 100}, {NOTE_E4, 50, 400}, {NOTE_E4, 50, 100}, {NOTE_FS4, 50, 100}, {NOTE_G4, 50, 200}, {NOTE_A4, 50, 200}, {NOTE_B3, 50, 200}, {NOTE_A4, 50, 200}, {NOTE_G4, 50, 100}, {NOTE_FS4, 50, 100}, {NOTE_E4, 50, 400}, {NOTE_E4, 50, 100}, {NOTE_FS4, 50, 100}, {NOTE_G4, 50, 200}, {NOTE_A4, 50, 200}, {NOTE_B3, 50, 200}, {NOTE_B4, 50, 200}, {NOTE_A4, 50, 100}, {NOTE_G4, 50, 100}, {NOTE_FS4, 50, 400}, {NOTE_E4, 50, 100}, {NOTE_FS4, 50, 100}, {NOTE_G4, 50, 200}, {NOTE_A4, 50, 200}, {NOTE_B3, 50, 200}, {NOTE_A4, 50, 200}, {NOTE_G4, 50, 100}, {NOTE_FS4, 50, 100}, {NOTE_E4, 50, 400}, {NOTE_G4, 50, 100}, {NOTE_G4, 50, 300}, {NOTE_G4, 50, 100}, {NOTE_G4, 50, 300}, {NOTE_G4, 50, 100}, {NOTE_G4, 50, 300}, {NOTE_A4, 50, 10}, {NOTE_FS4, 50, 300}, {NOTE_G4, 50, 100}, {NOTE_G4, 50, 300}, {NOTE_G4, 50, 100}, {NOTE_G4, 50, 300}, {NOTE_G4, 50, 100}, {NOTE_G4, 50, 300}, {NOTE_A4, 50, 100}, {NOTE_FS4, 50, 300}, {NOTE_G4, 50, 100}, {NOTE_A4, 50, 100}, {NOTE_G4, 50, 50}, {NOTE_FS4, 50, 50}, {NOTE_E4, 50, 100}, {NOTE_G4, 50, 100}, {NOTE_A4, 50, 100}, {NOTE_G4, 50, 50}, {NOTE_FS4, 50, 50}, {NOTE_E4, 50, 100}, {NOTE_G4, 50, 100}, {NOTE_A4, 50, 100}, {NOTE_G4, 50, 50}, {NOTE_FS4, 50, 50}, {NOTE_E4, 50, 100}, {NOTE_G4, 50, 100}, {NOTE_A4, 50, 100}, {NOTE_G4, 50, 50}, {NOTE_FS4, 50, 50}, {NOTE_E4, 50, 100}, {NOTE_G4, 50, 100}, {NOTE_A4, 50, 400}, {NOTE_G4, 50, 100}, {NOTE_A4, 50, 100}, {NOTE_G4, 50, 50}, {NOTE_FS4, 50, 50}, {NOTE_E4, 50, 50}};

void resetRGB() {
  analogWrite(RGBRedPin, 0);
  analogWrite(RGBGreenPin, 0);
  analogWrite(RGBBluePin, 0);
}

void redFade(int fade) { // Fade red LED
  resetRGB();
  analogWrite(RGBRedPin, fade);
}

void greenFade(int fade) { // Fade green LED
  resetRGB();
  analogWrite(RGBGreenPin, fade);
}

void blueFade(int fade) { // Fade blue LED
  resetRGB();
  analogWrite(RGBBluePin, fade);
}

void song() {
  for (int i = 0; i < 119; i++) {
    switch(random(3)) {
      case 0:
        redFade(map(notes[i][0], 31, 4978, 0, 255));
        break;
      case 1:
        greenFade(map(notes[i][0], 31, 4978, 0, 255));
        break;
      case 2:
        blueFade(map(notes[i][0], 31, 4978, 0, 255));
        break;
    }
    tone(buzzerPin, notes[i][0], notes[i][1]*2);
    delay(notes[i][2]*2);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);  //Setup red LED pin as an output pin.
  pinMode(buttonPin, INPUT);  //Setup button1 pin as an input pin.
  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}

void loop() {
  // put your main code here, to run repeatedly:
  while (digitalRead(buttonPin) == HIGH) {
    // do nothing
  }

  song();

}
