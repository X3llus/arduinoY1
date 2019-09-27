// Program 003 - Level 3
// Author: Braden Coates

#define rotationPin A0 //The rotation sensor is plugged into pin A0 of the Arduino.
#define RGBRedPin 9    //The red RGB LED is connected pin 9 of the Arduino.
#define RGBGreenPin 10 //The green RGB LED is connected pin 10 of the Arduino.
#define RGBBluePin 11  //The blue RGB LED is connected pin 11 of the Arduino.
int del;           //Used to store data from sensor.
int pos = 0; // 

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
    
void displayData(int data) {
  Serial.print("Delay = "); 
  Serial.println(data);  //Print the data to the serial port.
}

void setup() {
  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}

void loop() { //The loop function runs forever.
  del = analogRead(rotationPin);  //Read the value from the light sensor and store it in the lightData variable.
  displayData(del);

  if (pos == 0) red();
  if (pos == 1) green();
  if (pos == 2) blue();

  pos++;
  if (pos == 3) pos = 0;
  delay(del);
}
