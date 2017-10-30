int Led = 13;

void setup() {
    //Inicializando uma porta de comunicacao entre o computador e o arduino
Serial.begin(9600);
pinMode(Led, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
       //Le a mensagem da porta serial
      char mensagem = Serial.read();
       
      if (mensagem == '1')
      
      digitalWrite (Led, HIGH);
      delay(2000);    
  }
     else
     {
      digitalWrite(Led, LOW);
      }
 }

