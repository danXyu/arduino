#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potValue;
int angle;

// Setup the serial port and attachments
void setup(){
  myServo.attach(9);
  
  Serial.begin(9600);
}

void loop(){
  potValue = analogRead(potPin);
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  
  angle = map(potValue, 0, 1023, 0, 179);
  Serial.print(", Angle: ");
  Serial.println(angle);
  
  myServo.write(angle);
  delay(15);
}
