const int redLEDPin = 11;
const int greenLEDPin = 9;
const int blueLEDPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup(){
  Serial.begin(9600);
  
  // Set all LEDs as OUTPUT
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop(){
  redSensorValue = analogRead(redSensorPin);
  delay(10);
  greenSensorValue = analogRead(greenSensorPin);
  delay(10);
  blueSensorValue = analogRead(blueSensorPin);
  delay(10);
  
  // Print out raw sensor values
  Serial.print("Raw sensor values, Red: ");
  Serial.print(redSensorValue);
  Serial.print(" Green: ");
  Serial.print(greenSensorValue);
  Serial.print(" Blue: ");
  Serial.print(blueSensorValue);
  
  // Set the values for the LEDs
  // This is used to set the brightness for the LEDs
  redValue = redSensorValue/4;  
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;
  
  // Print the mapped sensor values
  Serial.print(" Mapped sensor values, Red: ");
  Serial.print(redValue);
  Serial.print(" Green: ");
  Serial.print(greenValue);
  Serial.print(" Blue: ");
  Serial.println(blueValue);
  
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);  
  delay(100);
}
