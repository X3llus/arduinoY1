#define tempPin A2     //The temperature sensor is plugged into pin A2 of the Arduino.
int data;             //This will store the data from the sensor.
int waitTime = 3000;  //Wait

void setup(void) {    //The Setup function runs once.
  Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
}

float toC (int inData) {
  float outData = (5.0 * data * 100.0) / 1024;
  return outData;
}

float toK (int inData) {
  float outData = ((5.0 * data * 100.0) / 1024) + 273.15;
  return outData;
}

float toN (int inData) {
  float outData = ((5.0 * data * 100.0) / 1024) * 0.33;
  return outData;
}

void loop(void) { //The loop function runs forever.
  data = analogRead(tempPin);        //Read from the temperature sensor
  Serial.print("\nSensor reading = "); //Serial.print displays to the Serial Monitor.
  Serial.println(data);                //This is the raw analog reading

  // Calculate and display temperature.
  Serial.print(toC(data)); Serial.println(" degrees C");
  Serial.print(toK(data)); Serial.println(" degrees K");
  Serial.print(toN(data)); Serial.println(" degrees N");
  

  delay(waitTime); //Wait waitTime before running again.
}

