/*
 Programador...: (c) 2024 Lourenço Moreira
 Data..........: 18/12/24
 Designação....: Estudo do sinal PWM
*/

const int BAUD_RATE = 9600;
const byte PINO_POTENCIOMETRO = A0;
const byte PINO_LED = 6;

int conversao;

void setup() {
  Serial.begin(BAUD_RATE);
  
  pinMode(PINO_POTENCIOMETRO, INPUT);
  pinMode(PINO_LED, OUTPUT);
}

void loop() {
  int leitura = analogRead(PINO_POTENCIOMETRO);
  Serial.println(leitura);
  
  conversao = map(leitura, 0, 1023, 0, 255);
  
  analogWrite(PINO_LED, conversao);
  
  delay(10);
}