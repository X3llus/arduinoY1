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

  // part one
  //three slow flashes
  for (int i = 3; i > 0; i--) {
    digitalWrite(bLED, HIGH);
    delay(dash);
    digitalWrite(bLED, LOW);
    delay(dash);
  }

  //three long flashes
  for (int i = 3; i > 0; i--) {
    digitalWrite(bLED, HIGH);
    delay(dot);
    digitalWrite(bLED, LOW);
    delay(dot);
  }

  // part two
  for (int i = 0; i <= morse.length(); i++) {

    // on time
    digitalWrite(bLED, HIGH);
    if (morse.charAt(i) == '-') {
      delay(dash);
    } else if (morse.charAt(i) == '.') {
      delay(dot);
    }
    
    // off time
    digitalWrite(bLED, LOW);
    if (morse.charAt(i) ==  ' ') {
      if (morse.charAt(i+1) == '/') {
        delay(dash*4);
      } else {
        delay(dash);
      }
    } else {
      delay(dot);
    }
  }
  delay(dash*4);  
}
