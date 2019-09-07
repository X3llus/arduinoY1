// defining pins and times
#define bLED 13
#define dot 100
#define dash 1000

// setting morse code variable
String morse = "-... -.-.";

void setup() {
  // put your setup code here, to run once:
  pinMode(bLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= morse.length(); i++) {

    // on time
    digitalWrite(bLED, HIGH);
    if (morse.charAt(i) == '-') {
      delay(dash);
      Serial.write("dash");
    } else if (morse.charAt(i) == '.') {
      delay(dot);
      Serial.write("dot");
    }
    
    // off time
    digitalWrite(bLED, LOW);
    if (morse.charAt(i) ==  ' ') {
      if (morse.charAt(i+1) == '/') {
        delay(dash*4);
        Serial.print("\n\n");
      } else {
        delay(dash);
        Serial.print("\n");
      }
    } else {
      delay(dot);
      Serial.print(" ");
    }
  }

  delay(dash*4);
  Serial.print("\n\n\n");
  
}
