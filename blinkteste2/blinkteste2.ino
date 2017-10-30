// Criação de variáveis
// int = integer
// pinoledvermelho =  nome da variável
// 11 = nome do pino que queremos controlar - valor da variavel
int pinoLedVermelho = 12;

// Setup = função/trecho de código que é executado uma única vez ao gravar o código no arduino
void setup() {
  // Função que configura a porta como input ou output
  // Tome cuidado com os nomes, pois a linguagem é case sensitive
  pinMode(pinoLedVermelho, OUTPUT);
}

void loop() {
  // estrutura de repetição que entra em atividade no momento que o código for gravado no arduino, logo após a execução do setup
  digitalWrite (pinoLedVermelho, HIGH);
  delay(1000);
  digitalWrite (pinoLedVermelho, LOW);
  delay(1000);
}
