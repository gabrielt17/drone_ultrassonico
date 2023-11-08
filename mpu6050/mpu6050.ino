/*
Autores(as): Cleide Almeida, Gabriel Víctor, Lucas Tavares
Data de início: 08/11/2023
Data de término: xx/xx/xxxx
Descrição: Código que utiliza do sensor MPU6065 para mensurar o ângulo
de rotação a partir de uma determinada origem.
Documentação biblioteca: https://adafruit.github.io/Adafruit_MPU6050/html/class_adafruit___m_p_u6050.html
*/

#include <Adafruit_MPU6050.h>

// Apelido para classe da biblioteca do MPU6050
Adafruit_MPU6050 mpu;

void setup (void) {
  Serial.begin(9600);
  // Enquanto monitor serial não for aberto, pausar
  while(!Serial)
    delay(10);
  // Tenta encontrar e iniciar o sensor
  if (!mpu.begin()) {
    Serial.println("Não foi possível iniciar o sensor");
    delay(2000);
  }
  Serial.println("MPU encontrado");
  // Algumas configurações do sensor
  mpu.setAccelerometerRange(MPU6050_RANGE_4_G)
}


void loop () {

}