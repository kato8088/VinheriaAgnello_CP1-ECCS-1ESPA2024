/*
2do:
- ajustar os valores do ldr na prática, no simulador está instável
- ajustar o delay dos buzzers
- fazer sons diferentes para atencao e alerta
- colocar lcd
*/

#define LDR_PIN A5
#define ledVermelho 2
#define ledAmarelo 3
#define ledVerde 4
#define debugLed 13
#define buzzer 5

int intensidadeLDR;


void setup(){
  Serial.begin(9600);
  pinMode(debugLed, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(buzzer, OUTPUT);
}

int luxTick(){
  intensidadeLDR = map(analogRead(LDR_PIN), 40, 999, 0, 100);

  if (intensidadeLDR > 50) {
    Serial.println(" Luminosidade: Alerta!");
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    //fine tune in real hardware l8r
    digitalWrite(buzzer, LOW);
  }
  if (41 < intensidadeLDR and intensidadeLDR < 50) {
    Serial.println(" Luminosidade: Atencao!");
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    //fine tune in real hardware l8r
  }
  if (intensidadeLDR < 40) {
    Serial.println(" Luminosidade: normal");
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
  }
}

void loop(){
  
  luxTick();

  Serial.print("Intensidade da Luz: ");
  Serial.println(intensidadeLDR);
  
  delay(1000);
  // fine tune in real hardware l8r
}