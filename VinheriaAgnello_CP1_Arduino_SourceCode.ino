#include <LiquidCrystal.h> // Incluindo a biblioteca necessária para o funcionamento do LCD
LiquidCrystal lcd(12, 11, 5, 4,  3,  2); // RS, E,  D4, D5, D6, D7

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
  lcd.begin(16, 2); //definir o tipo do lcd
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(pinoLDR, INPUT);
  pinMode(buzzer, OUTPUT);
  splashScreen();    
}

int luxTick(){
  // Função de checagem da luminosidade e I/O dos LEDs, LDR e buzzer
  intensidadeLDR = map(analogRead(pinoLDR), 20, 1010, 0, 100); // função map() usada para criar uma range calibrada para o LDR de 0 a 100

  // Condições da checagem da luminosidade e subsequentes ações
  if (intensidadeLDR > 51) {
    Serial.println(" Luminosidade: Alerta!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nivel de Luz:");
    lcd.setCursor(0, 1);
    lcd.print(intensidadeLDR);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    for (int b=0; b<9; b++){
      delay(200);
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
    }
  }
  if (21 < intensidadeLDR and intensidadeLDR < 50) {
    Serial.println(" Luminosidade: Atencao!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nivel de Luz:");
    lcd.setCursor(0, 1);
    lcd.print(intensidadeLDR);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);

    for (int a=0; a<4; a++){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(500);
    }

   // Complemento do timer de 3 segundos para a disparada do buzzer
  }
  if (intensidadeLDR < 20) {
    Serial.println(" Luminosidade: normal");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nivel de Luz:");
    lcd.setCursor(0, 1);
    lcd.print(intensidadeLDR);
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
  
  // Delay geral para o reinício do código
  delay(400);
  
}

void splashScreen(){
  image00();//Primeiro frame
  delay(300);
  image01();//Segundo frame
  delay(300);
  image02();//Terceiro frame
  delay(300);
  image03();//Quarto frame
  delay(300);
  image04();//Quinto frame
  delay(300);
  image05();//Sexto frame
  delay(300);
  image06();//Sétimo frame
  delay(300);
  image07();//Oitavo frame
  delay(300);
  image08();//Nono frame
  delay(300);
  image09();//Décimo frame
  delay(300);
  image10();//Décimo primeiro frame
  delay(300);
  image11();//Décimo segundo frame
  delay(300);
  image12();//Décimo terceiro frame
  delay(300);
  image13();//Décimo quarto frame
  delay(300);
  image14();//Décimo quinto frame
  delay(300);
  image15();//Décimo sexto frame
  delay(300);
  image16();//Décimo sétimo frame
  delay(300);
  image17();//Décimo oitavo frame
  delay(300);
  image18();//Décimo nono frame
  delay(300);
  image19();//Vigésimo frame
 	image20(); //Moskitto
}

void image00() { //Primeiro frame
lcd.clear();
byte image20[8] = {B11111, B00111, B00010, B00100, B01000, B10000, B00000, B00000};
byte image21[8] = {B10110, B10100, B11010, B00010, B00001, B00000, B00000, B00000};
byte image05[8] = {B00000, B00000, B00000, B00001, B00010, B11010, B10100, B10110};
byte image04[8] = {B00000, B00000, B10000, B01000, B00100, B00010, B00111, B11111};
byte image03[8] = {B01110, B01001, B00100, B00010, B00010, B00010, B11111, B11111};
byte image19[8] = {B11111, B11111, B00010, B00010, B00010, B00100, B01001, B01110};
byte image02[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00010};
byte image18[8] = {B00010, B00001, B00000, B00000, B00000, B00000, B00000, B00000};
lcd.createChar(0, image20);
lcd.createChar(1, image21);
lcd.createChar(2, image05);
lcd.createChar(3, image04);
lcd.createChar(4, image03);
lcd.createChar(5, image19);
lcd.createChar(6, image02);
lcd.createChar(7, image18);
lcd.setCursor(3, 1);
lcd.write(byte(0));
lcd.setCursor(4, 1);
lcd.write(byte(1));
lcd.setCursor(4, 0);
lcd.write(byte(2));
lcd.setCursor(3, 0);
lcd.write(byte(3));
lcd.setCursor(2, 0);
lcd.write(byte(4));
lcd.setCursor(2, 1);
lcd.write(byte(5));
lcd.setCursor(1, 0);
lcd.write(byte(6));
lcd.setCursor(1, 1);
lcd.write(byte(7));
}


void image01() { //Segundo frame
lcd.clear();
byte image05[8] = {B00000, B00000, B00000, B10000, B01000, B00101, B01111, B11111};
byte image06[8] = {B00000, B00000, B00000, B00001, B00010, B10100, B01000, B01100};
byte image21[8] = {B11111, B01111, B00101, B01000, B10000, B00000, B00000, B00000};
byte image22[8] = {B01100, B01000, B10100, B00010, B00001, B00000, B00000, B00000};
byte image20[8] = {B11111, B11111, B00100, B00100, B00100, B01001, B10010, B11100};
byte image03[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00010};
byte image19[8] = {B00010, B00001, B00000, B00000, B00000, B00000, B00000, B00000};
byte image04[8] = {B11100, B10010, B01001, B00100, B00100, B00100, B11111, B11111};
lcd.createChar(0, image05);
lcd.createChar(1, image06);
lcd.createChar(2, image21);
lcd.createChar(3, image22);
lcd.createChar(4, image20);
lcd.createChar(5, image03);
lcd.createChar(6, image19);
lcd.createChar(7, image04);
lcd.setCursor(4, 0);
lcd.write(byte(0));
lcd.setCursor(5, 0);
lcd.write(byte(1));
lcd.setCursor(4, 1);
lcd.write(byte(2));
lcd.setCursor(5, 1);
lcd.write(byte(3));
lcd.setCursor(3, 1);
lcd.write(byte(4));
lcd.setCursor(2, 0);
lcd.write(byte(5));
lcd.setCursor(2, 1);
lcd.write(byte(6));
lcd.setCursor(3, 0);
lcd.write(byte(7));
}

void image02() {
lcd.clear();

byte image03[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00001};
byte image04[8] = {B00000, B00000, B00000, B00000, B00000, B00100, B11111, B11111};
byte image19[8] = {B00001, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte image20[8] = {B11111, B11111, B00100, B00000, B00000, B00000, B00000, B00000};
byte image05[8] = {B00000, B00000, B00000, B00000, B00000, B00101, B01111, B11111};
byte image21[8] = {B11111, B01111, B00101, B00000, B00000, B00000, B00000, B00000};
byte image06[8] = {B00000, B00000, B00000, B00001, B00010, B10100, B01000, B01100};
byte image22[8] = {B01100, B01000, B10100, B00010, B00001, B00000, B00000, B00000};
lcd.createChar(0, image03);
lcd.createChar(1, image04);
lcd.createChar(2, image19);
lcd.createChar(3, image20);
lcd.createChar(4, image05);
lcd.createChar(5, image21);
lcd.createChar(6, image06);
lcd.createChar(7, image22);
lcd.setCursor(2, 0);
lcd.write(byte(0));
lcd.setCursor(3, 0);
lcd.write(byte(1));
lcd.setCursor(2, 1);
lcd.write(byte(2));
lcd.setCursor(3, 1);
lcd.write(byte(3));
lcd.setCursor(4, 0);
lcd.write(byte(4));
lcd.setCursor(4, 1);
lcd.write(byte(5));
lcd.setCursor(5, 0);
lcd.write(byte(6));
lcd.setCursor(5, 1);
lcd.write(byte(7));

}


void image03() { //Quarto Frame
lcd.clear();

byte image04[8] = {B00111, B00100, B00010, B00001, B00001, B00001, B01111, B11111};
byte image20[8] = {B11111, B01111, B00001, B00001, B00001, B00010, B00100, B00111};
byte image05[8] = {B00000, B10000, B01000, B00100, B10010, B10001, B10011, B11111};
byte image21[8] = {B11111, B10011, B10001, B10010, B00100, B01000, B10000, B00000};
byte image22[8] = {B11011, B11010, B01101, B00000, B00000, B00000, B00000, B00000};
byte image06[8] = {B00000, B00000, B00000, B00000, B00000, B01101, B11010, B11011};
byte image23[8] = {B00000, B00000, B00000, B00000, B10000, B00000, B00000, B00000};
byte image07[8] = {B00000, B00000, B00000, B10000, B00000, B00000, B00000, B00000};
lcd.createChar(0, image04);
lcd.createChar(1, image20);
lcd.createChar(2, image05);
lcd.createChar(3, image21);
lcd.createChar(4, image22);
lcd.createChar(5, image06);
lcd.createChar(6, image23);
lcd.createChar(7, image07);
lcd.setCursor(3, 0);
lcd.write(byte(0));
lcd.setCursor(3, 1);
lcd.write(byte(1));
lcd.setCursor(4, 0);
lcd.write(byte(2));
lcd.setCursor(4, 1);
lcd.write(byte(3));
lcd.setCursor(5, 1);
lcd.write(byte(4));
lcd.setCursor(5, 0);
lcd.write(byte(5));
lcd.setCursor(6, 1);
lcd.write(byte(6));
lcd.setCursor(6, 0);
lcd.write(byte(7));

}

void image04() { //Quinto Frame
lcd.clear();

byte image20[8] = {B01111, B10111, B01001, B00100, B00011, B00000, B00000, B00000};
byte image04[8] = {B00000, B00000, B00000, B00011, B00100, B01001, B10111, B01111};
byte image05[8] = {B00000, B00000, B00000, B11110, B00001, B00001, B11011, B11111};
byte image21[8] = {B11111, B11011, B00001, B00001, B11110, B00000, B00000, B00000};
byte image06[8] = {B00000, B00000, B00000, B00000, B00000, B01101, B11010, B11011};
byte image22[8] = {B11011, B11010, B01101, B00000, B00000, B00000, B00000, B00000};
byte image07[8] = {B00000, B00000, B00000, B10000, B00000, B00000, B00000, B00000};
byte image23[8] = {B00000, B00000, B00000, B10000, B00000, B00000, B00000, B00000};
lcd.createChar(0, image20);
lcd.createChar(1, image04);
lcd.createChar(2, image05);
lcd.createChar(3, image21);
lcd.createChar(4, image06);
lcd.createChar(5, image22);
lcd.createChar(6, image07);
lcd.createChar(7, image23);
lcd.setCursor(3, 1);
lcd.write(byte(0));
lcd.setCursor(3, 0);
lcd.write(byte(1));
lcd.setCursor(4, 0);
lcd.write(byte(2));
lcd.setCursor(4, 1);
lcd.write(byte(3));
lcd.setCursor(5, 0);
lcd.write(byte(4));
lcd.setCursor(5, 1);
lcd.write(byte(5));
lcd.setCursor(6, 0);
lcd.write(byte(6));
lcd.setCursor(6, 1);
lcd.write(byte(7));

}


void image05() { //Sexto Frame
lcd.clear();

byte image20[8] = {B00111, B00011, B00000, B00000, B00000, B00000, B00001, B00001};
byte image04[8] = {B00001, B00001, B00000, B00000, B00000, B00000, B00011, B00111};
byte image05[8] = {B10010, B00001, B10000, B01000, B01010, B01010, B11010, B11011};
byte image21[8] = {B11011, B11010, B01010, B01010, B01000, B10000, B00001, B10010};
byte image06[8] = {B00000, B00000, B00000, B10000, B01000, B00101, B01111, B11111};
byte image22[8] = {B11111, B01111, B00101, B00100, B01000, B10000, B00000, B00000};
byte image07[8] = {B00000, B00000, B00000, B00000, B00010, B10100, B01000, B01100};
byte image23[8] = {B01100, B01000, B10100, B00010, B00000, B00000, B00000, B00000};
lcd.createChar(0, image20);
lcd.createChar(1, image04);
lcd.createChar(2, image05);
lcd.createChar(3, image21);
lcd.createChar(4, image06);
lcd.createChar(5, image22);
lcd.createChar(6, image07);
lcd.createChar(7, image23);
lcd.setCursor(3, 1);
lcd.write(byte(0));
lcd.setCursor(3, 0);
lcd.write(byte(1));
lcd.setCursor(4, 0);
lcd.write(byte(2));
lcd.setCursor(4, 1);
lcd.write(byte(3));
lcd.setCursor(5, 0);
lcd.write(byte(4));
lcd.setCursor(5, 1);
lcd.write(byte(5));
lcd.setCursor(6, 0);
lcd.write(byte(6));
lcd.setCursor(6, 1);
lcd.write(byte(7));

}

void image06() { //Sétimo Frame
lcd.clear();

byte image20[8] = {B00011, B00001, B00000, B00000, B00000, B00000, B00000, B00000};
byte image04[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00011};
byte image05[8] = {B01100, B10010, B10001, B01000, B00100, B00100, B11101, B11101};
byte image21[8] = {B11101, B11101, B00100, B00100, B01000, B10001, B10010, B01100};
byte image06[8] = {B00000, B00000, B00000, B10000, B01000, B00010, B00111, B11111};
byte image22[8] = {B11111, B00111, B00010, B01000, B10000, B00000, B00000, B00000};
byte image23[8] = {B10110, B10100, B11010, B00001, B00000, B00000, B00000, B00000};
byte image07[8] = {B00000, B00000, B00000, B00000, B00001, B11010, B10100, B10110};


lcd.createChar(0, image20);
lcd.createChar(1, image04);
lcd.createChar(2, image05);
lcd.createChar(3, image21);
lcd.createChar(4, image06);
lcd.createChar(5, image22);
lcd.createChar(6, image23);
lcd.createChar(7, image07);


lcd.setCursor(3, 1);
lcd.write(byte(0));
lcd.setCursor(3, 0);
lcd.write(byte(1));
lcd.setCursor(4, 0);
lcd.write(byte(2));
lcd.setCursor(4, 1);
lcd.write(byte(3));
lcd.setCursor(5, 0);
lcd.write(byte(4));
lcd.setCursor(5, 1);
lcd.write(byte(5));
lcd.setCursor(6, 1);
lcd.write(byte(6));
lcd.setCursor(6, 0);
lcd.write(byte(7));

}

void image07() { //Oitavo Frame
lcd.clear();

byte image20[8] = {B00001, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte image04[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00001};
byte image05[8] = {B00000, B00000, B00000, B00111, B01000, B00010, B11110, B11110};
byte image21[8] = {B11110, B11110, B00010, B01000, B00110, B00000, B00000, B00000};
byte image22[8] = {B11111, B10011, B00001, B00010, B11100, B00000, B00000, B00000};
byte image06[8] = {B00000, B00000, B00000, B11100, B00010, B00001, B10011, B11111};
byte image07[8] = {B00000, B00000, B00000, B00000, B00001, B01100, B11010, B11011};
byte image23[8] = {B11011, B11010, B01100, B00001, B00000, B00000, B00000, B00000};


lcd.createChar(0, image20);
lcd.createChar(1, image04);
lcd.createChar(2, image05);
lcd.createChar(3, image21);
lcd.createChar(4, image22);
lcd.createChar(5, image06);
lcd.createChar(6, image07);
lcd.createChar(7, image23);


lcd.setCursor(3, 1);
lcd.write(byte(0));
lcd.setCursor(3, 0);
lcd.write(byte(1));
lcd.setCursor(4, 0);
lcd.write(byte(2));
lcd.setCursor(4, 1);
lcd.write(byte(3));
lcd.setCursor(5, 1);
lcd.write(byte(4));
lcd.setCursor(5, 0);
lcd.write(byte(5));
lcd.setCursor(6, 0);
lcd.write(byte(6));
lcd.setCursor(6, 1);
lcd.write(byte(7));

}




void image08() { //Nono frame
lcd.clear();

byte image21[8] = {B11111, B01111, B00001, B00001, B00001, B00010, B00100, B00111};
byte image05[8] = {B00111, B00100, B00010, B00001, B00001, B00001, B01111, B11111};
byte image22[8] = {B11111, B10011, B10001, B00010, B00100, B01000, B10000, B00000};
byte image06[8] = {B00000, B10000, B01000, B00100, B00010, B10001, B10011, B11111};
byte image07[8] = {B00000, B00000, B00000, B00000, B00000, B01101, B11010, B11011};
byte image23[8] = {B11011, B11010, B01101, B00000, B00000, B00000, B00000, B00000};


lcd.createChar(0, image21);
lcd.createChar(1, image05);
lcd.createChar(2, image22);
lcd.createChar(3, image06);
lcd.createChar(4, image07);
lcd.createChar(5, image23);


lcd.setCursor(4, 1);
lcd.write(byte(0));
lcd.setCursor(4, 0);
lcd.write(byte(1));
lcd.setCursor(5, 1);
lcd.write(byte(2));
lcd.setCursor(5, 0);
lcd.write(byte(3));
lcd.setCursor(6, 0);
lcd.write(byte(4));
lcd.setCursor(6, 1);
lcd.write(byte(5));

}


void image09() {
//lcd.clear();

byte image21[8] = {B01111, B00111, B00000, B00000, B00010, B00001, B00000, B00000};
byte image05[8] = {B00000, B00000, B00001, B00010, B00000, B00000, B00111, B01111};
byte image22[8] = {B10111, B10101, B10101, B10001, B00010, B11100, B00000, B00000};
byte image06[8] = {B00000, B00000, B11100, B00010, B10001, B10101, B10101, B10111};
byte image07[8] = {B00000, B00000, B00000, B00000, B00001, B01100, B11010, B11011};
byte image23[8] = {B11011, B11010, B01100, B00001, B00000, B00000, B00000, B00000};


lcd.createChar(0, image21);
lcd.createChar(1, image05);
lcd.createChar(2, image22);
lcd.createChar(3, image06);
lcd.createChar(4, image07);
lcd.createChar(5, image23);


lcd.setCursor(4, 1);
lcd.write(byte(0));
lcd.setCursor(4, 0);
lcd.write(byte(1));
lcd.setCursor(5, 1);
lcd.write(byte(2));
lcd.setCursor(5, 0);
lcd.write(byte(3));
lcd.setCursor(6, 0);
lcd.write(byte(4));
lcd.setCursor(6, 1);
lcd.write(byte(5));

}



void image10() {
lcd.clear();

byte image21[8] = {B00011, B00001, B00000, B00000, B00000, B00000, B00000, B00000};
byte image05[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00011};
byte image06[8] = {B11110, B10001, B01000, B00100, B00100, B00101, B11101, B11101};
byte image22[8] = {B11101, B11101, B00101, B00100, B00100, B01000, B10001, B11110};
byte image07[8] = {B00000, B00000, B10000, B01000, B00100, B00010, B00111, B11111};
byte image23[8] = {B11111, B00111, B00010, B00100, B01000, B10000, B00000, B00000};
byte image08[8] = {B00000, B00000, B00000, B00000, B00001, B01010, B10100, B10110};
byte image24[8] = {B10110, B10100, B01010, B00001, B00000, B00000, B00000, B00000};


lcd.createChar(0, image21);
lcd.createChar(1, image05);
lcd.createChar(2, image06);
lcd.createChar(3, image22);
lcd.createChar(4, image07);
lcd.createChar(5, image23);
lcd.createChar(6, image08);
lcd.createChar(7, image24);


lcd.setCursor(4, 1);
lcd.write(byte(0));
lcd.setCursor(4, 0);
lcd.write(byte(1));
lcd.setCursor(5, 0);
lcd.write(byte(2));
lcd.setCursor(5, 1);
lcd.write(byte(3));
lcd.setCursor(6, 0);
lcd.write(byte(4));
lcd.setCursor(6, 1);
lcd.write(byte(5));
lcd.setCursor(7, 0);
lcd.write(byte(6));
lcd.setCursor(7, 1);
lcd.write(byte(7));

}




void image11() {
lcd.clear();

byte image21[8] = {B00001, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte image05[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00001};
byte image06[8] = {B00000, B00000, B00000, B00111, B01000, B00010, B11110, B11110};
byte image22[8] = {B11110, B11110, B00010, B01000, B00111, B00000, B00000, B00000};
byte image07[8] = {B00000, B00000, B00000, B11100, B00010, B00001, B10011, B11111};
byte image23[8] = {B11111, B10011, B00001, B00010, B11100, B00000, B00000, B00000};
byte image08[8] = {B00000, B00000, B00000, B00000, B00001, B01100, B11010, B11011};
byte image24[8] = {B11011, B11010, B01100, B00001, B00000, B00000, B00000, B00000};


lcd.createChar(0, image21);
lcd.createChar(1, image05);
lcd.createChar(2, image06);
lcd.createChar(3, image22);
lcd.createChar(4, image07);
lcd.createChar(5, image23);
lcd.createChar(6, image08);
lcd.createChar(7, image24);


lcd.setCursor(4, 1);
lcd.write(byte(0));
lcd.setCursor(4, 0);
lcd.write(byte(1));
lcd.setCursor(5, 0);
lcd.write(byte(2));
lcd.setCursor(5, 1);
lcd.write(byte(3));
lcd.setCursor(6, 0);
lcd.write(byte(4));
lcd.setCursor(6, 1);
lcd.write(byte(5));
lcd.setCursor(7, 0);
lcd.write(byte(6));
lcd.setCursor(7, 1);
lcd.write(byte(7));

}


void image12() {
lcd.clear();

byte image06[8] = {B00111, B00100, B00010, B00001, B00001, B00001, B01111, B11111};
byte image22[8] = {B11111, B01111, B00001, B00001, B00001, B00010, B00100, B00111};
byte image07[8] = {B00000, B10000, B01000, B00100, B10010, B10001, B10011, B11111};
byte image23[8] = {B11111, B10011, B10001, B10010, B00100, B01000, B10000, B00000};
byte image08[8] = {B00000, B00000, B00000, B00000, B00000, B01101, B11010, B11010};
byte image24[8] = {B11010, B11010, B01101, B00000, B00000, B00000, B00000, B00000};


lcd.createChar(0, image06);
lcd.createChar(1, image22);
lcd.createChar(2, image07);
lcd.createChar(3, image23);
lcd.createChar(4, image08);
lcd.createChar(5, image24);


lcd.setCursor(5, 0);
lcd.write(byte(0));
lcd.setCursor(5, 1);
lcd.write(byte(1));
lcd.setCursor(6, 0);
lcd.write(byte(2));
lcd.setCursor(6, 1);
lcd.write(byte(3));
lcd.setCursor(7, 0);
lcd.write(byte(4));
lcd.setCursor(7, 1);
lcd.write(byte(5));

}




void image13() { //Décimo quarto frame
lcd.clear();

byte image06[8] = {B00000, B00000, B00000, B00001, B00010, B00000, B00111, B01111};
byte image22[8] = {B01111, B00111, B00000, B00010, B00001, B00000, B00000, B00000};
byte image23[8] = {B10111, B10100, B10001, B00010, B11100, B00000, B00000, B00000};
byte image07[8] = {B00000, B00000, B00000, B11100, B00010, B10001, B10100, B10111};
byte image08[8] = {B00000, B00000, B00000, B00000, B00001, B01100, B11010, B11011};
byte image24[8] = {B11011, B11010, B01100, B00001, B00000, B00000, B00000, B00000};


lcd.createChar(0, image06);
lcd.createChar(1, image22);
lcd.createChar(2, image23);
lcd.createChar(3, image07);
lcd.createChar(4, image08);
lcd.createChar(5, image24);


lcd.setCursor(5, 0);
lcd.write(byte(0));
lcd.setCursor(5, 1);
lcd.write(byte(1));
lcd.setCursor(6, 1);
lcd.write(byte(2));
lcd.setCursor(6, 0);
lcd.write(byte(3));
lcd.setCursor(7, 0);
lcd.write(byte(4));
lcd.setCursor(7, 1);
lcd.write(byte(5));

}


void image14() { //Décimo quinto frame
lcd.clear();

byte image22[8] = {B00111, B00011, B00001, B00001, B00001, B00010, B00100, B00111};
byte image06[8] = {B00111, B00100, B00010, B00001, B00001, B00001, B00011, B00111};
byte image07[8] = {B10000, B01000, B00100, B00010, B01001, B01000, B11010, B11011};
byte image23[8] = {B11011, B11010, B01000, B01001, B00010, B00100, B01000, B10000};
byte image08[8] = {B00000, B00000, B00000, B00000, B00000, B10110, B01101, B11101};
byte image24[8] = {B11101, B01101, B10110, B00000, B00000, B00000, B00000, B00000};
byte image09[8] = {B00000, B00000, B00000, B00000, B00000, B01000, B00000, B10000};
byte image25[8] = {B10000, B00000, B01000, B00000, B00000, B00000, B00000, B00000};


lcd.createChar(0, image22);
lcd.createChar(1, image06);
lcd.createChar(2, image07);
lcd.createChar(3, image23);
lcd.createChar(4, image08);
lcd.createChar(5, image24);
lcd.createChar(6, image09);
lcd.createChar(7, image25);


lcd.setCursor(5, 1);
lcd.write(byte(0));
lcd.setCursor(5, 0);
lcd.write(byte(1));
lcd.setCursor(6, 0);
lcd.write(byte(2));
lcd.setCursor(6, 1);
lcd.write(byte(3));
lcd.setCursor(7, 0);
lcd.write(byte(4));
lcd.setCursor(7, 1);
lcd.write(byte(5));
lcd.setCursor(8, 0);
lcd.write(byte(6));
lcd.setCursor(8, 1);
lcd.write(byte(7));

}



void image15() { //Décimo sexto frame
lcd.clear();

byte image22[8] = {B00001, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte image06[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00001};
byte image07[8] = {B00000, B00000, B00000, B00111, B01000, B00010, B11110, B11110};
byte image23[8] = {B11110, B11110, B00010, B01000, B00111, B00000, B00000, B00000};
byte image08[8] = {B00000, B00000, B00000, B11100, B00010, B00001, B10011, B11111};
byte image24[8] = {B11111, B10011, B00001, B00010, B11100, B00000, B00000, B00000};
byte image25[8] = {B11011, B11010, B01100, B00001, B00000, B00000, B00000, B00000};
byte image09[8] = {B00000, B00000, B00000, B00000, B00001, B01100, B11010, B11011};


lcd.createChar(0, image22);
lcd.createChar(1, image06);
lcd.createChar(2, image07);
lcd.createChar(3, image23);
lcd.createChar(4, image08);
lcd.createChar(5, image24);
lcd.createChar(6, image25);
lcd.createChar(7, image09);


lcd.setCursor(5, 1);
lcd.write(byte(0));
lcd.setCursor(5, 0);
lcd.write(byte(1));
lcd.setCursor(6, 0);
lcd.write(byte(2));
lcd.setCursor(6, 1);
lcd.write(byte(3));
lcd.setCursor(7, 0);
lcd.write(byte(4));
lcd.setCursor(7, 1);
lcd.write(byte(5));
lcd.setCursor(8, 1);
lcd.write(byte(6));
lcd.setCursor(8, 0);
lcd.write(byte(7));

}




void image16() { //Décimo sètimo frame
lcd.clear();

byte image23[8] = {B11111, B01111, B00001, B00001, B00001, B00010, B00100, B00111};
byte image07[8] = {B00111, B00100, B00010, B00001, B00001, B00001, B01111, B11111};
byte image24[8] = {B11111, B10011, B10001, B00010, B00100, B01000, B10000, B00000};
byte image08[8] = {B00000, B10000, B01000, B00100, B00010, B10001, B10011, B11111};
byte image09[8] = {B00000, B00000, B00000, B00000, B00001, B01100, B11010, B11011};
byte image25[8] = {B11011, B11010, B01100, B00001, B00000, B00000, B00000, B00000};


lcd.createChar(0, image23);
lcd.createChar(1, image07);
lcd.createChar(2, image24);
lcd.createChar(3, image08);
lcd.createChar(4, image09);
lcd.createChar(5, image25);


lcd.setCursor(6, 1);
lcd.write(byte(0));
lcd.setCursor(6, 0);
lcd.write(byte(1));
lcd.setCursor(7, 1);
lcd.write(byte(2));
lcd.setCursor(7, 0);
lcd.write(byte(3));
lcd.setCursor(8, 0);
lcd.write(byte(4));
lcd.setCursor(8, 1);
lcd.write(byte(5));

}


void image17() { //Décimo oitavo frame
lcd.clear();

byte image23[8] = {B01111, B00111, B00000, B00000, B00000, B00001, B00010, B00011};
byte image07[8] = {B00011, B00010, B00001, B00000, B00000, B00000, B00111, B01111};
byte image08[8] = {B10000, B01000, B00100, B10010, B10001, B10010, B10000, B10000};
byte image24[8] = {B10000, B10010, B10000, B10001, B10010, B00100, B01000, B10000};
byte image25[8] = {B00000, B00001, B00001, B00100, B00010, B00000, B00000, B00000};
byte image09[8] = {B00000, B00000, B00000, B00100, B00000, B00100, B01001, B00000};


lcd.createChar(0, image23);
lcd.createChar(1, image07);
lcd.createChar(2, image08);
lcd.createChar(3, image24);
lcd.createChar(4, image25);
lcd.createChar(5, image09);


lcd.setCursor(6, 1);
lcd.write(byte(0));
lcd.setCursor(6, 0);
lcd.write(byte(1));
lcd.setCursor(7, 0);
lcd.write(byte(2));
lcd.setCursor(7, 1);
lcd.write(byte(3));
lcd.setCursor(8, 1);
lcd.write(byte(4));
lcd.setCursor(8, 0);
lcd.write(byte(5));

}


void image18() {//Décimo nono frame
lcd.clear();

byte image07[8] = {B00001, B00001, B00000, B00000, B00000, B00000, B00011, B00111};
byte image23[8] = {B00111, B00011, B00000, B00000, B00000, B00000, B00001, B00001};
byte image08[8] = {B11000, B00110, B10000, B01000, B01000, B01000, B11010, B11010};
byte image24[8] = {B11000, B11001, B01000, B01000, B01000, B10000, B00100, B11010};
byte image09[8] = {B00000, B00000, B00000, B01000, B00000, B00000, B00000, B00000};


lcd.createChar(0, image07);
lcd.createChar(1, image23);
lcd.createChar(2, image08);
lcd.createChar(3, image24);
lcd.createChar(4, image09);


lcd.setCursor(6, 0);
lcd.write(byte(0));
lcd.setCursor(6, 1);
lcd.write(byte(1));
lcd.setCursor(7, 0);
lcd.write(byte(2));
lcd.setCursor(7, 1);
lcd.write(byte(3));
lcd.setCursor(8, 0);
lcd.write(byte(4));

}


void image19() {
lcd.clear();

byte image07[8] = {B00000, B00000, B00000, B00100, B00000, B00000, B00001, B00011};
byte image23[8] = {B00011, B00001, B00000, B00100, B00000, B00000, B00000, B00000};
byte image08[8] = {B00000, B00001, B00000, B00000, B01000, B00000, B10100, B11100};
byte image24[8] = {B01100, B11100, B00000, B01000, B00000, B00000, B00000, B00010};


lcd.createChar(0, image07);
lcd.createChar(1, image23);
lcd.createChar(2, image08);
lcd.createChar(3, image24);


lcd.setCursor(6, 0);
lcd.write(byte(0));
lcd.setCursor(6, 1);
lcd.write(byte(1));
lcd.setCursor(7, 0);
lcd.write(byte(2));
lcd.setCursor(7, 1);
lcd.write(byte(3));
  
lcd.clear();
}



//Moskitto


void image20() {
  // Liga e desliga a mensagem na segunda linha
  lcd.setCursor(0, 0);
  lcd.print("M O S K I T T O");
  delay(500);
  lcd.clear();
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("M O S K I T T O");
  delay(500);
  lcd.clear();
  delay(500); // Espera 500 milissegundos
  lcd.print("M O S K I T T O");
  delay(1500); // Espera de 1,5 segundos para iniciar o programa
    
}