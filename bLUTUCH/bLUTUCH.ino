#include <SoftwareSerial.h>

// Pin 10 es RX (recibe del HC-05)
// Pin 11 es TX (envía al HC-05)
SoftwareSerial BT(10, 11); 

void setup() {
  Serial.begin(9600);   // Velocidad monitor serie PC
  BT.begin(9600);      // Velocidad modo AT del HC-05
  Serial.println("Listo. Escribe el comando AT abajo:");
}

void loop() {
  // Lo que llegue del Bluetooth, pásalo al monitor serie
  if (BT.available()) Serial.write(BT.read());
  
  // Lo que escribas en el monitor serie, pásalo al Bluetooth
  if (Serial.available()) BT.write(Serial.read());
}