// Initialize the value of switchState
int switchState = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);
  
  if(switchState == LOW) {
    // This means the button isn't pressed
    // Turn green LED on when button isn't pressed
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }else{
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    // Make the LEDs Blink
    delay(100);
    // Toggle the LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(100);
  }
}  
  
