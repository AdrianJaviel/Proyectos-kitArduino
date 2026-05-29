void setup() {

  Serial.begin(9600);

}

void loop() {

  int sonido = analogRead(A0);

  Serial.print("Valor: ");
  Serial.println(sonido);

  if (sonido > 100) {

    Serial.println("¡¡SONIDO DETECTADO!!");

  }

  delay(50);
}