// defining pins
#define SW1 2
#define SW2 3
#define rLED 12
#define bLED 13

// state variables
bool on = false;
bool switcher = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(rLED, OUTPUT);
  pinMode(bLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(SW1) == HIGH) {
    on = true;
  }

  while (on) {
    
    if (switcher) {
      digitalWrite(rLED, HIGH);
      digitalWrite(bLED, LOW);
      switcher = false;
    } else {
      digitalWrite(rLED, HIGH);
      digitalWrite(bLED, LOW);
      switcher = true;
    }

    if (digitalRead(SW2) == HIGH) {
      digitalWrite(rLED, LOW);
      digitalWrite(bLED, LOW);
      on = false;
    }

    delay(500);
    
  }
  
}
