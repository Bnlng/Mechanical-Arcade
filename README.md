# Mechanical-Dogfight
Mechanical Arduino Arcade

```C
const int analogInPin = A0;  
const int analogOutPin9 = 9; 
const int analogOutPin11 = 11;
int sensorValue = 0;        
int outputValue = 0;      

void setup() {
  Serial.begin(9600);
}

void loop() {

  sensorValue = analogRead(analogInPin);
   if (sensorValue = 515) {
  outputValue = 0;
 }
 else
 if (sensorValue > 521) {
  outputValue = map(sensorValue, 526, 1023, 0, 255);
  analogWrite(analogOutPin9, outputValue);
 }
 if (sensorValue < 501) {
  outputValue = map(sensorValue, 501, 0, 0, 255);
  analogWrite(analogOutPin11, outputValue);
 }

 
 
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);


  delayMicroseconds(5);
}
```

```C
const int analogInPin = A0;  
const int analogOutPin9 = 9; 
const int analogOutPin11 = 11;
int sensorValue = 0;        
int outputValue = 0;      

void setup() {
  Serial.begin(9600);
}

void loop() {

  sensorValue = analogRead(analogInPin);

 if (sensorValue > 515) {
  outputValue = map(sensorValue, 515, 1023, 0, 255);
  analogWrite(analogOutPin9, outputValue);
 }

else if (sensorValue < 512) {
  outputValue = map(sensorValue, 513, 0, 0, 255);
  analogWrite(analogOutPin11, outputValue);
 }
else if (sensorValue = 513){
  outputValue = 0;
  analogWrite(analogOutPin11, outputValue);
  analogWrite(analogOutPin9, outputValue);
}

 
 
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);


  delay(1);
}
´´´


const int analogInPin = A0;  
const int analogOutPin9 = 9; 
const int analogOutPin11 = 11;
int sensorValue = 0;        
int outputValue = 0;
int sensorValueMax = 1023
int sensorValueTollerance = 10

void setup() {
  Serial.begin(9600);
}

void loop() {

  sensorValue = analogRead(analogInPin);

 if (sensorValue > ((sensorValueMax/2)+sensorValueTollerance) {
  outputValue = map(sensorValue, (sensorValueMax/2), sensorValueMax, 0, 255);
  analogWrite(analogOutPin9, outputValue);
 }

else if (sensorValue < ((sensorValueMax/2)-sensorValueTollerance) {
  outputValue = map(sensorValue, (sensorValueMax/2), 0, 0, 255);
  analogWrite(analogOutPin11, outputValue);
 }
else if (sensorValue <= ((sensorValueMax/2)+sensorValueTollerance) || sensorValue >= ((sensorValueMax/2)-sensorValueTollerance) ){
  outputValue = 0;
  analogWrite(analogOutPin11, outputValue);
  analogWrite(analogOutPin9, outputValue);
}

 
 
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);


  delay(1);
}
