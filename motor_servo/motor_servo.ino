/ ************************************************************************************************************
* Programador..: Lourenço Moreira
* Data.........: 20/01/25
* Observações..: Construção de um circutio que permite controlar um motor servo através de um potênciometro.
/ ************************************************************************************************************

#include <Servo.h>

const byte POT_PIN = A0, SERVO_PIN = 9;
const int BAUD_RATE = 9600;

Servo myServo;

int potenciometro;

void setup() {
  myServo.attach(SERVO_PIN);

  pinMode(POT_PIN, INPUT);

  Serial.begin(BAUD_RATE);
}

void loop() {
  potenciometro = analogRead(POT_PIN);

  angulo = map(potenciometro, 0, 1023, 0, 180);
  myServo.write(angulo);

  Serial.println("Pot:" + (String(potenciometro) + "Angulo" + String(angulo));
}