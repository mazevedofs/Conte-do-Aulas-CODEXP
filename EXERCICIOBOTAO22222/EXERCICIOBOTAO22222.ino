  const int pinoLedVermelho = 12;
  const int pinoLedVerde = 13;
  const int pinoBotao = 11;
  int estadoBotao = LOW;
  int ultimoAcesso = 12;
  int ultimoEstadoBotao = LOW;
  
void setup() {
pinMode(pinoLedVermelho, OUTPUT);
pinMode(pinoLedVerde, OUTPUT);
pinMode(pinoBotao, INPUT);

}

void loop() {
  estadoBotao = digitalRead (pinoBotao);
  if (estadoBotao == HIGH) 
  {
    if (ultimoAcesso == pinoLedVermelho)
    {
    digitalWrite(pinoLedVermelho, HIGH);
    digitalWrite (pinoLedVerde, LOW);
    ultimoAcesso = pinoLedVerde;
  }
  
  else 
  {
     digitalWrite (pinoLedVerde, HIGH);
     digitalWrite(pinoLedVermelho, LOW);
     ultimoAcesso = pinoLedVermelho;
  }
  }
}
