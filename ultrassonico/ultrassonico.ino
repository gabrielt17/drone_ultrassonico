/*
Autor: Gabriel Víctor
Data de início: 18/10/2023
Data de término: xx/xx/xxxx
* Programa com funções que utiliza o sensor ultrassônico para determinar
* a posição em até duas dimensões em um espaço de área retangular.
* Raio de medição: 2 cm ~ 400 cm
* Precisão: 3 mm
*/
#include <Arduino.h>
#define trig 21 // Associa o pino 21 ao pino Trigger
#define echo 12 // Associa o pino 12 ao pino Echo


void setup() {
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
  Serial.begin(9600);
}


void loop() {
  Serial.print("Distância: ");
  Serial.print(distanciaCm());
  Serial.println(" cm");
  Serial.print("Distância: ");
  Serial.print(distanciaMetro());
  Serial.println(" m");             
  delay(600);
}

float distanciaCm(void) {
  digitalWrite(trig, LOW);
  delay(60); // Recomendação de 60 ms entre ciclos
  digitalWrite(trig, HIGH);
  // Intervalo de empo mínimo para que a onda seja enviada
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);

  // Mensura os intervalos de tempo entre o último momento que o
  float tempoalto = pulseIn(echo, HIGH);
  float velsom = 0.0003403; // Velocidade do som em microssegundos
  float distancia = tempoalto*velsom*50; // Tempo em nível alto * velocidade do ar/2
  if (distancia >= 400){
    return -1;
  }
  else
    return distancia;
}

float distanciaMetro(void) {
  digitalWrite(trig, LOW);
  delay(60); // Recomendação de 60 ms entre ciclos
  digitalWrite(trig, HIGH);
  // Intervalo de empo mínimo para que a onda seja enviada
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);

  // Mensura os intervalos de tempo entre o último momento que o
  float tempoalto = pulseIn(echo, HIGH);
  float velsom = 0.0003403; // Velocidade do som em microssegundos
  float distancia = tempoalto*velsom*50; // Tempo em nível alto * velocidade do ar/2
  if (distancia >= 400){
    return -1;
  }
  else
    return (distancia/100);
}