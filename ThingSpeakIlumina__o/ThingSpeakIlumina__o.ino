#include <ThingSpeak.h>
#include <SPI.h>
#include <UIPEthernet.h>
#include <utility/logging.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xE1, 0x32};
EthernetClient client;

int portaLDR = A5; //Porta analógica utilizada pelo LDR

unsigned long myChannelNumber = 366137;
const char * myWriteAPIKey = "S6SZENSQWQ6Z5OSN";
int fieldNumber = 1;

void setup() {
  Ethernet.begin(mac);
  ThingSpeak.begin(client);
}

void loop() {
  int estado = analogRead(portaLDR);  //Lê o valor fornecido pelo LDR
  ThingSpeak.writeField(myChannelNumber, 2, estado, myWriteAPIKey);
  delay(10000);
}
