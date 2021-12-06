# Mechanical Dogfight
Mechanical Dogfight ist Singleplayer Arcade-Spiel, bei dem es um einen Flugzeugkampf geht (engl. Dogfight). Der Spieler steuert ein Flugzeug, dass ein anderes automatisch gesteuertes Flugzeug verfolgt. Ziel ist es, das gegnerische Flugzeug mit einem Laser abzuschießen. Zu diesem Zeitpunkt ist nur das Spielerflugzeug fertig, weshalb es in diesem repository auch nur darum geht. Das zweite Flugzeug wäre vielleicht etwas für ein Folgeprojekt.

## Materialliste
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

## Schaltplan
![image](https://user-images.githubusercontent.com/88386307/144762397-f52d4438-60af-4e12-a86d-8b91ff4a76ab.png)

Anmerkungen:

Der Joystick sieht in echt etwas anders aus, da es in der verwendeten Software (TinkerCAD) keinen gab.

Die Pins des Motor-Controllers müssen je nach Controller anders belegt werden.

## Code
`Arduino Code ohne Erklärungen.ino` enthält den Code, der auf dem Arduino läuft.

`Arduino Code mit Erklärungen.ino` enthält den gleichen Code, aber mit zusätzlichen Erläuterungen.
