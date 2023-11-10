//Autor: Lucas Tavares Machado
//Início do projeto: 10/11/2023 

#include <Wire.h> //Incluindo a biblioteca wire

float RateRoll, RatePitch, RateYaw;//Declarando variáveis 

void gyro_signals(void) { //Iniciando função
//Configurando giroscópio
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission(); 
  Wire.beginTransmission(0x68);
  Wire.write(0x1B); 
  Wire.write(0x8); 
  Wire.endTransmission(); 
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();

  //Leitura de dados do giroscópio
  Wire.requestFrom(0x68,6);
  int16_t GyroX=Wire.read()<<8 | Wire.read();
  int16_t GyroY=Wire.read()<<8 | Wire.read();
  int16_t GyroZ=Wire.read()<<8 | Wire.read();

  //Conversão de dados para taxas em graus por segundo
  RateRoll=(float)GyroX/65.5;
  RatePitch=(float)GyroY/65.5;
  RateYaw=(float)GyroZ/65.5;
}

void setup() { //Início de função setup
  Serial.begin(57600); //Inicia comunicação serial a uma velocidade de 57600 bauds
  pinMode(13, OUTPUT); //Configura pino 13 como saída e o define como alto
  digitalWrite(13, HIGH);
  Wire.setClock(400000); //Velocidade de comunicação de 400KHz
  Wire.begin();
  delay(250);
  Wire.beginTransmission(0x68); 
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
}


void loop() { //Início da função loop -> Imprimir valores
  gyro_signals();
  Serial.print("Roll rate [°/s]= ");
  Serial.print(RateRoll);
  Serial.print(" Pitch Rate [°/s]= ");
  Serial.print(RatePitch);
  Serial.print(" Yaw Rate [°/s]= ");
  Serial.println(RateYaw);
  delay(50);
}