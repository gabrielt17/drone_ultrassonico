/*
Autores(as): Cleide Almeida, Gabriel Víctor, Lucas Tavares
Data de início: 08/11/2023
Última atualização: xx/xx/xxxx
Código que utiliza do sensor MPU6065 para mensurar o ângulo
de rotação a partir de uma determinada origem.
Documentação da biblioteca: https://adafruit.github.io/Adafruit_MPU6050/html/class_adafruit___m_p_u6050.html
Datasheet MPU6050: https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf 
Mapa de registadores: https://cdn.sparkfun.com/datasheets/Sensors/Accelerometers/RM-MPU-6000A.pdf
Código exemplo configurando registadores manualmente: https://www.makerhero.com/blog/tutorial-acelerometro-mpu6050-arduino/
*/

#include <Adafruit_MPU6050.h>
#include <math.h>

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
  Serial.println("");
  // Algumas configurações do sensor
  mpu.setAccelerometerRange(MPU6050_RANGE_4_G); // Mede acelerações de até 4G
  mpu.setGyroRange(MPU6050_RANGE_500_DEG); // Mede giros de até 500º/s
  mpu.setFilterBandwidth(MPU6050_BAND_10_HZ); // Filtro passa baixo de 10Hz
  Serial.println("Configuração inicial feita! Iniciando\
  código principal");
}


void loop () {
  // Cria ponteiros que receberão os
  // valores da aceleração e do giroscópio
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  // Imprime os dados
  Serial.print("Aceleração (x, y,z)[m/s^2]: ");
  Serial.print(accel.acceleration.x);
  Serial.print(", ");
  Serial.print(accel.acceleration.y);
  Serial.print(", ");
  Serial.println(accel.acceleration.z);

  // Serial.print("Rotação (x, y, z)[º/s]: ");
  // Serial.print((gyro.gyro.x*360)/(2*M_PI));
  // Serial.print(", ");
  // Serial.print((gyro.gyro.y*360)/(2*M_PI));
  // Serial.print(", ");
  // Serial.println((gyro.gyro.z*360)/(2*M_PI));
  
  Serial.println("");
  delay(100);
}