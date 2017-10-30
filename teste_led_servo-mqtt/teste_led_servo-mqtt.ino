
#include <SPI.h>
#include <UIPEthernet.h>
#include <utility/logging.h>
#include <PubSubClient.h>
#include <Servo.h>
#define SERVO 6 // Porta Digital 6 PWM

Servo portao; // Variável Servo
int pos; // Posição Servo

const int pinoBotaoPortao = 4; //botao portao
int estadoBotaoPortao = LOW;
int ultimoEstadoBotaoPortao = LOW;

const int pinoLed = 8;  //
const int pinoBotaoLed = 3;  //botao led
int estadoBotaoLed = LOW;
int ultimoEstadoBotaoLed = LOW;

//mqtt
// Update these with values suitable for your network.
byte mac[] = {0xDE, 0xED, 0xBA, 0xFE, 0xF1, 0x61};//PEGAR MAC ADDRESS

// Callback function header
void callback(char *topic, byte *payload, unsigned int length);

EthernetClient ethClient;

// Dados do MQTT Cloud
PubSubClient client("m11.cloudmqtt.com", 10285, callback, ethClient);

// Funcçao que irá receber o retorno do servidor.
void callback(char *topic, byte *payload, unsigned int length)
{
  char c = payload[0];
  Serial.println(c);
  Serial.println(topic);

  if (topic == "Portao") {
     
  }

  byte *p = (byte *)malloc(length);
  memcpy(p, payload, length);
  free(p);
}

void setup ()
{
  portao.attach(SERVO);
  Serial.begin(9600);
  portao.write(0); // Inicia motor posição zero
  pinMode(pinoBotaoPortao, INPUT);
  pinMode(pinoLed, OUTPUT);
  pinMode(pinoBotaoLed, INPUT);
  Serial.println("Iniciando...");
Ethernet.begin(mac);

// Faz a conexão no cloud com nome do dispositivo, usuário e senha respectivamente
if (client.connect("AbrirOPT", "arduinonovo", "123"))
{
  // Envia uma mensagem para o cloud no topic portao
  client.publish("Portao", 1);

  // Conecta no topic para receber mensagens
  client.subscribe("Portao");
  //client.subscribe("Lampada");

  Serial.println("conectado Portao");
} else {
  Serial.println("erro ao conectar");
}
}

//mqtt




void loop()
{
  client.loop();
  estadoBotaoPortao = digitalRead(pinoBotaoPortao);
  if ( estadoBotaoPortao == HIGH ) {
    if (ultimoEstadoBotaoPortao == HIGH) {
      Serial.println("FechaPortao");
      FechaPortao();

    } else {
      Serial.println("AbrePortao");
      AbrePortao();

    }
    if (ultimoEstadoBotaoPortao == HIGH) {

      ultimoEstadoBotaoPortao = LOW;
    }
    else {

      ultimoEstadoBotaoPortao = HIGH;
    }
    delay(1000);
  }
  else {
    
    //delay(1000);
  }

  /// controle led
  estadoBotaoLed = digitalRead (pinoBotaoLed);
  //Serial.println("circuito led");
  if (estadoBotaoLed == HIGH) {
    
    if (ultimoEstadoBotaoLed == HIGH) {
      digitalWrite(pinoLed, LOW);
    } else {
      digitalWrite(pinoLed, HIGH);
    }

    if (ultimoEstadoBotaoLed == HIGH) {
      ultimoEstadoBotaoLed = LOW;

    } else {
      ultimoEstadoBotaoLed = HIGH;
    }
    
    delay(1000);

  }

}

void AbrePortao() {
  portao.write(90);
  delay(15);
}

void FechaPortao() {
  portao.write(1);
  delay(15);
}



