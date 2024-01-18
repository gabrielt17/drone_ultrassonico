/*
Autores: Cleide Almeida e Gabriel Víctor
Data: 21/11/2023
Última alteração: 17/01/2024
Exibe valores de leitura de um sensor ultrassonico
num display LCD 16x2 (Endereço I2C: 0x27)
*/

#include <LiquidCrystal_I2C.h>
// Pinos ultrassônico
const byte trig = 19; // Associa o pino 19 ao Trigger
const byte echo = 23; // Associa o pino 23 ao Echo
// Endereço I2C e parâmetros do Display 16x2 (módulo I2C)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init(); // Inicia o display
  lcd.backlight(); // Liga o display
  pinMode(trig, OUTPUT); // Declara Trigger como saída dig.
	pinMode(echo, INPUT); // Declara Echo como ent. dig.
}

void loop() {
  // Imprime os dados do sensor no display
  float distance = distanciaCm();
  lcd.print("Distancia: ");
  lcd.setCursor(0, 1);
  lcd.print("     ");
  lcd.print(distance);
  lcd.print(" cm");
  delay(1000);
  lcd.clear();
}

float distanciaCm(void) {
  digitalWrite(trig, LOW);
  delay(80); // Recomendação de ao menos 60 ms entre ciclos
  digitalWrite(trig, HIGH);
  // Intervalo de tempo mínimo para que a onda seja enviada
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  // Mensura quanto tempo o pino ECHO ficou em nível alto em microssegundos
  float tempoalto = pulseIn(echo, HIGH);
  // Velocidade do som em micrometros/microssegundos
  float velsom = 0.0003403;
  // Tempo em nível alto * velocidade do ar/2
  float distancia = (tempoalto*velsom*100)/2; 
  if (distancia >= 400){
    return -1; // Caso valor seja maior que 400 cm, retorna -1 (Inválido)
  }
  else
    return distancia;
}
