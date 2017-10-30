#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Endereço fisico do arduino na rede
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xF1, 0x35 };

// Função que será executada toda vez que o arduino receber uma mensagem dafila
void callback(char* topic, byte* mensagem, unsigned int length) {
  char* msg = mensagem;

  if(topic == "Lampada"){
    if(msg == "1"){
      acendeApagaLed(portaLed, HIGH);
    }  
  }
  
}

EthernetClient ethClient;

// Cliente de conexão com o mqtt
PubSubClient client("m11.cloudmqtt.com", 10285, callback, ethClient);

void setup()
{

  // Inicializa a conexão na rede de internet
  Ethernet.begin(mac);

  // Tenta se conectar ao servidor de MQTT
  if (client.connect("arduinoClient","Arduino2","teste")) {
    // Se inscreve em uma fila de comunicação
    client.subscribe("Portao");
    //client.subscribe("Lampada");
  }
}

void loop()
{
  client.loop();
}
