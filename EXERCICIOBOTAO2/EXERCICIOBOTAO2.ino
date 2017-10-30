  const int pinoLedVermelho = 12;
  const int pinoLedVerde = 13;
  const int pinoBotao = 11;
  int estadoBotao = LOW;
  int ultimoAcesso;
  
void setup() {
pinMode(pinoLedVermelho, OUTPUT);
pinMode(pinoLedVerde, OUTPUT);
pinMode(pinoBotao, INPUT);

}

void loop() {
  estadoBotao = digitalRead (pinoBotao);
  if (estadoBotao == HIGH) 
  {
    digitalWrite(pinoLedVermelho, HIGH);
    digitalWrite (pinoLedVerde, LOW);
  }
  estadoBotao = digitalRead (pinoBotao);
  if (estadoBotao == HIGH)
  {
    digitalWrite(pinoLedVermelho, LOW);
    digitalWrite (pinoLedVerde, HIGH);
  }
    
}
