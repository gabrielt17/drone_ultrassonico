/*
Autor: Gabriel Víctor
Data de início: 18/10/2023
Data de término: xx/xx/xxxx
* Programa com funções que utiliza o sensor ultrassônico para determinar
* a posição em até duas dimensões em um espaço de área retangular.
* Raio de medição: 2 cm ~ 400 cm
* Precisão: 3 mm
*/

#define trig  1//Dá apelido ao pino Trigger
#define echo 2//Dá apelido ao pino Echo


  Serial.begin(9600);
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);

}

float distancia(void) {
	digitalWrite(trig, LOW);
	delay(60); // Recomendação de 60 ms entre ciclos
	digitalWrite(trig, HIGH);
	delayMicroseconds(10); // Tempo para que a onda seja enviada
	digitalWrite(trig, LOW);
	float tempoalto = pulseIn(echo, HIGH); // Mensura o tempo em que o pino echo
                                        // está em nível alto
	float distancia = tempoalto*340/2; //Tempo em nível alto * velocidade do ar
	return distancia;
}


void loop() {
  Serial.print(distancia());
  

}
