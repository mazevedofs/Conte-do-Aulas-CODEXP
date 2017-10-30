int LedRed = 11;
int LedYellow = 12;
int LedGreen = 13;
int pinoBuzzer = 3;

void setup() {
    //Inicializando uma porta de comunicacao entre o computador e o arduino
Serial.begin(9600);
pinMode(LedRed, OUTPUT);
pinMode(LedYellow, OUTPUT);
pinMode(LedGreen, OUTPUT);
pinMode(pinoBuzzer, OUTPUT);
}

void acendeApagaPrimeiroLed (int acendeLed, int apagaLed1, int apagaLed2){
  //funcao- ao digitar a funcao, ela vai precisar das 3 int(variaveis), que vao se comportar na ordem dos comandos abaixo
  digitalWrite(acendeLed, HIGH);
  digitalWrite(apagaLed1, LOW);
  digitalWrite(apagaLed2, LOW);

  }

void acendeTodosLeds (int acende1, int acende2, int acende3){
  //funcao- ao digitar a funcao, ela vai precisar das 3 int(variaveis), que vao se comportar na ordem dos comandos abaixo
  digitalWrite(acende1, HIGH);
  digitalWrite(acende2, HIGH);
  digitalWrite(acende3, HIGH);
}
void apagaTodosLeds (int apaga1, int apaga2, int apaga3){
  //funcao- ao digitar a funcao, ela vai precisar das 3 int(variaveis), que vao se comportar na ordem dos comandos abaixo
  digitalWrite(apaga1, LOW);
  digitalWrite(apaga2, LOW);
  digitalWrite(apaga3, LOW);
  }
  
void loop() {
  if (Serial.available() > 0) {
       //Le a mensagem da porta serial
      char mensagem = Serial.read();
      Serial.println(mensagem);
       
          switch (mensagem) {
          case 'R':
            acendeApagaPrimeiroLed (LedRed, LedYellow, LedGreen);
            break;
          case 'Y':
              acendeApagaPrimeiroLed (LedYellow, LedGreen, LedRed);
            break;
          case 'G': 
              acendeApagaPrimeiroLed (LedGreen, LedRed, LedYellow);
          break;
          case 'A': 
              acendeTodosLeds (LedRed, LedYellow, LedGreen);
          break;
          default: 
              //buzzer
              apagaTodosLeds (LedRed, LedYellow, LedGreen);
              tone(pinoBuzzer, 1000);
              delay(1000);
              noTone (pinoBuzzer);
              delay (1000);
             
          break;
        }
        
   }
    
}   


