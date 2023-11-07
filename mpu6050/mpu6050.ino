#include <Wire.h>

float eY, eX, eZ; // Taxas de variação nos Eixos X, Y e Z (Z vertical)

void sinalGiroscopio(void) {    // Inicia comunicação com sensor no seu
  
  // Escreve a configuração de filtro passa baixo para 10 Hz
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission();

  //Embassado demais isso


}
