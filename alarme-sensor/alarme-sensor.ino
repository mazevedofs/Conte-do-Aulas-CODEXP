int portaSensorTMP = A0;
int valorSensorTMP;
float temperatura = 0;
int buzzer = 12;

void setup()
{
 Serial.begin(9600);
 pinMode (buzzer, OUTPUT);
}

void loop()
{
 valorSensorTMP = analogRead(portaSensorTMP);
 temperatura = valorSensorTMP * 0.1075268817204301;
  Serial.println(temperatura);
  if (temperatura > 15){
    tone (buzzer, 2000);
  }
}
