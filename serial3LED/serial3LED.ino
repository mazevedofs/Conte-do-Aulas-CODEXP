int LedRed = 11;
int LedYellow = 12;
int LedGreen = 13;

void setup() {
    //Inicializando uma porta de comunicacao entre o computador e o arduino
Serial.begin(9600);
pinMode(LedRed, OUTPUT);
pinMode(LedYellow, OUTPUT);
pinMode(LedGreen, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
       //Le a mensagem da porta serial
      char mensagem = Serial.read();
      Serial.println(mensagem);
       
            if (mensagem == 'R'){
            digitalWrite (LedRed, HIGH);
            digitalWrite (LedYellow, LOW);
            digitalWrite (LedGreen, LOW);
            }
            if (mensagem == 'Y'){
            digitalWrite (LedRed, LOW);
            digitalWrite (LedYellow, HIGH);
            digitalWrite (LedGreen, LOW);
            }
            if (mensagem == 'G'){
            digitalWrite (LedRed, LOW);
            digitalWrite (LedYellow, LOW);
            digitalWrite (LedGreen, HIGH);
            }
      
      }
}   


