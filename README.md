# Mechanical Dogfight
Mechanical Dogfight ist Singleplayer Arcade-Spiel, bei dem es um einen Flugzeugkampf geht (engl. Dogfight). Der Spieler steuert ein Flugzeug, dass ein anderes automatisch gesteuertes Flugzeug verfolgt. Ziel ist es, das gegnerische Flugzeug mit einem Laser abzuschießen. Zu diesem Zeitpunkt ist nur das Spielerflugzeug fertig, weshalb es in diesem repository auch nur darum geht. Das zweite Flugzeug wäre vielleicht etwas für ein Folgeprojekt.

## Verwendete Bauteile
* 1 Arduino
* 1 5V Netzteil
* 1 Steckbrett
*   Steckbrettkabel
*   Holzplatten
* 1 DC-Motor-Controller
* 2 DC-Motoren
* 2 Zahnräder
* 2 Zahnstangen
* 2 Schienen
* 1 dünne Metallstange
* 1 Modellflugzeug
* 1 kleiner Laser
* 1 Joystick
* 4 Taster
* 4 1kΩ Widerstände

## Aufbau
Damit das Flugzeug alle Punkte erreichen kann haben wir ein mechanisches Bewegungssystem mit zwei Achsen gebaut. Wie genau dieses System aufgebaut ist zeigt folgende Grafik.

![image](https://user-images.githubusercontent.com/88386307/144764417-1840f16e-6fd4-458f-b5d3-6f260564718b.png)

Ein genaueres 3D Modell kann unter <code>3D Modell.3mf</code> in den Dateien des Repositorys eingesehen werden.

Außerdem findet sich [hier](https://www.youtube.com/watch?v=KiZhklhcncI) ein Vorführungsvideo aus der Ansicht von hinten, also vom späteren Inneren des Spielekastens. [Hier](https://www.youtube.com/watch?v=7guUQbI5MUM) findet sich ein Vorführungsvideo aus der Spieleransicht.

## Schaltplan
![image](https://user-images.githubusercontent.com/88386307/144762397-f52d4438-60af-4e12-a86d-8b91ff4a76ab.png)

Anmerkungen:

Der Joystick sieht in echt etwas anders aus, da es in der verwendeten Software (TinkerCAD) keinen gab.

Die Pins des Motor-Controllers müssen je nach Controller anders belegt werden.

## Code
//Input Pins um den Joystick auszulesen
const int joystickXInputPin = A1; //X-Achse des Joysticks
const int joystickYInputPin = A0; //Y-Achse des Joysticks

//PWM pins für den Motor-Controller
const int posXpwmPin = 10; //rechts
const int negXpwmPin = 6; //links
const int posYpwmPin = 9; //oben
const int negYpwmPin = 11; //unten

//Pins für die Taster an den rändern des Spiels 
const int buttonLeftPin = 2; //links
const int buttonRightPin = 4; //rechts
const int buttonTopPin = 7; //oben
const int buttonBottomPin = 8; //unten

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

//Variablen um den Status der Knöpfe an den rändern zwischenzuspeichern 
int buttonLeftState = 0;
int buttonRightState = 0;
int buttonTopState = 0;
int buttonBottomState = 0;

void setup() {
    Serial.begin(9600); //Startet den Plotter (für die Kallibrierung des Joysticks notwendig)

    //Legt die Pins, mit denen die Knöpfe gelesen werden als input fest
    pinMode(buttonLeftPin, INPUT);
    pinMode(buttonRightPin, INPUT);
    pinMode(buttonTopPin, INPUT);
    pinMode(buttonBottomPin, INPUT);
}

void loop() {
    //liest den Status der Taster aus und Speichert diese zwischen
    buttonLeftState = digitalRead(buttonLeftPin);
    buttonRightState = digitalRead(buttonRightPin);
    buttonTopState = digitalRead(buttonTopPin);
    buttonBottomState = digitalRead(buttonBottomPin);
    //X-movement
    sensorValueX = analogRead(joystickXInputPin); //Liest den Ausgabewert des Joysticks für die X-Achse aus und speichert diesen zwischen

    if (sensorValueX > (joystickXCenterValue + joystickXCenterTollerance) && buttonLeftState == LOW) { //Wenn der Joystick auf der X-Achse rechts von der Mitte ist und der Taster auf der rechten Seite nicht betätigt ist, dann:
        outputValueX = map(sensorValueX, joystickXCenterValue + joystickXCenterTollerance, joystickXMaxValue, 0, 255); //Konvertiert den Ausgabewert des Joysticks in eine geschwindigkeit für den Motor-Controller
        analogWrite(negXpwmPin, 0); //Setzt die geschwindigkeit des Motors nach links auf Null
        analogWrite(posXpwmPin, outputValueX); //Übermittelt die geschwindigkeit nach rechts an den Motor-Controller
    }
    else if (sensorValueX < (joystickXCenterValue - joystickXCenterTollerance) && buttonRightState == LOW) { //Wenn der Joystick auf der X-Achse links von der Mitte ist und der Taster auf der linken Seite nicht betätigt ist, dann:
        outputValueX = map(sensorValueX, joystickXCenterValue - joystickXCenterTollerance, joystickYMinValue, 0, 255); //Konvertiert den Ausgabewert des Joysticks in eine geschwindigkeit für den Motor-Controller
        analogWrite(posXpwmPin, 0); //Setzt die geschwindigkeit des Motors nach rechts auf Null
        analogWrite(negXpwmPin, outputValueX); //Übermittelt die geschwindigkeit nach links an den Motor-Controller
    }
    else{ //Wenn der Joystick in der Ausgangsposition ist, dann:
        outputValueX = 0; //setzt Variable für die Motorgeschwindigkeit auf 0

        //Übermittelt die geschwindigkeiten an den Motor-Controller
        analogWrite(posXpwmPin, outputValueX);
        analogWrite(negXpwmPin, outputValueX);
    }

    //Y-movement
    sensorValueY = analogRead(joystickYInputPin); //Liest den Ausgabewert des Joysticks für die Y-Achse aus und speichert diesen zwischen

    if (sensorValueY > (joystickYCenterValue + joystickYCenterTollerance) && buttonTopState == LOW) {  //Wenn der Joystick auf der Y-Achse oberhalb der Mitte ist und der Taster oben nicht betätigt ist, dann:
        outputValueY = map(sensorValueY, joystickYCenterValue + joystickYCenterTollerance, joystickYMaxValue, 0, 255); //Konvertiert den Ausgabewert des Joysticks in eine geschwindigkeit für den Motor-Controller
        analogWrite(negYpwmPin, 0); //Setzt die geschwindigkeit des Motors nach unten auf Null
        analogWrite(posYpwmPin, outputValueY); //Übermittelt die geschwindigkeit nach oben an den Motor-Controller
    }
    else if (sensorValueY < (joystickYCenterValue - joystickYCenterTollerance) && buttonBottomState == LOW) {  //Wenn der Joystick auf der Y-Achse unterhalb der Mitte ist und der Taster unten nicht betätigt ist, dann:
        outputValueY = map(sensorValueY, joystickYCenterValue - joystickYCenterTollerance, joystickYMinValue, 0, 255); //Konvertiert den Ausgabewert des Joysticks in eine geschwindigkeit für den Motor-Controller
        analogWrite(posYpwmPin, 0); //Setzt die geschwindigkeit des Motors nach oben auf Null
        analogWrite(negYpwmPin, outputValueY); //Übermittelt die geschwindigkeit nach unten an den Motor-Controller
    }
    else{
        outputValueY = 0; //setzt Variable für die Motorgeschwindigkeit auf 0

        //Übermittelt die geschwindigkeiten an den Motor-Controller
        analogWrite(posYpwmPin, outputValueY);
        analogWrite(negYpwmPin, outputValueY);
    }

    //Output für den Plotter (für die Kallibrierung)
    Serial.println("sensorX = ");
    Serial.print(sensorValueX);
    Serial.print("\t outputX = ");
    Serial.print(outputValueX);

    Serial.print("\tsensorY = ");
    Serial.print(sensorValueY);
    Serial.print("\t outputY = ");
    Serial.print(outputValueY);

    delay(1);
}
