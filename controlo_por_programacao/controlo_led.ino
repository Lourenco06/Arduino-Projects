/*
Programador......: (C) Lourenço Moreira
Data..................: 17/01/2025
Observações......: Controlo de um led vermelho.
*/

//Constantes
const int PINO_LED = 7;
const int TEMPO_ESPERA_MS = 1000;

//Inicializações
void setup(void) {
pinMode(PINO_LED, OUTPUT);
}

//Programa principal
void loop(void) {
digitalWrite(PINO_LED, HIGH);
delay(TEMPO_ESPERA_MS);
digitalWrite(PINO_LED, LOW);
delay(TEMPO_ESPERA_MS);
}