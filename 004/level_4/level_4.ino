// Program: 004 Level 4
// Author: Braden Coates

#define lightPin A1 //The light sensor is plugged into pin A1 of the Arduino.
#define RGBRedPin 9    //The red RGB LED is connected pin 9 of the Arduino.
#define RGBGreenPin 10 //The green RGB LED is connected pin 10 of the Arduino.
#define RGBBluePin 11  //The blue RGB LED is connected pin 11 of the Arduino.
int light;      //This will store the data from the sensor.

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

void setup() { //The Setup function runs once.
  Serial.begin(9600);
  pinMode(RGBRedPin, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}

void loop() { //The loop function runs forever.
  light = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable
  light = map(light, 0, 1023, 1, 100);
  Serial.print("Light value = ");
  Serial.println(light);  //Print the data to the serial port.
  
  if (light <= 35) red(); // dark light
  if (light > 35 && light < 70) blue(); // medium light
  if (light >=70) green(); // high light
  
  delay(100);
}

