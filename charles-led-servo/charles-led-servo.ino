#include <Servo.h>

const int portaLed = 7;
const int portaBotaoLed = 4;
const int portaBotaoPortao = 2;
const int portaMotorPortao = 6;
const int velocidadePortao = 5;

int statusLed = LOW;
int statusBotaoLed = LOW;
int statusBotaoPortao = LOW;
int statusPortao = LOW;

Servo portao;

void setup()
{
  Serial.begin(9600);
  
  pinMode(portaLed, OUTPUT);
  pinMode(portaBotaoLed, INPUT);
  pinMode(portaBotaoPortao, INPUT);
  
  portao.attach(portaMotorPortao);
}

void loop()
{
  int estadoBotao = digitalRead(portaBotaoLed);
  int estadoBotaoPortao = digitalRead(portaBotaoPortao);  
  
  verificaEstadoBotaoLed(estadoBotao);
  verificaEstadoBotaoPortao(estadoBotaoPortao); 
}

void verificaEstadoBotaoLed(int estado){
  if(estado != statusBotaoLed){
    if(estado == HIGH){
      if(statusLed == HIGH){
        acendeApagaLed(portaLed, LOW);
      }else{
        acendeApagaLed(portaLed, HIGH);    
      }
    }
    statusBotaoLed = estado;
  }
}

void verificaEstadoBotaoPortao(int estado){
  if(estado != statusBotaoPortao){
    if(estado == HIGH){
      if(statusPortao == HIGH){
        abreFechaPortao(false);
      }else{
        abreFechaPortao(true);
      }
    }
    statusBotaoPortao = estado;
  }
}

void acendeApagaLed(int pino, int status){
  digitalWrite(pino, status);
  statusLed = status;
}

void abreFechaPortao(bool abre){
  if(abre){
    for(int pos = 0; pos <= 90; pos++){
      portao.write(pos);
      delay(velocidadePortao);
    }
    statusPortao = HIGH;
  }else{
    for(int pos = 90; pos >= 0; pos--){
      portao.write(pos);
      delay(velocidadePortao);
    }
    statusPortao = LOW;
  }
}
