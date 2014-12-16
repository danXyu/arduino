const int sensorPin = A0;
const float baselineTemp = 21.9;

void setup() {
  Serial.begin(9600);
  
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop(){
  int sensorVal = analogRead(sensorPin);
  
  // Log the value of the sensor
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  
  // Convert the analog value to a voltage
  float voltageValue = (sensorVal/1024.0) * 5.0;
  
  // Print voltage value to the screen
  Serial.print(", Voltage value: ");  
  Serial.print(voltageValue);
  
  // Print out the temperature
  float temperature = (voltageValue - 0.5) * 100;
  Serial.print(", Temperature: ");
  Serial.println(temperature);
  
  // Parse for the lighting
  if(temperature < baselineTemp){
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }else if(temperature >= baselineTemp && temperature < baselineTemp+2){
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  delay(200);
}

