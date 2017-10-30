  const int pinoLed = 8;
  const int pinoBotao = 3;
  int estadoBotao = LOW;
  
void setup() {
pinMode(pinoLed, OUTPUT);
pinMode(pinoBotao, INPUT);

}

void loop() {
  estadoBotao = digitalRead (pinoBotao);
  if (estadoBotao == HIGH) {
    digitalWrite(pinoLed, HIGH);
  }
  else 
  {  
    digitalWrite (pinoLed, LOW);
  }
}
