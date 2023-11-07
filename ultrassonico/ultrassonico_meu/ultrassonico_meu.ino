/*
Autor: Lucas Tavares
Data de início: 07/11/2023
Data de término: xx/xx/xxxx
* Programa com funções que utiliza o sensor ultrassônico para determinar
* a posição em até duas dimensões em um espaço de área retangular.
* Raio de medição: 2 cm ~ 400 cm
* Precisão: 3 mm
*/

//Início do código:

//Definir os pinos que vão ser usados do Esp32:
const int trigPin = 12;
const int echoPin = 14;

//Definindo a velocidade do som em cm/uS (funções)

#define Velocidade_Som 0.034

long duracao;
float distanceCm;

//Chamada de funções - rodar 

void setup() {
  Serial.begin(115200); //Começa a comunicação serial
  pinMode(trigPin, OUTPUT); //Seta trigPin como saída
  pinMode(echoPin, INPUT); //Seta echoPin como entrada
}

void loop() {
  //Limpar a saída
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Setar a saída para alto por 10 micro segundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Ler a entrada e retonar o tempo de duração da onda em micro segundos
  duracao = pulseIn(echoPin, HIGH);

  //Calcular a distância
  distanceCm = duracao*Velocidade_Som/2;

  //Imprimir a distância do Monitor Serial
  Serial.print("Distância (cm): ");
  Serial.printIn(distanceCm);

  delay(500);
}