void setup() {
    //Inicializando uma porta de comunicacao entre o computador e o arduino
Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
       //Le a mensagem da porta serial
      char mensagem = Serial.read();
      //Escreve novamente a mensagem na porta serial
      Serial.print(mensagem);
  }
 
 }
