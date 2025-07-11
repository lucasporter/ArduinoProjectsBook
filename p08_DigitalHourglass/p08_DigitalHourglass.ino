const int switchPin = 8;

unsigned long previousTime = 0;  // store the last time an LED was updated
int switchState = 0;             // the current switch state
int prevSwitchState = 0;         // the previous switch state
int led = 2;                     // a variable to refer to the LEDs


long interval = 1000;  

void setup() {
  
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  
  pinMode(switchPin, INPUT);
}

void loop() {
  
  unsigned long currentTime = millis();

  
  if (currentTime - previousTime > interval) {
    
    previousTime = currentTime;
    
    digitalWrite(led, HIGH);
    
    led++;

    if (led == 7) {
    
    }
  }

  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }

    led = 2;

    previousTime = currentTime;
  }

  prevSwitchState = switchState;
}
