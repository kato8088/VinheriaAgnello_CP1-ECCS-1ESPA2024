/*
(tinkercad) LDR - valor analogico na prática, de 54 a 974 (com 5v) (tinkercad)
(tinkercad) leitura resistencia LDR (tinkercad)
0% - 506ohms
50% - 1k
100% - 180k

referencia ldr teste: ± 20% do limite

analogRead mede voltagem
referencia: 0.0049 volts (4.9 mV) per unit
*/

#define LDR_PIN A5
#define ledVermelho 2
#define ledAmarelo 3
#define ledVerde 4
#define debugLed 13
#define buzzer 5

int ldrValue;

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
  if (analogRead(LDR_PIN) > 849) {
    Serial.println("Luminosidade: Alerta!");
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    return 1;
  }
  if ( 849 > analogRead(LDR_PIN) and analogRead(LDR_PIN) > 799) {
    Serial.println("Luminosidade: Atencao!");
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    return 0;
  }
  if (analogRead(LDR_PIN) < 800) {
    Serial.println("Luminosidade: normal");
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
    return 0;
  }
}

void loop(){
  
  luxTick();
  //debug start
  Serial.println(luxTick());
  //debug end
  while(luxTick() == 1){
    digitalWrite(buzzer, HIGH);
    delay(3000);
    digitalWrite(buzzer, LOW);
    // debug start
    digitalWrite(debugLed, HIGH);
    // debug end
  }
  else {

    //debug start
  digitalWrite(debugLed, LOW);
    //debug end
  }
  ldrValue = analogRead(LDR_PIN);
  //debug
  Serial.println(ldrValue);
  delay(500);
  //debug
}