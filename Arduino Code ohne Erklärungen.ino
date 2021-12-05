//Arduino Pins
const int joystickXInputPin = A1;
const int joystickYInputPin = A0;

const int posXpwmPin = 10;
const int negXpwmPin = 6;
const int posYpwmPin = 9;
const int negYpwmPin = 11;

const int buttonLeftPin = 2;
const int buttonRightPin = 4;
const int buttonTopPin = 7;
const int buttonBottomPin = 8;

//Joystick callibration
int joystickXMaxValue = 955;
int joystickXMinValue = 210;
int joystickXCenterValue = 511;
int joystickXCenterTollerance = 20;

int joystickYMaxValue = 890;
int joystickYMinValue = 155;
int joystickYCenterValue = 512;
int joystickYCenterTollerance = 20;


int sensorValueX = 0;
int sensorValueY = 0;

int outputValueX = 0;
int outputValueY = 0;

int buttonLeftState = 0;
int buttonRightState = 0;
int buttonTopState = 0;
int buttonBottomState = 0;

void setup() {
    Serial.begin(9600);

    pinMode(buttonLeftPin, INPUT);
    pinMode(buttonRightPin, INPUT);
    pinMode(buttonTopPin, INPUT);
    pinMode(buttonBottomPin, INPUT);
}

void loop() {
    buttonLeftState = digitalRead(buttonLeftPin);
    buttonRightState = digitalRead(buttonRightPin);
    buttonTopState = digitalRead(buttonTopPin);
    buttonBottomState = digitalRead(buttonBottomPin);

    //X-movement
    sensorValueX = analogRead(joystickXInputPin);

    if (sensorValueX > (joystickXCenterValue + joystickXCenterTollerance) && buttonLeftState == LOW) {
        outputValueX = map(sensorValueX, joystickXCenterValue + joystickXCenterTollerance, joystickXMaxValue, 0, 255); 
        analogWrite(negXpwmPin, 0);
        analogWrite(posXpwmPin, outputValueX);
    }
    else if (sensorValueX < (joystickXCenterValue - joystickXCenterTollerance) && buttonRightState == LOW) {
        outputValueX = map(sensorValueX, joystickXCenterValue - joystickXCenterTollerance, joystickYMinValue, 0, 255);
        analogWrite(posXpwmPin, 0);
        analogWrite(negXpwmPin, outputValueX);
    }
    else{
        outputValueX = 0;
        analogWrite(posXpwmPin, outputValueX);
        analogWrite(negXpwmPin, outputValueX);
    }

    //Y-movement
    sensorValueY = analogRead(joystickYInputPin);

    if (sensorValueY > (joystickYCenterValue + joystickYCenterTollerance) && buttonTopState == LOW) {
        outputValueY = map(sensorValueY, joystickYCenterValue + joystickYCenterTollerance, joystickYMaxValue, 0, 255);
        analogWrite(negYpwmPin, 0);
        analogWrite(posYpwmPin, outputValueY);
    }
    else if (sensorValueY < (joystickYCenterValue - joystickYCenterTollerance) && buttonBottomState == LOW) {
        outputValueY = map(sensorValueY, joystickYCenterValue - joystickYCenterTollerance, joystickYMinValue, 0, 255);
        analogWrite(posYpwmPin, 0);
        analogWrite(negYpwmPin, outputValueY);
    }
    else{
        outputValueY = 0;
        analogWrite(posYpwmPin, outputValueY);
        analogWrite(negYpwmPin, outputValueY);
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
