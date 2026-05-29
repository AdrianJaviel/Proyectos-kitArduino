#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX (10) -> TX del HC-05 | TX (11) -> RX del HC-05

void setup() {
  Serial.begin(9600);   // Comunicación con la PC
  BT.begin(9600);       // <- CAMBIADO DE 38400 A 9600
  Serial.println("--- Sistema Listo ---");
}

void loop() {
  if (BT.available()) {
    Serial.write(BT.read());
  }
  
  if (Serial.available()) {
    BT.write(Serial.read());
  }
}