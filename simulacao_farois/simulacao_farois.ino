/*
	Programador....: (C) 2025 Lourenço Moreira
    Data...........: 07/01/25
    Observações....: Construção de uma simulação luminosa 
    semelhante aos faróis do carro K.I.T.T da série televisiva
    Knight Rider
*/

const byte pinosLeds [] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup(void) {
  for(byte indice = 0; indice <= 9; indice++) {
    pinMode(pinosLeds[indice], OUTPUT);
  }
}

void loop(void) {
  for(byte indice = 9; ((indice >= 0) && (indice <= 9)); indice--) {
  	digitalWrite(pinosLeds[indice], HIGH);
  	delay(100);
  	digitalWrite(pinosLeds[indice], LOW);
  	delay(100);
	}
  for(byte indice = 0; ((indice >= 0) && (indice <=9)); indice++) {
    digitalWrite(pinosLeds[indice], HIGH);
    delay(100);
    digitalWrite(pinosLeds[indice], LOW);
    delay(100);
    }
}