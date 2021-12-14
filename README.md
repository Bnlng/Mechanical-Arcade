<h1>Mechanical Dogfight</h1>
<h3>Von Ben und Martin, 12bc</h3>

<h2>Inhaltsverzeichnis</h2>

<ul style="list-stlye-type:none">
    <li><a href="#einl">1. Einleitung</a></li>
    <li><a href="#proj">2. Das Projekt</a></li>
    <li><a href="#hard">3. Hardware</a></li>
    <ul>
        <li><a href="#aufb">3.1 Aufbau</a></li>
        <li><a href="#teil">3.2 Verwendete Bauteile</a></li>
        <li><a href="#schalt">3.3 Schaltplan</a></li>
    </ul>
    <li><a href="#soft">2. Software</a></li>
</ul>

<h2 id="einl">Einleitung</h2>

Dies ist die Projektseite für unser Informatikprojekt des ersten Halbjahres. 
    
<h2 id="proj">Das Projekt</h2>

"Mechanical Dogfight" ist ein Singleplayer Computerspiel auf Arduino-Basis, dessen Inhalt ein Luftkampf (eng. Dogfight) zwischen zwei Flugzeugen ist. Der Spieler steuert das Verfolgerflugzeug, eine Englische Supermarine Spitfire, mit einem Joystick. Das Besondere an diesem Spiel ist, dass es sich nicht auf einem Bildschirm abspielt, sondern mit echten Modellen der Flugzeuge welche sich zwei dimensional im Spielekasten bewegen können. Das Gegnerflugzeug wird automatisch vom Arduino gesteuert und muss vom Spieler mittels des Bordgeschützes getroffen werden. Zurzeit ist nur das Flugzeug des Spielers fertiggestellt, daher handelt es sich bei diesem Projekt erst einmal nur um eine Art „Proof of Concept“. Alles funktioniert, wie gedacht, weshalb wir das Projekt als vollen Erfolg ansehen.

<h2 id="hard">Hardware</h2>

<h3 id="aufb">Aufbau</h3>

Damit das Flugzeug alle Punkte erreichen kann haben wir ein mechanisches Bewegungssystem mit zwei Achsen gebaut. Wie genau dieses System aufgebaut ist zeigt folgende Grafik.

![image](https://user-images.githubusercontent.com/88386307/144764417-1840f16e-6fd4-458f-b5d3-6f260564718b.png)

Ein genaueres 3D Modell kann unter <code>3D Modell.3mf</code> in den Dateien des Repositorys eingesehen werden.

Außerdem findet sich [hier](https://www.youtube.com/watch?v=KiZhklhcncI) ein Vorführungsvideo aus der Ansicht von hinten, also vom späteren Inneren des Spielekastens. [Hier](https://www.youtube.com/watch?v=7guUQbI5MUM) findet sich ein Vorführungsvideo aus der Spieleransicht.

<h3 id="teil">Verwendete Bauteile</h3>

* Arduino
* Netzteil (mind. 6V)
* Steckbrett
* Steckbrettkabel
* Holzplatten
* DC-Motor-Treiber
* DC-Motoren
* Zahnräder
* Zahnstangen
* Schienen
* dünne Metallstange
* Modellflugzeug
* kleiner Laser
* Joystick
* Taster
* 1kΩ Widerstände

<h4>5V Netzteil</h4>

Dieses versorgt den Arduino und die Motoren mit Strom. Der Arduino Nano benötigt eine Spannungsversorgung von 7 bis 12V um arbeiten zu können. Eine besonders hohe Leistung muss das Netzteil nicht aufweisen, da das gesamte Projekt noch keine Ströme über 1A gezogen hat.

<h4>Arduino</h4>

Arduino ist eine Open Source Physical-Computing-Plattform. Es handelt sich um einen Microcontroller mit mehreren analogen und digitalen Ein und Ausgängen. Dieser ist das Herzstück unseres Projektes und für die verarbeitung der Steuersignale und später für das Steuern des Gegnerflugzeuges und das Punktezählen zuständig.
<h4>Joystick</h4>

<h4>DC-Motor-Treiber</h4>
 Hierbei handelt es sich um den L298N dual H-Bridge Driver. Dieser ermöglicht die Steuerung von zwei Gleichstrommotoren. Also die Änderung von Drehrichtung und Geschwindigkeit.

<h4>DC-Getriebemotoren</h4>

Diese sind für die Bewegung des Flugzeuges zuständig. Durch das Getriebe sind sie in der Lage deutlich mehr Drehmoment zu leisten. Dies ist für das Projekt notwendig, da die Motoren sonst nicht in der Lage wären auch nur eine Umdrehung zu machen.  

<h4>Joystic</h4>

Bei dem Joystick handelt es sich um einen Logitch-Wingman 

<h4>Taster</h4>

<h4>Weitere Bauteile</h4>

<h3 id="schalt">Schaltplan</h3>

![image](https://user-images.githubusercontent.com/88386307/146005848-2f45c6a0-38ad-49ec-bc33-91fe2b977dcd.png)

**Anmerkungen:** Da es in der verwendeten Software (TinkerCAD) keinen Joystick gab wird dieser durch zwei Potentiometer dargestellt was technich gesehen genau das gleiche ist. Die Pins des Motor-Controllers müssen je nach Controller anders belegt werden.

<h2 id="soft">Software</h2>

Die Programmiersprache von Arduino basiert auf c++, verfügt aber über zusätzliche befehle, genaueres über die Sprache kann [hier](https://www.arduino.cc/reference/de/) nachgelesen werden. Der gesamte Sketch wird im Folgenden Schritt für schritt erklärt, kann aber auch in den Dateien des Repositorys [ohne Erklärungen](https://github.com/Bnlng/Mechanical-Dogfight/blob/main/Arduino%20Code%20ohne%20Erkl%C3%A4rungen.ino) und [mit Erklärungen](https://github.com/Bnlng/Mechanical-Dogfight/blob/main/Arduino%20Code%20mit%20Erkl%C3%A4rungen.ino) eingesehen und heruntergeladen werden.

<details>
    <summary>Gesamter Sketch</summary>

```c
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
```
                                        
</details>

<h3>Schritt für Schritt Erklärung</h3>

<h4>1. Pins definieren</h4>

Als allererstes wird in Variablen gespeichert, welche Pins am Arduino für was zuständig sind. Die Pins A1 und A2 lesen die zwei verschiedenen Achsen des Joysticks aus, dabei wird pro Achse ein Wert von 0 bis 1023 ausgelesen. In der Ausgangsposition ist dieser Wert ca. 512 und wenn der Joystick beispielsweise nach oben gedrückt wird kann dieser Wert je nach Stelleung zwischen 513 und 1023 sein.

Als nächstes werden den verschiedenen Bewegungsrichtungen des Flugzeugs Pins zugewiesen, wenn diese Pins aktiviert werden gibt der Arduino ein PWM Signal ([mehr Infos](https://www.arduino.cc/en/Tutorial/Foundations/PWM)) über diesen Pin aus, der Motor-Controller lässt daraufhin den Motor (X- oder Y-Achse) in eine bestimmte Richtung drehen. Soll sich die Drehrichtung ändern muss der Pin ausgeschaltet und ein anderer angeschaltet werden. `posXpwmPin` bewegt das flugzeug nach rechts, `negXpwmPin` nach links, `posYpwmPin` nach oben und `negYpwmPin` nach unten. Die bennenung ist analog zum Koordinatensystem aus der Mathematik.

Danach werden die Pins für die Taster am Rand des Spiels definiert. Wird ein Taster gedrückt, so liest der dazugehörige Pin HIGH aus, wird er nicht gedrückt, dann LOW.

```c
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
```

<h4>2. Joystick Kalibrierung</h4>

Da der Joystick nicht perfekt ist gibt er in der ausgangsposition nicht genau 512 aus und bei voller Betätigung weder 0 noch 1023, dehalb muss jeder Joystick individuell Kalibriert werden. Dazu müssen über den Seriellen Motor des Arduinos die Output-Werte des Joysticks ausgelesen werden. Die Werte, die in der Ausgangsstellung ausgegeben werden müssen bei `joystickXCenterValue` und `joystickYCenterValue` eingetragen werden. Anschließen müssen die maximalen und minimalen Werte, die der Joystick ausgibt, wenn er so stark wie möglich gedrückt wird in die Dafür vorgesehenden Variablen eingetragen werden.

```c
//Joystick Kalibrierung
int joystickXMaxValue = 955; //Maximaler X-Wert, den der joystick ausgibt
int joystickXMinValue = 210; //Minimaler X-Wert, den der joystick ausgibt
int joystickXCenterValue = 516; //X-Wert, den der Joystick in der ausgangsposition ausgibt
int joystickXCenterTollerance = 6; //Tolleranz für die ausgangsposition des Joyticks auf der X-Achse

int joystickYMaxValue = 890; //Maximaler Y-Wert, den der joystick ausgibt
int joystickYMinValue = 155; //Minimaler Y-Wert, den der joystick ausgibt
int joystickYCenterValue = 522; //Y-Wert, den der Joystick in der ausgangsposition ausgibt
int joystickYCenterTollerance = 12; //Tolleranz für die ausgangsposition des Joyticks auf der Y-Achse
```

<h4>3. Zwischenspeicher Variablen</h4>
    
Dies sind die Variablen, in denen Werte im loop (der Teil des Sketches, der immer wieder wiederholt wird) zwischengespeichert werden. Die funktionen der Variablen werden im Code-Bock beschrieben.

```c
//Variablen um die Ausgabewerte (0-1023) des Joysticks im loop zwischenzuspeichern
int sensorValueX = 0;
int sensorValueY = 0;

//Variablen um die für den Motor-Controller konvertierten Ausgabewerte (0-255) des Joysticks im loop zwischenzuspeichern
int outputValueX = 0;
int outputValueY = 0;

//Variablen um den Status (HIGHT oder LOW) der Taster an den rändern zwischenzuspeichern 
int buttonLeftState = 0;
int buttonRightState = 0;
int buttonTopState = 0;
int buttonBottomState = 0;
```

<h4>4. Setup</h4>

Dieser Teil des Sketches wird nur ein einziges mal beim Starten des Arduinos ausgeführt. `Serial.begin(9600);` Legt die Datenrate in Bit pro Sekunde (Baud) für die serielle Datenübertragung fest und macht das Anzeigen von Daten über den Seriellen Monitor möglich. `pinMode(Pin, INPUT);` legt den Pin als Input fest.

```c
void setup() {
    Serial.begin(9600); (für die Kallibrierung des Joysticks notwendig)

    pinMode(buttonLeftPin, INPUT);
    pinMode(buttonRightPin, INPUT);
    pinMode(buttonTopPin, INPUT);
    pinMode(buttonBottomPin, INPUT);
}
```

<h4>5. loop</h4>

Alles innerhalb der geschwungenen Klammern von `void loop() {}` wird immer wieder ausgeführt. Um die Funktionsweise besser erklären zu können ist der loop in verschiedene Abschnitte gegliedert.

Als erstes werden die Taster ausgelesen und deren Zustand zwischengeseichert.

```c
void loop() {
    buttonLeftState = digitalRead(buttonLeftPin);
    buttonRightState = digitalRead(buttonRightPin);
    buttonTopState = digitalRead(buttonTopPin);
    buttonBottomState = digitalRead(buttonBottomPin);
```

Der Code in den nächsten Drei Abschnitten ist für die Bewegung des Flugzeugs auf der X-Achse zuständig. Zunächst wird der Ausgabewert des Joysticks für die X-Achse ausgelesen und gespeichert. Danach wird `if() {}` verwendet, dabei wird überprüft, ob die in der Klammer stehende bedingung erfüllt ist und falls dies so ist wird der Code zwischen den geschwungenen Klammern ausgeführt. Als bedingung muss in unserem Fall der Output vom Joystick größer sein als er ist, wenn der Joystick in der Ausgangsposition ist und der Taster an der rechten Seite darf nicht batätigt sein. Zwischen den geschwungenen Klammern wird zunächst mit Hilfe der `map()`-Funktion der Ausgabewert des Joysticks in einen Wert zwischen 0 und 255 konvertiert. Anschließend wird über `analogWrite(Pin, 0-255)` die geschwindigkeit des Motors nach links (falls vohanden) auf Null und die geschwindigkeit nach Rechts auf den eben konvertierten Wert gesetzt. 0 entspricht stillstand und 255 voller Geschwindigkeit.

```c
    sensorValueX = analogRead(joystickXInputPin); //Liest den Ausgabewert des Joysticks für die X-Achse aus und speichert diesen zwischen

    if (sensorValueX > (joystickXCenterValue + joystickXCenterTollerance) && buttonLeftState == LOW) {
        outputValueX = map(sensorValueX, joystickXCenterValue + joystickXCenterTollerance, joystickXMaxValue, 0, 255);
        analogWrite(negXpwmPin, 0); //Setzt die geschwindigkeit des Motors nach links auf Null
        analogWrite(posXpwmPin, outputValueX); //Übermittelt die geschwindigkeit nach rechts an den Motor-Controller
    }
```

`else if()` ist wie `if()`, allerdings wird es nur ausgeführt, wenn die bedingung von `if()` davor nicht erfüllt wurde. Die Bedingung ist diesmal ähnlich wie die davor, nur ist Alles invertiert, d.h., dass nicht die bewegung nach Recht geregelt wird, sondern die nach Links.

```c
    else if (sensorValueX < (joystickXCenterValue - joystickXCenterTollerance) && buttonRightState == LOW) { //Wenn der Joystick auf der X-Achse links von der Mitte ist und der Taster auf der linken Seite nicht betätigt ist, dann:
        outputValueX = map(sensorValueX, joystickXCenterValue - joystickXCenterTollerance, joystickYMinValue, 0, 255); //Konvertiert den Ausgabewert des Joysticks in eine geschwindigkeit für den Motor-Controller
        analogWrite(posXpwmPin, 0); //Setzt die geschwindigkeit des Motors nach rechts auf Null
        analogWrite(negXpwmPin, outputValueX); //Übermittelt die geschwindigkeit nach links an den Motor-Controller
    }
```

Abschließend wird eine Else-Anweisung verwendet, diese führt den Code in den Geschwungenen Klammern nur aus, wenn die beiden Bedingungen davor nicht erfüllt wurden. Der Code Setzt die geschwindigkeit des Motors (falls vorhanden) in beide Richtungen auf Null.

```c
    else{ //Wenn der Joystick in der Ausgangsposition ist, dann:
        outputValueX = 0; //setzt Variable für die Motorgeschwindigkeit auf 0

        //Übermittelt die geschwindigkeiten an den Motor-Controller
        analogWrite(posXpwmPin, outputValueX);
        analogWrite(negXpwmPin, outputValueX);
    }
```

<details>
    <summary>Das Gleiche für die Y-Achse</summary>

```c
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
```

</details>

<h4>6. Output für den Plotter</h4>

Als allerletztes werden verschiedene Werte an den Seriellen Monitor übermitteltu. Dies wird nur zur Kalibrirung des Joysticks und zur Fehlerbehebung benötigt.

```c
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
```
