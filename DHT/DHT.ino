#include <DHT.h>

// Pin donde está conectado el DHT11
#define DHTPIN 2

// Tipo de sensor
#define DHTTYPE DHT11

// Crear objeto DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  // Iniciar sensor
  dht.begin();

  Serial.println("Sensor DHT11 iniciado");
}

void loop() {

  // Leer humedad
  float humedad = dht.readHumidity();

  // Leer temperatura
  float temperatura = dht.readTemperature();

  // Verificar errores
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error leyendo el sensor");
    return;
  }

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  Serial.println("----------------");

  delay(2000);
}