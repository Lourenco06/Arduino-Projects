/* 
 Programador..: Lourenço Moreira (c)
 Data.........: 17/12/24
 Observações..: Led + Botão
 */

const byte PINO_LED = 12;
const byte PINO_BOTAO = 4;

byte estadoBotao;
byte ultimoEstadoBotao = LOW;
unsigned long tempoUltimoDebounce = 0;
unsigned long tempoDebounce = 50;

void setup(void) {
  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_BOTAO, INPUT_PULLUP); // Usando resistor pull-up interno
}

void loop(void) {
  lerEstadoBotao();
  
  // Inverter a lógica porque agora usamos o pull-up interno
  if (estadoBotao == LOW) {
    digitalWrite(PINO_LED, HIGH);
  } else {
    digitalWrite(PINO_LED, LOW);
  }
}

void lerEstadoBotao() {
  int leitura = digitalRead(PINO_BOTAO);
  
  if (leitura != ultimoEstadoBotao) {
    tempoUltimoDebounce = millis();
  }
  
  if ((millis() - tempoUltimoDebounce) > tempoDebounce) {
    if (leitura != estadoBotao) {
      estadoBotao = leitura;
    }
  }
  
  ultimoEstadoBotao = leitura;
}