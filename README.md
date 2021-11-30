# Mechanical-Dogfight
Mechanical Arduino Arcade



![image](https://user-images.githubusercontent.com/88386307/144134092-46e0fe8e-6a1f-4bf1-b96e-1f3ff82eb055.png)


überabeiteter Code:
```c
const int analogInPinX = A0; //Joystick Inputpin X-axis
const int analogInPinY = A1; //Joystick Inputpin Y-axis

const int pwmPinXpos = 3;
const int pwmPinXneg = 5;
const int pwmPinYpos = 6;
const int pwmPinYneg = 9;

const int buttonBorderLeftPin = 2;
const int buttonBorderRightPin = 4;
const int buttonBorderUpPin = 7;
const int buttonBorderDownPin = 8;

const int inputTolleranceX = 1;
const int inputTolleranceY = 1;
const int inputOffsetX = 0; //Has to be adjusted if sensorValueX ≠ 511 or 512
const int inputOffsetY = 0; //Has to be adjusted if sensorValueY ≠ 511 or 512
const int antiGravity = 5/10; //Prevents plane from going down too fast

int sensorValueX = 0;  
int sensorValueY = 0;

int outputValueX = 0;       
int outputValueY = 0;       

void setup() {
    Serial.begin(9600);

    pinMode(buttonBorderLeftPin, INPUT);
    pinMode(buttonBorderRightPin, INPUT);
    pinMode(buttonBorderUpPin, INPUT);
    pinMode(buttonBorderDownPin, INPUT);
}

void loop() {

    /*Border detection
    buttonBorderLeftState = digitalRead(buttonBorderLeftPin);
    buttonBorderRightState = digitalRead(buttonBorderRightPin);
    buttonBorderUpState = digitalRead(buttonBorderUpPin);
    buttonBorderDownState = digitalRead(buttonBorderDownPin);

    if(buttonBorderLeftState == HIGHT) {
        analogWrite(pwmPinXpos, 250);
        delay(500);
        analogWrite(pwmPinXpos, 0);
    }
    if(buttonBorderRightState == HIGHT) {
        analogWrite(pwmPinXneg, 250);
        delay(500);
        analogWrite(pwmPinXneg, 0);
    }

    if(buttonBorderUpState == HIGHT) {
        analogWrite(pwmPinYpos, 250);
        delay(500);
        analogWrite(pwmPinYpos, 0);
    }
    if(buttonBorderDownState == HIGHT) {
        analogWrite(pwmPinYneg, 250);
        delay(500);
        analogWrite(pwmPinYneg, 0);
    }
    */


    //X-movement
    sensorValueX = analogRead(analogInPinX);

    if (sensorValueX >= (512 + inputTolleranceX + inputOffsetX)) {
        outputValueX = map(sensorValueX,  512 + inputOffsetX, 1023, 0, 255);
        analogWrite(pwmPinXneg, 0);
        analogWrite(pwmPinXpos, outputValueX);
    }

    else if (sensorValueX <= (511 - inputTolleranceX + inputOffsetX)) {
        outputValueX = map(sensorValueX, 511 + inputOffsetX, 0, 0, 255);
        analogWrite(pwmPinXpos, 0);
        analogWrite(pwmPinXneg, outputValueX);
    }

    else{
        outputValueX = 0;
        analogWrite(pwmPinXpos, outputValueX);
        analogWrite(pwmPinXneg, outputValueX);
    }

    //Y-movement
    sensorValueY = analogRead(analogInPinX);

    if (sensorValueY >= (512 + inputTolleranceY + inputOffsetY)) {
        outputValueY = map(sensorValueY, 512 + inputOffsetY, 1023, 0, 255);
        analogWrite(pwmPinYneg, 0);
        analogWrite(pwmPinYpos, outputValueY);
    }

    else if (sensorValueY <= (511 - inputTolleranceY + inputOffsetY)) {
        outputValueY = map(sensorValueY, 511 + inputOffsetY, 0, 0, 255);
        analogWrite(pwmPinYpos, 0);        
        analogWrite(pwmPinYneg, outputValueY);
    }

    else{
        outputValueY = 0;
        analogWrite(pwmPinYpos, outputValueY);
        analogWrite(pwmPinYneg, outputValueY);
    }


    
    Serial.print("sensorX = ");
    Serial.print(sensorValueX);
    Serial.print("\t outputX = ");
    Serial.println(outputValueX);

    Serial.print("sensorY = ");
    Serial.print(sensorValueY);
    Serial.print("\t outputY = ");
    Serial.println(outputValueY);


    delay(1);
}
```







```c

const int analogInPinX = A1;
const int analogInPinY = A0; 
 
const int analogOutPin9 = 9; 
const int analogOutPin11 = 11;

const int OutPinX10 = 10;
const int OutPinX6 = 6;
//int yCorrection = 1/10; 

int sensorValueY = 0;
int sensorValueX = 0;  
      
int outputValueY = 0;   
int outputValueX = 0;     

void setup() {
  Serial.begin(9600);
}

void loop() {
    sensorValueX = analogRead(analogInPinX);

 if (sensorValueX > 515) {
  outputValueX = map(sensorValueX, 515, 1023, 0, 255);
  analogWrite(OutPinX10, outputValueX);
 }

else if (sensorValueX < 512) {
  outputValueX = map(sensorValueX, 513, 0, 0, 255);
  analogWrite(OutPinX6, outputValueX);
 }
else  if (sensorValueX = 513){
  outputValueX = 0;
  analogWrite(OutPinX10, outputValueX);
  analogWrite(OutPinX6, outputValueX);
}

// YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY  if (sensorValueX = 513)
  sensorValueY = analogRead(analogInPinY);

 if (sensorValueY > 500) {
  outputValueY = map(sensorValueY, 515, 1023, 0, 255);
  analogWrite(analogOutPin9, outputValueY);
 }

else if (sensorValueY < 495) {
  outputValueY = map(sensorValueY, 513, 0, 0, 255);
  analogWrite(analogOutPin11, outputValueY);
 }
else if (sensorValueY >495 ||sensorValueY<500){
  outputValueY = 0;
  analogWrite(analogOutPin11, outputValueY);
  analogWrite(analogOutPin9, outputValueY);
}

 
 
  Serial.print("sensor = ");
  Serial.print(sensorValueY);
  Serial.print("\t output = ");
  Serial.println(outputValueY);


  delay(1);
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
´´´c


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
