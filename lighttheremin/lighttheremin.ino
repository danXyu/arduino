int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup(){
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  Serial.begin(9600);
  
  // Calibrate sensor
  while(millis() < 5000){
    sensorValue = analogRead(A0);
    if(sensorValue < sensorLow){
     sensorLow = sensorValue;
    }
    if(sensorValue > sensorHigh){
     sensorHigh = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop(){
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  Serial.print("Pitch Value: ");
  Serial.println(pitch);
  tone(8, pitch, 20);
  
  delay(10);
}


