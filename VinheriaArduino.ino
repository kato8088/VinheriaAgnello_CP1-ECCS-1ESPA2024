// Associando pinos físicos as suas funções correspondentes
#define pinoLDR A5
#define ledVermelho 6
#define ledAmarelo 7
#define ledVerde 8
#define buzzer 9


int intensidadeLDR; // Declarando a variável global do nível de luminosidade detectado pelo LDR


void setup(){
  // Setando a baud rate da comunicação serial e o tipo do I/O dos pinos
  Serial.begin(9600);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(pinoLDR, INPUT);
  pinMode(buzzer, OUTPUT);
}

int luxTick(){
  // Função de checagem da luminosidade e I/O dos LEDs, LDR e buzzer
  intensidadeLDR = map(analogRead(pinoLDR), 45, 990, 0, 100); // função map() usada para criar uma range calibrada para o LDR de 0 a 100

  // Condições da checagem da luminosidade e subsequentes ações
  if (intensidadeLDR > 67) {
    Serial.println(" Luminosidade: Alerta!");
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(buzzer, HIGH);
    delay(3000);
    digitalWrite(buzzer, LOW);
    delay(2000); // Complemento do timer de 3 segundos para a disparada do buzzer
  }
  if (34 < intensidadeLDR and intensidadeLDR < 66) {
    Serial.println(" Luminosidade: Atencao!");
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(buzzer, HIGH);
    delay(1500);
    digitalWrite(buzzer, LOW);
    delay(2000); // Complemento do timer de 3 segundos para a disparada do buzzer
  }
  if (intensidadeLDR < 33) {
    Serial.println(" Luminosidade: normal");
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
  }
}

void loop(){
  // Função de loop principal do sistema para rodar indefinidamente
  luxTick();

  // Código para informar a intensidade da luz via Serial
  Serial.print("Intensidade da Luz: ");
  Serial.println(intensidadeLDR);
  
  // Delay geral complementar ao buzzer e para não sobrecarregar o Arduino
  delay(1000);
}