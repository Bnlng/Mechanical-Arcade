//Input Pins um den Joystick auszulesen
const int joystickXInputPin = A1; //X-Achse des Joysticks
const int joystickYInputPin = A0; //Y-Achse des Joysticks

//PWM pins für den Motor-Controller
const int posXpwmPin = 10; //rechts
const int negXpwmPin = 6; //links
const int posYpwmPin = 9; //oben
const int negYpwmPin = 11; //unten

//Pins für die schalter an den rändern des Spiels 
const int buttonBorderLeftPin = 2; //links
const int buttonBorderRightPin = 4; //rechts
const int buttonBorderTopPin = 7; //oben
const int buttonBorderBottomPin = 8; //unten

//Joystick Kalibrierung
int joystickXMaxValue = 955; //Maximaler X-Wert, den der joystick ausgibt
int joystickXMinValue = 210; //Minimaler X-Wert, den der joystick ausgibt
int joystickXCenterValue = 516; //X-Wert, den der Joystick in der ausgangsposition ausgibt
int joystickXCenterTollerance = 6; //Tolleranz für die ausgangsposition des Joyticks auf der X-Achse

int joystickYMaxValue = 890; //Maximaler Y-Wert, den der joystick ausgibt
int joystickYMinValue = 155; //Minimaler Y-Wert, den der joystick ausgibt
int joystickYCenterValue = 522; //Y-Wert, den der Joystick in der ausgangsposition ausgibt
int joystickYCenterTollerance = 12; //Tolleranz für die ausgangsposition des Joyticks auf der Y-Achse

//Variablen um die Ausgabewerte des Joysticks im loop zwischenzuspeichern
int sensorValueX = 0; 
int sensorValueY = 0;

//Variablen um die konvertierten Ausgabewerte des Joysticks im loop zwischenzuspeichern
int outputValueX = 0;
int outputValueY = 0;

void setup() {
    Serial.begin(9600); //Startet den Plotter (für die kallibrierung notwendig)

    //Legt die Pins um die Knöpfe auszulesen als input fest
    pinMode(buttonBorderLeftPin, INPUT);
    pinMode(buttonBorderRightPin, INPUT);
    pinMode(buttonBorderTopPin, INPUT);
    pinMode(buttonBorderBottomPin, INPUT);
}

void loop() {
    //X-movement
    sensorValueX = analogRead(joystickXInputPin);

    if (sensorValueX > (joystickXCenterValue + joystickXCenterTollerance) && digitalRead(buttonBorderLeftPin) == LOW) {
        outputValueX = map(sensorValueX, joystickXCenterValue + joystickXCenterTollerance, joystickXMaxValue, 0, 255); 
        analogWrite(negXpwmPin, 0);
        analogWrite(posXpwmPin, outputValueX);
    }
    else if (sensorValueX < (joystickXCenterValue - joystickXCenterTollerance) && digitalRead(buttonBorderRightPin) == LOW) {
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

    if (sensorValueY > (joystickYCenterValue + joystickYCenterTollerance) && digitalRead(buttonBorderTopPin) == LOW) {
        outputValueY = map(sensorValueY, joystickYCenterValue + joystickYCenterTollerance, joystickYMaxValue, 0, 255);
        analogWrite(negYpwmPin, 0);
        analogWrite(posYpwmPin, outputValueY);
    }
    else if (sensorValueY < (joystickYCenterValue - joystickYCenterTollerance) && digitalRead(buttonBorderBottomPin) == LOW) {
        outputValueY = map(sensorValueY, joystickYCenterValue - joystickYCenterTollerance, joystickYMinValue, 0, 255);
        analogWrite(posYpwmPin, 0);
        analogWrite(negYpwmPin, outputValueY);
    }
    else{
        outputValueY = 0;
        analogWrite(posYpwmPin, outputValueY);
        analogWrite(negYpwmPin, 0);
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