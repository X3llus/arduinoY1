// defining pins and times
#define bLED 13
#define dot 100
#define dash 1000

// setting morse code variable
String morse = "-... -.-.";

void setup() {
  // put your setup code here, to run once:
  pinMode(bLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= morse.length(); i++) {

    // on time
    digitalWrite(bLED, HIGH);
    if (morse[i] == "-") {
      delay(dash);
    } else if (morse[i] == ".") {
      delay(dot);
    }
    
    // off time
    digitalWrite(bLED, LOW);
    if (morse[i+1] == " ") {
      if (morse[i + 2] == "/") {
        i++;
        delay(dash*4);
      } else {
        i+=2;
        delay(dash);
      }
    } else {
      delay(dot);
    }
  }
}
